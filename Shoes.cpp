#include "Shoes.h"

// ��� ��� ���������� Boots.cpp

void Shoes::print(std::ostream& out) const {
    Footwear::print(out);
    out << " " << color; 
}

void Shoes::scan(std::istream& in) {
    Footwear::scan(in);
    if (&in == &std::cin)
        std::cout << "������� ����: ";
    in >> color;
}

std::string Shoes::getClassName() const {
    return "Shoes";
}

Footwear* Shoes::getCopy() const {
    return new Shoes(*this);
}