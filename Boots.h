#pragma once
#include "Footwear.h"

class Boots : public Footwear {
protected:
    std::string material; // поле принадлежащее только классу для ботинок (материал)

public:
    void print(std::ostream&) const override; // переопределили вывод и ввод
    void scan(std::istream&) override;

    std::string getClassName() const override; // переопределили чистые виртуальные методы
    Footwear* getCopy() const override;
};