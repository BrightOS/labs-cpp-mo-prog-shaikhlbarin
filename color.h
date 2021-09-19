//
// Created by Денис on 19.09.2021.
//

#ifndef UNTITLED_COLOR_H
#define UNTITLED_COLOR_H

using namespace std;

void set_color(int text_color, int background_color) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Console descriptor
    SetConsoleTextAttribute(hStdOut, (WORD) ((background_color << 4) | text_color));
}

void set_color(int text_color) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Console descriptor
    SetConsoleTextAttribute(hStdOut, (WORD) (text_color));
}

#endif //UNTITLED_COLOR_H
