// publicFunctions.c
#include "JurineeHeader.h"

//--------텍스트 컬러입히기--------------------

void setColor(unsigned short text) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

//--------현재 커서 위치 좌표 찍기--------------------
void getCursorPosition() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        coord = csbi.dwCursorPosition;
        printf("커서: (%d, %d)\n", coord.X, coord.Y);
    }
    else {
        fprintf(stderr, "커서 위치 에러남.\n");
    }
}
