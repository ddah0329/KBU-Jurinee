// graph.c
#include "JurineeHeader.h"


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void displayGraph() {
    double values[] = { 70.0, 60.0, 50.0, 40.0, 30.0, 20.0, 10.0, 5.0, 1.0, 0.5 };
    int numValues = sizeof(values) / sizeof(values[0]);

    int totalSpaces = 0;

    for (int i = 0; i < numValues; i++) {
        printValueAndDot(values[i], totalSpaces);
        totalSpaces += 2;
    }

    gotoxy(66, 30);

    printLineWithNumbers(2015, 2023);
    //getCursorPosition();
}

void printValueAndDot(double value, int spaces) {
    printf("\n\t%5.1f ┼", value);
    printf("\n\t      ┼");
    for (int i = 0; i < spaces; i++) {
        printf("      ");
    }
}


void printLineWithNumbers(int start, int end) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\t        ─────");
    for (int i = start; i <= end; i += 2) {
        printf("┼───────");
    }
    printf("\n\t           ");
    for (int i = start; i <= end; i += 2) {
        printf("%-8d", i);
    }
}



void year2015() {
    setColor(BLUE); 
    gotoxy(21, 22); //파랭이 A 바이오 628,293원
    printf("●");
    setColor(DARK_YELLOW);
    gotoxy(20, 28); //노랭이 B 뷰티 216,000원
    printf("●");
    setColor(GREEN);
    gotoxy(21, 31); //초랭이 C IT 92,300원
    printf("●");
    setColor(RED);
    gotoxy(22, 28); //빨갱이 D 운송 211,000원
    printf("●");
    setColor(VIOLET);
    gotoxy(21, 32); //분홍이 E 엔터 6,875원
    printf("●");
    
    setColor(WHITE);
    /*timer5MINS();*/
    //printStockPrices();
}

void year2017() {
   
    setColor(BLUE);
    gotoxy(30, 29); //파랭이 A 바이오 325,432원
    printf("●");
    setColor(DARK_YELLOW);
    gotoxy(30, 31); //노랭이 B 뷰티 251,500원
    printf("●");
    setColor(GREEN);
    gotoxy(30, 20); //초랭이 C IT 192,000원
    printf("●");
    setColor(RED);
    gotoxy(30, 34); //빨갱이 D 운송 139,500원
    printf("●");
    setColor(VIOLET);
    gotoxy(30, 30); //분홍이 E 엔터 5,000원
    printf("●");
}

void year2019() {
      setColor(BLUE);
    gotoxy(37, 35); //파랭이 A 바이오 286,057원
    printf("●");
    setColor(DARK_YELLOW);
    gotoxy(37, 33); //노랭이 B 뷰티 143,500원
    printf("●");
    setColor(GREEN);
    gotoxy(37, 27); //초랭이 C IT 108,500원
    printf("●");
    setColor(RED);
    gotoxy(37, 32); //빨갱이 D 운송 190,500원
    printf("●");
    setColor(VIOLET);
    gotoxy(37, 30); //분홍이 E 엔터 12,700원
    printf("●");
}

void year2021() {
    setColor(BLUE);
    gotoxy(45, 29); //파랭이 A 바이오 340,969원
    printf("●");
    setColor(DARK_YELLOW);
    gotoxy(45, 33); //노랭이 B 뷰티 157,000원
    printf("●");
    setColor(GREEN);
    gotoxy(45, 20); //초랭이C IT 440,000원
    printf("●");
    setColor(RED);
    gotoxy(45, 34); //빨갱이 D 운송 124,000원
    printf("●");
    setColor(VIOLET);
    gotoxy(45, 30); //분홍이 E 엔터 7,925원
    printf("●");
}

//----완료-----
void year2023() {
    setColor(BLUE);
    gotoxy(53, 30); //파랭이 A 바이오 293,818원
    printf("●");
    setColor(DARK_YELLOW);
    gotoxy(53, 34); //노랭이 B 뷰티 118,500원
    printf("●");
    setColor(GREEN);
    gotoxy(53, 33); //초랭이C IT 178,300원
    printf("●");
    setColor(RED);
    gotoxy(53, 35); //빨갱이 D 운송 81,300원
    printf("●");
    setColor(VIOLET);
    gotoxy(53, 38); //분홍이 E 엔터 27,500원
    printf("●");
}
