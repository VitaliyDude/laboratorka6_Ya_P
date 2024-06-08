#include "Footwear.h"

void Footwear::print(std::ostream& out) const { // метод вывода на экран
    out << name << " " << size << " " << price;
}

void Footwear::scan(std::istream& in) { // метод ввода. ≈го переделал теперь правильно работает
    if (&in == &std::cin)
        std::cout << "¬ведите название, размер и цену: ";
    in >> name >> size >> price;
}

std::ostream& operator<<(std::ostream& out, const Footwear& obj) { // перегрузки
    obj.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Footwear& obj) {
    obj.scan(in);
    return in;
}