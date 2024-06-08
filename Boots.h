#pragma once
#include "Footwear.h"

class Boots : public Footwear {
protected:
    std::string material; // ���� ������������� ������ ������ ��� ������� (��������)

public:
    void print(std::ostream&) const override; // �������������� ����� � ����
    void scan(std::istream&) override;

    std::string getClassName() const override; // �������������� ������ ����������� ������
    Footwear* getCopy() const override;
};