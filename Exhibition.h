#pragma once
#include "Footwear.h"
#include "Boots.h"
#include "Shoes.h"
#include <vector>
#include <map>

// ��� ���� ��� ������, �������� �����, �������� ����������, ������ � ����������

class Exhibition {
    std::vector<Footwear*> footwears;

public:
    ~Exhibition();
    void addFootwear(Footwear*);

    void print(std::ostream&) const;
    void scan(std::istream&);

    void listBySize(int) const;
    void listByPriceRange(double, double) const;
    void priceStats() const;

    void clear();
};

std::istream& operator>>(std::istream&, Exhibition&);
std::ostream& operator<<(std::ostream&, const Exhibition&);