#include "mydatastore.h"
#include <string>
#include <set>
#include <vector>
#include <map>

// **Constructor**
MyDataStore::MyDataStore() {}

// **Destructor**
MyDataStore::~MyDataStore() {
  for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
    delete *it;
  }
  for (std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
    delete it->second;
  }
}

void MyDataStore::addProduct(Product* p) {
  products_.insert(p);  // Store product

  std::set<std::string> keywords = p->keywords();  // Get product keywords
  for (std::set<std::string>::iterator it = keywords.begin(); it != keywords.end(); ++it) {
      keywordMap_[*it].insert(p);  // Map keyword → product
  }
}

void MyDataStore::addUser(User* u) {
  users_[u->getName()] = u;  // Store user by username
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::set<Product*> result;

    for (std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it) {  
        if (keywordMap_.find(*it) != keywordMap_.end()) {  
            if (result.empty()) {  
                result = keywordMap_[*it];
            } else {  
                if (type == 0) {  // AND search  
                    result = setIntersection(result, keywordMap_[*it]);  
                } else {  // OR search  
                    result = setUnion(result, keywordMap_[*it]);  
                }
            }
        }
    }
    return std::vector<Product*>(result.begin(), result.end());
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>\n";
    for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
        (*it)->dump(ofile);
    }
    ofile << "</products>\n";

    ofile << "<users>\n";
    for (std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        it->second->dump(ofile);
    }
    ofile << "</users>\n";
}

std::map<std::string, User*>& MyDataStore::getUsers() {
    return users_;
}

void MyDataStore::addToCart(const std::string& username, Product* product) {
    if (users_.find(username) == users_.end()) {
        std::cout << "Invalid request" << std::endl;  // Match expected output
        return;
    }
    
    userCarts_[username].push_back(product);
}

void MyDataStore::viewCart(const std::string& username) {
    if (users_.find(username) == users_.end()) {
        std::cout << "Invalid username" << std::endl;  // Match expected output
        return;
    }

    std::vector<Product*>& cart = userCarts_[username];
    if (cart.empty()) {
        std::cout << "Cart is empty!" << std::endl;  // Match expected output
        return;
    }

    for (size_t i = 0; i < cart.size(); ++i) {
        std::cout << "Item " << (i + 1) << std::endl;  // Expected format
        std::cout << cart[i]->displayString() << std::endl;
    }
}

void MyDataStore::buyCart(const std::string& username) {
    if (users_.find(username) == users_.end()) {
        std::cout << "Invalid username" << std::endl;  // Match expected output
        return;
    }

    User* user = users_[username];
    std::vector<Product*>& cart = userCarts_[username];
    std::vector<Product*> remainingItems;

    for (Product* product : cart) {
        if (product->getQty() > 0 && user->getBalance() >= product->getPrice()) {
            // Deduct stock and user balance
            product->subtractQty(1);
            user->deductAmount(product->getPrice());
        } else {
            // Keep the item in the cart if not purchased
            remainingItems.push_back(product);
        }
    }

    // Update the user's cart with remaining (unpurchased) items
    cart = remainingItems;
}