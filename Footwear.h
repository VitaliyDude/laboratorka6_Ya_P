#pragma once
#include <iostream>
#include <string>

class Footwear { // наш абстрактный класс для обуви
protected:
    std::string name;
    int size;
    double price;

public:
    virtual void print(std::ostream&) const; // виртуальные методы
    virtual void scan(std::istream&);

    virtual std::string getClassName() const = 0; // чистые виртуальрные методы
    virtual Footwear* getCopy() const = 0;

    int getSize() const { return size; }
    double getPrice() const { return price; }

    virtual ~Footwear() {}
};
 
std::ostream& operator<<(std::ostream&, const Footwear&); // перегрузки ввода/вывода
std::istream& operator>>(std::istream&, Footwear&);