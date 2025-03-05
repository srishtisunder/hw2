#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product {
  public:
  //constructor
    Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author);
    virtual ~Book();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

  protected:
    std::string isbn_;
    std::string author_;
};

#endif