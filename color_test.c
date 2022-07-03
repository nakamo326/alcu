#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) 
{
    // 端末の準備
    initscr();

    // 色の準備
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);    // 色1 は青地に赤文字
    init_pair(2, COLOR_GREEN, COLOR_BLUE);  // 色2 は青地に緑文字
    init_pair(3, COLOR_YELLOW, COLOR_BLUE); // 色3 は青地に黄文字
    init_pair(10, COLOR_WHITE, COLOR_BLUE); // 色10 は青地に白文字
    bkgd(COLOR_PAIR(10));           // 背景は色10

    // 表示
    attrset(COLOR_PAIR(1));         // 色1 を使う
    mvaddstr(5,  5, "Hello World");
    attrset(COLOR_PAIR(2));         // 色2 を使う
    mvaddstr(5, 25, "Hello World");
    attrset(COLOR_PAIR(3));         // 色3 を使う
    mvaddstr(5, 45, "Hello World");

    attrset(COLOR_PAIR(1) | A_BOLD);        // 色＆強調表示
    mvaddstr(6,  5, "Hello World");
    attrset(COLOR_PAIR(2) | A_BOLD);
    mvaddstr(6, 25, "Hello World");
    attrset(COLOR_PAIR(3) | A_BOLD);
    mvaddstr(6, 45, "Hello World");

    attrset(COLOR_PAIR(1) | A_REVERSE);     // 色＆反転表示
    mvaddstr(7,  5, "Hello World");
    attrset(COLOR_PAIR(2) | A_REVERSE);
    mvaddstr(7, 25, "Hello World");
    attrset(COLOR_PAIR(3) | A_REVERSE);
    mvaddstr(7, 45, "Hello World");

    attrset(COLOR_PAIR(1) | A_REVERSE | A_BOLD);    // 色＆反転＆強調
    mvaddstr(8,  5, "Hello World");
    attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
    mvaddstr(8, 25, "Hello World");
    attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
    mvaddstr(8, 45, "Hello World");

    // 終了
    getch();

    endwin();
    return (0);
}