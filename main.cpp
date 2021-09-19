#include "first.h"
#include "second.h"
#include <cstdio>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    set_color(10);
    printf("Разработчик - Денис Шайхльбарин - @BrightOS\n\n");
    while (true) {
        set_color(3);
        printf("Выберите одну из следующих лабораторных работ:\n");
        set_color(7);
        printf("1. 10 программ.\n");
        printf("2. Визуализация трёх алгоритмов сортировки.\n");
        printf("0. Выход из программы.\n");
        int a = 0;

        set_color(6);
        printf("> ");
        set_color(7);

        scanf("%d", &a);

        if (a == 0)
            exit(0);

        set_color(3);
        printf("\rВыбрана лабораторная работа: ");
        set_color(7);

        switch (a) {
            case 1:
                printf("10 программ.\n\n");

                (new First())->start();
                break;
            case 2:
                printf("Визуализация трёх алгоритмов сортировки.\n\n");

                (new Second())->start();
                break;
            default:
                break;
        }
    }
}