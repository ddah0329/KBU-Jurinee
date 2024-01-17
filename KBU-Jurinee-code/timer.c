// timer.c
#include "JurineeHeader.h"

#pragma comment(lib, "winmm.lib")

void timer5MINS(){
    int startTime = 300; // 5분 = 300초
    int currentTime = 0;
    int remainingTime = startTime;
    int choice;

    while (1) {
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;

        printf("남은 시간: %d분 %d초\r", minutes, seconds);
        Sleep(1000);
        remainingTime--;

        if (remainingTime <= 0) {
            printf("타이머 종료\n");
            break;
        }

        if (_kbhit()) {
            scanf("%d", &choice);
            if (choice == 1) {
                printf("스킵! 타이머 초기화\n");
                remainingTime = startTime;
            }
            else {
                printf("잘못 입력하였습니다.\n");
            }
        }
    }
}


