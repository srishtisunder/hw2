#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "util.h"
#include "datastore.h"

class MyDataStore : public DataStore {
public:
  MyDataStore();
  ~MyDataStore();

  void addProduct(Product* p);
  void addUser(User* u);
  std::vector<Product*> search(std::vector<std::string>& terms, int type);
  void dump(std::ostream& ofile);

  std::map<std::string, User*>& getUsers();  
  void addToCart(const std::string& username, Product* product);
  void viewCart(const std::string& username);
  void buyCart(const std::string& username);

private:
  std::set<Product*> products_;
  std::map<std::string, User*> users_;  // Stores users by name
  std::map<std::string, std::set<Product*>> keywordMap_;
  std::map<std::string, std::vector<Product*>> userCarts_; 
};

#endif