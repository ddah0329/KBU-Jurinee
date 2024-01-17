//inGameFunctions.c
#include "JurineeHeader.h"

void buyNews();

//--------- 홈 메뉴 2.시작 시작 --------------------------------
void inGameTitle() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t□□□   □□□□   □□     □□□\n");
    printf("\t\t\t    □   □    □     □     □    \n");
    printf("\t\t\t□□□   □    □     □     □□□\n");
    printf("\t\t\t□       □    □     □         □\n");
    printf("\t\t\t□□□   □□□□   □□□   □□□\n");

    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t□□□   □□□□   □□    □□□\n");
    //printf("\t\t\t    □   □    □     □    □  □\n");
    //printf("\t\t\t□□□   □    □     □        □\n");
    //printf("\t\t\t□       □    □     □        □\n");
    //printf("\t\t\t□□□   □□□□   □□□      □\n");
    //
    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t□□□   □□□□   □□     □□□\n");
    //printf("\t\t\t    □   □    □     □     □  □\n");
    //printf("\t\t\t□□□   □    □     □     □□□\n");
    //printf("\t\t\t□       □    □     □         □\n");
    //printf("\t\t\t□□□   □□□□   □□□   □□□\n");
    //
    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t□□□   □□□□   □□□   □□\n");
    //printf("\t\t\t    □   □    □       □     □\n");
    //printf("\t\t\t□□□   □    □   □□□     □\n");
    //printf("\t\t\t□       □    □   □         □\n");
    //printf("\t\t\t□□□   □□□□   □□□   □□□\n");
    //
    ////-------
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t□□□   □□□□   □□□   □□□\n");
    //printf("\t\t\t    □   □    □       □       □\n");
    //printf("\t\t\t□□□   □    □   □□□   □□□\n");
    //printf("\t\t\t□       □    □   □           □\n");
    //printf("\t\t\t□□□   □□□□   □□□   □□□\n");
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
    printf("● A 바이오\n");
    setColor(DARK_YELLOW);
    printf("● B 뷰티\n");
    setColor(GREEN);
    printf("● C IT\n");
    setColor(RED);
    printf("● D 운송\n");
    setColor(VIOLET);
    printf("● E 엔터\n");
    setColor(WHITE);

}

void inGameMenu() {
    setColor(YELLOW);
    printf("\n\n\t\t1. 주식 구매 (매수)   2. 주식 판매 (매도)\n\n");
    printf("\t\t3. 정보거래소         4. 5분 건너뛰기\n\n");
    printf("\t\t5. 나의 현 상황       6. 메인화면으로 나가기\n\n");
    printf("\t\t         번호를 골라주세요.(1 - 6) : ");
    
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
        printf("정보거래소\n");
        buyNews();
        inGameMenu();
        break;
    case 4:
        setColor(WHITE);
        system("cls");
        printf("5분 건너뛰기\n");
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
        printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        printf("\n\n");
        inGameMenu();
        break;
    }
}

