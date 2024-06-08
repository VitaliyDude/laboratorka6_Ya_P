#include "Boots.h"

void Boots::print(std::ostream& out) const { // ����� �� �����
    Footwear::print(out); // ��� ��� ��� ���� �������� ����� ������������� ������
    out << " " << material; 
}

void Boots::scan(std::istream& in) { // ���� ������. ������� ���������� print
    Footwear::scan(in);
    if (&in == &std::cin)
        std::cout << "������� ��������: ";
    in >> material;
}

std::string Boots::getClassName() const { // ������� ��� ������
    return "Boots";
}

Footwear* Boots::getCopy() const { // ������� ����� �������
    return new Boots(*this);
}