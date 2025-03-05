#include "clothing.h"
#include <iostream>
#include <sstream>
#include <set>
#include <cctype>

//constructor definition
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):Product(category,name,price,qty),size_(size),brand_(brand)
{

}

//destructor definition
Clothing::~Clothing() 
{
  
}

std::set<std::string> Clothing::keywords() const{
  std::set<std::string> keys;
  std::stringstream ss;
  std::string word;
  ss<<name_<<" "<<brand_;
  while(ss>>word){
    std::string currentWord; 
    for(char c: word){
      if(std::isalpha(c)){
        currentWord += static_cast<char>(std::tolower(c));
      }
      else{
        if(currentWord.length()>=2){
          keys.insert(currentWord);
        }
        currentWord.clear();
      }
    }
    if(currentWord.length()>=2){
      keys.insert(currentWord);
    }
  }
  return keys;
}

std::string Clothing::displayString() const {
  std::stringstream ss;
  ss<<name_<<"\n";
  ss<<"Size: "<<size_<<" Brand: "<<brand_<<"\n";
  ss<<price_<<" "<<qty_<<" "<<"left."<< std::endl;
  return ss.str();
}

void Clothing::dump(std::ostream& os) const{
  os<<category_<<"\n";
  os<<name_<<"\n";
  os<<price_<<"\n";
  os<<qty_<<"\n";
  os<<size_<<"\n";
  os<<brand_<<"\n";
}