//inGameFunctions.c
#include "JurineeHeader.h"

void buyNews();

//--------- Ȩ �޴� 2.���� ���� --------------------------------
void inGameTitle() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t����   �����   ���     ����\n");
    printf("\t\t\t    ��   ��    ��     ��     ��    \n");
    printf("\t\t\t����   ��    ��     ��     ����\n");
    printf("\t\t\t��       ��    ��     ��         ��\n");
    printf("\t\t\t����   �����   ����   ����\n");

    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t����   �����   ���    ����\n");
    //printf("\t\t\t    ��   ��    ��     ��    ��  ��\n");
    //printf("\t\t\t����   ��    ��     ��        ��\n");
    //printf("\t\t\t��       ��    ��     ��        ��\n");
    //printf("\t\t\t����   �����   ����      ��\n");
    //
    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t����   �����   ���     ����\n");
    //printf("\t\t\t    ��   ��    ��     ��     ��  ��\n");
    //printf("\t\t\t����   ��    ��     ��     ����\n");
    //printf("\t\t\t��       ��    ��     ��         ��\n");
    //printf("\t\t\t����   �����   ����   ����\n");
    //
    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t����   �����   ����   ���\n");
    //printf("\t\t\t    ��   ��    ��       ��     ��\n");
    //printf("\t\t\t����   ��    ��   ����     ��\n");
    //printf("\t\t\t��       ��    ��   ��         ��\n");
    //printf("\t\t\t����   �����   ����   ����\n");
    //
    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t����   �����   ����   ����\n");
    //printf("\t\t\t    ��   ��    ��       ��       ��\n");
    //printf("\t\t\t����   ��    ��   ����   ����\n");
    //printf("\t\t\t��       ��    ��   ��           ��\n");
    //printf("\t\t\t����   �����   ����   ����\n");
    displayGraph();
    //getCursorPosition();
    year2015();
    Sleep(1500);
    year2017();
    Sleep(1500);
    year2019();
    Sleep(1500);
    year2021();
    Sleep(1500);
    year2023();
    
    gotoxy(80, 15);
    companyColor();
    //----------
    gotoxy(20, 45);
    myInfo(companyIndex);
    //----------
    gotoxy(80, 30);
    print2015StockPrices();
    //----------
    gotoxy(85, 45);
    inGameMenu();
    //----------
    timer5MINS();

}
void companyColor() {
    printf("\n");
    setColor(BLUE);
    printf("�� A ���̿�\n");
    setColor(DARK_YELLOW);
    printf("�� B ��Ƽ\n");
    setColor(GREEN);
    printf("�� C IT\n");
    setColor(RED);
    printf("�� D ���\n");
    setColor(VIOLET);
    printf("�� E ����\n");
    setColor(WHITE);

}

void inGameMenu() {
    setColor(YELLOW);
    printf("\n\n\t\t1. �ֽ� ���� (�ż�)   2. �ֽ� �Ǹ� (�ŵ�)\n\n");
    printf("\t\t3. �����ŷ���         4. 5�� �ǳʶٱ�\n\n");
    printf("\t\t5. ���� �� ��Ȳ       6. ����ȭ������ ������\n\n");
    printf("\t\t         ��ȣ�� ����ּ���.(1 - 6) : ");
    
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        setColor(WHITE);
        system("cls");
        buyStock(companyIndex);
        inGameMenu();
        break;
    case 2:
        setColor(WHITE);
        system("cls");
        sellStock(companyIndex);
        sellStock(0);
        inGameMenu();
        break;
    case 3:
        setColor(WHITE);
        system("cls");
        printf("�����ŷ���\n");
        buyNews();
        inGameMenu();
        break;
    case 4:
        setColor(WHITE);
        system("cls");
        printf("5�� �ǳʶٱ�\n");
        inGameMenu();
        break;
    case 5:
        setColor(WHITE);
        system("cls");
        myInfo(companyIndex);
        inGameMenu();
        break;
    case 6:
        setColor(WHITE);
        system("cls");
        inGameTitle();
        break;
    default:
        setColor(WHITE);
        printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
        printf("\n\n");
        inGameMenu();
        break;
    }
}

