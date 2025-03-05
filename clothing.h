#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product {
  public:
  //constructor
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    virtual ~Clothing();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

  protected:
    std::string size_;
    std::string brand_;
};

#endif