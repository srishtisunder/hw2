#include "book.h"
#include <iostream>
#include <sstream>
#include <set>
#include <cctype>

//constructor definition
Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author):Product(category,name,price,qty),isbn_(isbn), author_(author)
{

}
  
//destructor definition
Book::~Book() 
{

}

std::set<std::string> Book::keywords() const {
  std::set<std::string> key;
  std::stringstream ss;
  std::string word;

  ss << name_ << " " << author_;
  while (ss >> word) {
    std::string currentWord;
    for (char c : word) {
      if (std::isalpha(c)) {
        currentWord += static_cast<char>(std::tolower(c));
      } else {
        if (currentWord.length() >= 2) {
            key.insert(currentWord);
          }
          currentWord.clear();
      }
    }
  if (currentWord.length() >= 2) {
    key.insert(currentWord);
  }
}
  key.insert(isbn_);

  return key;
}

std::string Book::displayString() const {
  std::stringstream ss;
  ss<<name_<<"\n";
  ss<<"Author: "<<author_<<" ISBN: "<<isbn_<<"\n";
  ss<<price_<<" "<<qty_<<" "<<"left."<<std::endl;
  return ss.str();
}

void Book::dump(std::ostream& os) const{
  os<<category_<<"\n";
  os<<name_<<"\n";
  os<<price_<<"\n";
  os<<qty_<<"\n";
  os<<isbn_<<"\n";
  os<<author_<<std::endl;
}