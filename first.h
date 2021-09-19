//
// Created by Денис on 19.09.2021.
//

#ifndef UNTITLED_FIRST_H
#define UNTITLED_FIRST_H

#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "color.h"

using namespace std;

class First {

public:
    void start() {
        first_main();
    }

private:
    int a = 0, b = 0, c = 0;
    string d;
    string temp;
    char insert[500];
    int k = 0;
    vector<string> list;
    vector<int> intList;

    bool power_of_two(int &x) {
        int tempX = 1;

        while (tempX < x)
            tempX *= 2;

        return tempX == x;
    }

    void first_main() {
        SetConsoleOutputCP(CP_UTF8);

        begin:
        a = 0;
        b = 0;
        c = 0;
        d = "";
        temp.clear();
        k = 0;
        list.clear();
        intList.clear();

        set_color(3);
        printf("Выберите программу:\n");
        set_color(7);
        printf("1. Количество стрелочек.\n");
        printf("2. Сортировка.\n");
        printf("3. Площадь и объём шара.\n");
        printf("4. Существует ли треугольник?\n");
        printf("5. Калькулятор индекса массы тела.\n");
        printf("6. Является ли число палиндромом?\n");
        printf("7. Является ли компания дочерней у холдинга BBK?\n");
        printf("8. Является ли число точной степенью двойки?\n");
        printf("9. Игра \"Угадай число\".\n");
        printf("10. Перевод числа из 10-ой СС в n-ую.\n");
        printf("0. Возврат в меню выбора лабораторных работ.\n");
        set_color(6);
        printf("> ");
        set_color(7);

        scanf("%i", &c);

        if (c == 0)
            goto end;

        // а по-хорошему бы использовать c = getchar();
        switch (c) {
            case 1:
                printf("Введите строку, в которой необходимо найти стрелочки формата \">>-->\" или \"<--<<\"\n");
                // <<<<>>--><--<<--<<>>>--><<<<<
                memset(&insert[0], 0, sizeof(insert));
                scanf("%s", &insert);
                d = insert;
                intList.clear();
                for (int i = 0; i < d.length() - 4; i++) {
                    temp = d.substr(i, 5);
                    if (temp == ">>-->" || temp == "<--<<") {
                        k++;
                        intList.push_back(i);
                    }
                }
                if (k > 0) {
                    printf("В данной строке содержится стрел: %d. Стрелы находятся на позициях: ", k);
                    for (int i = 0; i < intList.size(); i++) {
                        printf("%d", intList[i]);
                        if (i != intList.size() - 1)
                            printf(", ");
                    }
                    printf("\n\n");
                } else {
                    printf("Стрелок в строке не найдено.\n\n");
                }
                goto begin;

            case 2:
                printf("Введите через пробел данные, которые необходимо сортировать. Чтобы закончить список, напишите \"stop\".\n");
                printf("Разрешено использовать только цифры и латинские символы.\n");

                temp = "";
                list.clear();

                while (temp != "stop") {
                    memset(&insert[0], 0, sizeof(insert));
                    scanf("%s", &insert);
                    temp = insert;

                    if (temp == "stop")
                        break;

                    list.push_back(temp);
                }

                sort(list.begin(), list.end());

                printf("Отсортированные данные:\n");
                for (int i = 0; i < list.size(); i++) {
                    printf("%s", list[i].c_str());
                    if (i != list.size() - 1)
                        printf(", ");
                }
                printf("\n\n");

                goto begin;

            case 3:

                printf("Введите радиус шара (в метрах):\n");
                scanf("%d", &k);
                printf("V (объём) шара = %5.2f (м^3)\nS (площадь) шара = %d (м^2)\n\n", 4 * 1.0 / 3 * k * k * k * M_PI,
                       4 * M_PI * k * k);

                goto begin;

            case 4:
                a = 0;
                b = 0;
                c = 0;

                printf("Введите три стороны треугольника через пробел и нажмите \"Enter\".\n");
                scanf("%d", &a);
                scanf("%d", &b);
                scanf("%d", &c);
                intList.push_back(a);
                intList.push_back(b);
                intList.push_back(c);
                sort(intList.begin(), intList.end());

                if (intList[0] + intList[1] <= intList[2])
                    printf("Такого треугольника не может быть в природе.\n\n");
                else
                    printf("Да, такой треугольник может существовать.\n\n");

                goto begin;

            case 5:
                printf("Введите свой рост (сантиметры).\n");
                scanf("%d", &a);
                printf("Введите свой вес (кг).\n");
                scanf("%d", &b);
                printf("Индекс массы вашего тела: %5.2f.\n\n", b * 10000.0 / (a * a));
                goto begin;

            case 6:
                printf("Введите число.\n");
                scanf("%d", &a);
                // А по правилам надо бы использовать a = getchar();
                c = a;
                while (a > 0) {
                    b = a % 10;
                    a = a / 10;
                    k = k * 10 + b;
                }
                if (k == c)
                    printf("Число - палендром.\n\n");
                else
                    printf("Число - не палендром.\n\n");
                goto begin;

            case 7:
                printf("Введите название компании.\n");
                memset(&insert[0], 0, sizeof(insert));
                scanf("%s", &insert);
                d = insert;

                transform(d.begin(), d.end(), d.begin(), ::toupper);
                if (d == "OPPO" ||
                    d == "VIVO" ||
                    d == "ONEPLUS" ||
                    d == "REALME" ||
                    d == "IMOO") {
                    printf("Это дочерняя компания холдинга BBK.\n\n");
                    goto begin;
                } else {
                    printf("Это НЕ дочерняя компания холдинга BBK.\n\n");
                    goto begin;
                }

            case 8:
                printf("Введите число.\n");
                scanf("%d", &a);
                if (power_of_two(a))
                    printf("Число является степенью двойки.\n\n");
                else
                    printf("Число не является степенью двойки.\n\n");

            case 9:
                printf("Компьютер загадал случайное число от 1 до 10. Угадайте его. Даётся три попытки\n");
                srand(time(nullptr));
                c = rand() % 10 + 1;
                a = 0; // Количество попыток
                while (a++ < 3) {
                    scanf("%d", &b);
                    if (b == c) {
                        printf("Верно! Вы угадали с %d попыток.\n\n", a);
                        break;
                    } else if (a < 3) {
                        printf("Неверно, попробуйте ещё раз.\n");
                    }
                }
                if (b != c)
                    printf("У вас закончились попытки. Сожалею.\n\n");

                goto begin;

            case 10:
                printf("Введите исходное число в десятеричной системе счисления.\n");
                scanf("%d", &c);
                printf("Введите разрядность системы счисления для результата (от 2 до 36).\n");
                scanf("%d", &b);

                temp = "";

                while (c > 0) {
                    if (c == b) {
                        temp = "10" + temp;
                        break;
                    } else if (c % b > 9)
                        temp = char('A' + (c % b) - 10) + temp;
                    else
                        temp = char((c % b) + '0') + temp;

                    c /= b;
                }

                printf("Результат перевода числа в %i систему счисления: %s.\n\n", b, &temp);

                goto begin;


            default:
                break;
        }

        end:
        printf("\n");
    }
};

#endif //UNTITLED_FIRST_H
