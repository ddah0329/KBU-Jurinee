// timer.c
#include "JurineeHeader.h"

#pragma comment(lib, "winmm.lib")

void timer5MINS(){
    int startTime = 300; // 5�� = 300��
    int currentTime = 0;
    int remainingTime = startTime;
    int choice;

    while (1) {
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;

        printf("���� �ð�: %d�� %d��\r", minutes, seconds);
        Sleep(1000);
        remainingTime--;

        if (remainingTime <= 0) {
            printf("Ÿ�̸� ����\n");
            break;
        }

        if (_kbhit()) {
            scanf("%d", &choice);
            if (choice == 1) {
                printf("��ŵ! Ÿ�̸� �ʱ�ȭ\n");
                remainingTime = startTime;
            }
            else {
                printf("�߸� �Է��Ͽ����ϴ�.\n");
            }
        }
    }
}


