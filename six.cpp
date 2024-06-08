#include <iostream>
#include <string>
#include <fstream>
#include "Exhibition.h"

using namespace std;

enum Menu {
    scan_from_keyboard,
    scan_from_file,
    print_to_display,
    print_to_file,
    list_by_size,
    list_by_price_range,
    price_stats,
    exit_program
};

int main() {
    system("chcp 1251");
    int ans;
    Exhibition exhibition; 

    do {
        cout << "Выберите пункт меню: " << endl;
        cout << scan_from_keyboard << " - чтение с клавиатуры" << endl
            << scan_from_file << " - чтение из файла" << endl
            << print_to_display << " - вывод на экран" << endl
            << print_to_file << " - вывод в файл" << endl
            << list_by_size << " - вывод списка по размеру" << endl
            << list_by_price_range << " - вывод списка по ценовому диапазону" << endl
            << price_stats << " - статистика" << endl
            << exit_program << " - выход" << endl;
        cin >> ans;

        switch (ans) {
        case scan_from_keyboard: // чтение с клавиатуры
            cin >> exhibition;
            break;
        case scan_from_file: { // чтение из файла
            string path;
            cout << "Введите название файла: ";
            cin >> path;
            ifstream fin(path + ".txt");
            fin >> exhibition;
            fin.close();
            break;
        }
        case print_to_display: // вывод на экран
            cout << exhibition;
            break;
        case print_to_file: { // вывод в файл
            string path;
            cout << "Введите название файла: ";
            cin >> path;
            ofstream fout(path + ".txt");
            fout << exhibition;
            fout.close();
            break;
        }
        case list_by_size: { // вывод списка по размеру
            int size;
            cout << "Введите размер: ";
            cin >> size;
            exhibition.listBySize(size);
            break;
        }
        case list_by_price_range: { //  вывод списка по ценовому диапазону
            double minPrice, maxPrice;
            cout << "Введите минимальную и максимальную цену: ";
            cin >> minPrice >> maxPrice;
            exhibition.listByPriceRange(minPrice, maxPrice);
            break;
        }
        case price_stats: // статистика
            exhibition.priceStats();
            break;
        case exit_program:
            break;
        }
    } while (ans != exit_program);

    return 0;
}