#pragma once
#include "Footwear.h"

// ��� ��� ���������� Boots.h

class Shoes : public Footwear { 
protected:
    std::string color; // ����

public:
    void print(std::ostream&) const override;
    void scan(std::istream&) override;

    std::string getClassName() const override;
    Footwear* getCopy() const override;
};