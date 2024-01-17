//main.c
#include "JurineeHeader.h"

//void getCursorPosition(); //현재 커서 위치 좌표 찍기


int main() {
    //col = 가로, lines = 세로
    system("mode con:cols=80 lines=200"); //콘솔창 열때 사이즈 조절

    //GameState state = { 2015, 500000, "None", 1, 0 };

    char simulationText[] = " 가상 주식 시뮬레이션";
    printTextWithBorder(simulationText);

    printf("\n\n  본 가상 주식 시뮬레이션 프로그램은 실제 주식과는 다를 수 있음을 알려드립니다.\n\n\n");
    mainHomeMenu();
    
        return 0;
    
}// main 끝

