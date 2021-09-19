//
// Created by Денис on 19.09.2021.
//

#ifndef UNTITLED_SECOND_H
#define UNTITLED_SECOND_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <windows.h>
#include <cstring>
#include <ctime>
#include <vector>
#include "color.h"

using namespace std;

class Second {
public:
    void start() {
        second_main();
    }

private:
    int a, b, c, n, temp, columns;
    bool flag;
    vector<int> v;
    int ar[10];
    string d, s;

    const int delay = 500;

    static int get_random_number(int min, int max) {
        int num = min + rand() % (max - min + 1);
        return num;
    }

    void print_vector(vector<int> &vect, int first,
                      int second, int begin_sorted_count,
                      int end_sorted_count, bool second_yellow,
                      bool second_red) const {
        int size = vect.size();

        printf("\r");

        for (int i = 0; i < size; i++) {

            if (!(first == 0 && second == 0))
                if (i == first)
                    set_color(2); // Green
                else if (i == second)
                    if (second_yellow)
                        set_color(6); // Yellow
                    else if (second_red)
                        set_color(4); // Red
                    else
                        set_color(2); // Green
                else if (begin_sorted_count != end_sorted_count)
                    if (i < begin_sorted_count || i > size - end_sorted_count - 1)
                        set_color(5); // Light green
                    else
                        set_color(7); // White
                else
                    set_color(7); // White
            else
                set_color(7); // White

            printf("%d ", vect[i]);
        }
        Sleep(delay);
    }

    void quick_sort(int *array, int low, int high) {
        int i = low;
        int j = high;
        int pivot = array[(i + j) / 2];

        while (i <= j) {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;

            flag = false;

            if (i <= j) {
                vector<int> vect(begin(ar), end(ar));
                print_vector(vect, i, j, 0, 0, true, false);
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
                flag = true;
            }

            vector<int> vect2(begin(ar), end(ar));
            if (flag)
                print_vector(vect2, i - 1, j + 1, 0, 0, false, false);
            else
                print_vector(vect2, i, j, 0, 0, false, false);
        }
        if (j > low)
            quick_sort(array, low, j);
        if (i < high)
            quick_sort(array, i, high);
    }

    void generate_random_vector(vector<int> &vect) {
        v.clear();
        srand(time(nullptr));
        for (int i = 0; i < 10; i++)
            v.push_back(get_random_number(a, b));

        n = vect.size();

        set_color(3);
        printf("\nНачальный массив:\n");
        print_vector(vect, 0, 0, 0, 0, false, false);
        printf("\n\n");
    }

    void print_end(vector<int> &vect) {
        print_vector(vect, 0, 0, 0, 0, false, false);
        set_color(3);
        printf("\rОтсортированный массив:                                 \n");
        print_vector(vect, 0, 0, 0, 0, false, false);
        printf("\n\n");
    }

    int second_main() {
        SetConsoleOutputCP(CP_UTF8);

        set_color(3);
        printf("Введите диапазон значений \"от\" и \"до\" через пробел (или же \"0 0\", чтобы использовать диапазон 10..999):\nЫ");

        set_color(6);
        printf("> ");
        set_color(7);

        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) {
            a = 10;
            b = 999;
        }
        printf("\n");

        while (true) {
            set_color(7);

            c = 0;
            temp = 0;
            d = "";
            s = "";
            v.clear();
            flag = true;
            set_color(3);
            printf("Выберите один из алгоритмов сортировки:\n");
            set_color(7);
            printf("1. Сортировка пузырьком.\n");
            printf("2. Обменная сортировка.\n");
            printf("3. Быстрая сортировка.\n");
            printf("0. Возврат в меню выбора лабораторных работ.\n");

            set_color(6);
            printf("> ");
            set_color(7);

            scanf("%d", &n);

            if (n == 0)
                goto end;

            set_color(3);
            printf("\rВыбрана программа: ");
            set_color(7);

            switch (n) {
                case 1:
                    printf("Сортировка пузырьком.\n");

                    generate_random_vector(v);

                    for (int i = 0; i < n - 1 && flag; i++) {
                        flag = false;

                        for (int j = 0; j < n - i - 1; j++) {
                            if (v[j] > v[j + 1]) {
                                print_vector(v, j, j + 1, 0, i, true, false);
                                temp = v[j];
                                v[j] = v[j + 1];
                                v[j + 1] = temp;
                                flag = true;
                            }

                            print_vector(v, j, j + 1, 0, i, false, false);
                        }

                        if (!flag)
                            break;
                    }

                    print_end(v);
                    break;
                case 2:
                    printf("Обменная сортировка.\n");

                    generate_random_vector(v);

                    n = v.size();
                    for (int k = 0; k < n - 1; k++)
                        for (int i = k + 1; i < n; i++)
                            if (v[k] > v[i]) {
                                print_vector(v, k, i, k, 0, true, false);
                                temp = v[k];
                                v[k] = v[i];
                                v[i] = temp;
                                print_vector(v, k, i, k, 0, false, false);
                            } else {
                                print_vector(v, k, i, k, 0, false, true);
                            }
                    print_end(v);
                    break;
                case 3:
                    printf("Быстрая сортировка.\n");
                    generate_random_vector(v);
                    copy(v.begin(), v.end(), ar);
                    quick_sort(ar, 0, 9);
                    v = vector<int>(begin(ar), end(ar));
                    print_end(v);
                    break;
                default:
                    printf("Программа не найдена.\n\n", n);
                    break;
            }
        }

        end:
        printf("\n");
    }
};

#endif //UNTITLED_SECOND_H
