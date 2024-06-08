#pragma once
#include <iostream>
#include <string>

class Footwear { // ��� ����������� ����� ��� �����
protected:
    std::string name;
    int size;
    double price;

public:
    virtual void print(std::ostream&) const; // ����������� ������
    virtual void scan(std::istream&);

    virtual std::string getClassName() const = 0; // ������ ������������ ������
    virtual Footwear* getCopy() const = 0;

    int getSize() const { return size; }
    double getPrice() const { return price; }

    virtual ~Footwear() {}
};
 
std::ostream& operator<<(std::ostream&, const Footwear&); // ���������� �����/������
std::istream& operator>>(std::istream&, Footwear&);