#include "Exhibition.h"
#include <iostream>
#include <algorithm>
#include <map>

Exhibition::~Exhibition() { // ��� ����������
    clear();
}

void Exhibition::addFootwear(Footwear* f) { // ��� �� ��������� ����� � ���������� (����� �������)
    footwears.push_back(f->getCopy());
}

void Exhibition::print(std::ostream& out) const { // ����� �� �����
    out << footwears.size() << std::endl;
    for (const auto& f : footwears) {
        out << *f << std::endl;
    }
}

void Exhibition::scan(std::istream& in) { // ���� ������
    size_t s;
    if (&in == &std::cin)
        std::cout << "������� ���������� ��������: ";
    in >> s;

    clear(); // ������ ���� ���������
    for (size_t i = 0; i < s; ++i) {
        std::string type;
        if (&in == &std::cin)
            std::cout << "������� ��� Boots/Shoes(1/2): ";
        in >> type;

        Footwear* f = nullptr;
        if (type == "1") {
            f = new Boots;
        }
        else if (type == "2") {
            f = new Shoes;
        }
        else
        {
            std::cout << "�������� ��� �����\n";
            break;
        }
        in >> *f;
        addFootwear(f); // ��������� � ���������
        delete f;
    }
}

void Exhibition::listBySize(int size) const { // ����� �� �������
    for (const auto& f : footwears) {
        if (f->getSize() == size) {
            std::cout << *f << std::endl;
        }
    }
}

void Exhibition::listByPriceRange(double minPrice, double maxPrice) const { // ����� �� �������� ���������
    for (const auto& f : footwears) {
        if (f->getPrice() >= minPrice && f->getPrice() <= maxPrice) {
            std::cout << *f << std::endl;
        }
    }
}

void Exhibition::priceStats() const { // ����������
    std::map<int, std::pair<double, double>> stats;  // ���������� �����, ����� ������� ���������� �� ����� � ��������

    for (const auto& f : footwears) {
        int size = f->getSize();
        double price = f->getPrice();

        if (stats.find(size) == stats.end()) {
            stats[size] = { price, price };
        }
        else {
            stats[size].first = std::min(stats[size].first, price);
            stats[size].second = std::max(stats[size].second, price);
        }
    }

    for (const auto& entry : stats) {
        int size = entry.first;
        auto priceRange = entry.second;
        std::cout << "������ " << size << ": ���. ���� = " << priceRange.first << ", ����. ���� = " << priceRange.second << std::endl;
    }
}

void Exhibition::clear() { // ������� ������ �� ���������
    for (auto& f : footwears) {
        delete f;
    }
    footwears.clear();
}

std::istream& operator>>(std::istream& in, Exhibition& obj) { // ���������� 
    obj.scan(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Exhibition& obj) {
    obj.print(out);
    return out;
}