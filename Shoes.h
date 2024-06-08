#pragma once
#include "Footwear.h"

// тут все аналогично Boots.h

class Shoes : public Footwear { 
protected:
    std::string color; // цвет

public:
    void print(std::ostream&) const override;
    void scan(std::istream&) override;

    std::string getClassName() const override;
    Footwear* getCopy() const override;
};