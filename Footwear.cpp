#include "Footwear.h"

void Footwear::print(std::ostream& out) const { // ����� ������ �� �����
    out << name << " " << size << " " << price;
}

void Footwear::scan(std::istream& in) { // ����� �����. ��� ��������� ������ ��������� ��������
    if (&in == &std::cin)
        std::cout << "������� ��������, ������ � ����: ";
    in >> name >> size >> price;
}

std::ostream& operator<<(std::ostream& out, const Footwear& obj) { // ����������
    obj.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Footwear& obj) {
    obj.scan(in);
    return in;
}