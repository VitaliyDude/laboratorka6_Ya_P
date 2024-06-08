#include "Boots.h"

void Boots::print(std::ostream& out) const { // вывод на экран
    Footwear::print(out); // тут как раз таки вызываем метод родительского класса
    out << " " << material; 
}

void Boots::scan(std::istream& in) { // ввод данных. Принцип аналогичен print
    Footwear::scan(in);
    if (&in == &std::cin)
        std::cout << "Введите материал: ";
    in >> material;
}

std::string Boots::getClassName() const { // Вернули имя класса
    return "Boots";
}

Footwear* Boots::getCopy() const { // вернули копии объекта
    return new Boots(*this);
}