#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"

class Movie : public Product {
  public:
  //constructor
    Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
    virtual ~Movie();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

  protected:
    std::string genre_;
    std::string rating_;
};

#endif