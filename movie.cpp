#include "movie.h"
#include <iostream>
#include <sstream>
#include <set>
#include <cctype>

//constructor
Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):Product(category,name,price,qty),genre_(genre),rating_(rating)
{

}

//destructor
Movie::~Movie() 
{

}

std::set<std::string> Movie::keywords() const{
  std::set<std::string> keys;
  std::stringstream ss;
  std::string word;
  ss<<name_;
  while(ss>>word){
    std::string currentWord;
    for(char c:word){
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
  std::string lowercaseGenre;
  for (char c : genre_) {
      lowercaseGenre += static_cast<char>(std::tolower(c));
  }
  keys.insert(lowercaseGenre);
  return keys;
}

std::string Movie::displayString() const{
  std::stringstream ss;
  ss<<name_<<"\n";
  ss<<"Genre: "<<genre_<<" Rating: "<<rating_<<"\n";
  ss<<price_<<" "<<qty_<<" "<<"left."<<std::endl;
  return ss.str();
}

void Movie::dump(std::ostream& os) const {
  os<<category_<<"\n";
  os<<name_<<"\n";
  os<<price_<<"\n";
  os<<qty_<<"\n";
  os<<genre_<<"\n";
  os<<rating_<<std::endl;  
}
