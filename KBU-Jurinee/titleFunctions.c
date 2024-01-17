#include "JurineeHeader.h"

//--------- 타이틀 디자인 시작 --------------------------------

void printBorder(int width) {
    for (int i = 0; i < width; i++) {
        printf("□");
    }
    printf("\n");
}

void printTextWithBorder(char* text) {
    printf("\n");
    int textLength = strlen(text);
    int totalWidth = textLength - 7; // 텍스트와 테두리의 총 폭
    int leftSpaces = (65 - totalWidth) / 2; // 화면 가로폭은 예시로 110으로 설정

    // 첫 줄 테두리 가운데 정렬
    for (int i = 0; i < leftSpaces; i++) {
        printf(" ");
    }
    printf("□");
    printBorder(totalWidth - 2); // 첫 줄 테두리 출력

    // 텍스트 출력
    for (int i = 0; i < leftSpaces; i++) {
        printf(" ");
    }
    printf("□");
    printf("%s", text);
    printf(" □\n");
    for (int i = 0; i < leftSpaces; i++) {
        printf(" ");
    }

    // 나머지 테두리 가운데 정렬
    printBorder(totalWidth - 1); // 나머지 테두리 출력
}


//--------- 홈 메뉴 시작 --------------------------------
void mainHomeMenu() {

    setColor(YELLOW);
    char homeMenuChoice[5];
    
    printf("\n\t\t\t설명      시작      종료\n");
    printf("\n\t\t\t랭킹      정보      출처\n");
    printf("\n\t\t    원하는 메뉴를 문자로 입력하세요 : ");
    scanf("%s", homeMenuChoice);

    if (strcmp(homeMenuChoice, "설명") == 0) {
        setColor(WHITE);
        system("cls");
        showInstructions();
        mainHomeMenu();
    }
    else if (strcmp(homeMenuChoice, "시작") == 0) {
        setColor(WHITE);
        system("cls");
        Sleep(5);
        printf("\n\n가상 주식 시뮬레이션 프로그램 시작하겠습니다.\n");
        printf("처음은 2015년입니다. 주어진 초기자본을 사용해주세요.\n");
        system("cls");
        inGameTitle();
    }
    else if (strcmp(homeMenuChoice, "종료") == 0) {
        setColor(WHITE);
        printf("\n\n[종료]\n");
        printf("프로그램을 종료합니다.\n");
        exit(0);
    }
    else if (strcmp(homeMenuChoice, "랭킹") == 0) {
        setColor(WHITE);
        printf("\n\n[랭킹]\n");
        USER user;
        getUserInput(&user);
        saveToUserRanking("userRanking.txt", &user);
        printUserRanking("userRanking.txt");
        printf("\n\n");
        mainHomeMenu();
    }
    else if (strcmp(homeMenuChoice, "정보") == 0) {
        setColor(WHITE);
        printf("\n\n[정보]\n");
        printf("- 만든이: 마다현, 이현묵\n");
        printf("- 날짜: 2023-12-13\n");
        printf("- 장소: 한국성서대학교\n");

        printf("\n");
        mainHomeMenu();
    }
    else if (strcmp(homeMenuChoice, "출처") == 0) {
        setColor(WHITE);
        printf("\n\n[출처]\n");
        printf("1. https://kr.investing.com \n");
        printf("2. https://www.google.com \n");
        printf("3. https://www.naver.com \n");
        printf("4. https://kiffblog.tistory.com/151 \n");
        printf("5. https://coding-factory.tistory.com/663 \n");
        printf("6. https://clgnsdl94.tistory.com/25 \n");
        printf("7. https://mwultong.blogspot.com/2007/09/c-printf-right.html\n");
        printf("\n\n");
        mainHomeMenu();
    }
    else {
        setColor(WHITE);
        printf("\n\n\t\t    ");
        printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        printf("\n\n");
        mainHomeMenu();
    }
}



//--------- 홈 메뉴 1.방법 시작 --------------------------------
void showInstructions() {
    //playSound("typingSound.mp3");
    setColor(WHITE);

    const char* message = "\n[이용방법]\n"
        "현실에서의 5분을 시뮬레이션에서는 2년으로 간주됩니다.\n"
        "과거 특정 시점의 실제 주식 데이터를 가져온 것이므로,\n"
        "과거 당시의 주식에 대한 지식이 있다면 유리합니다.\n"
        "정보거래소에서 각 단계에 해당하는 예상 정보를 구매할 수 있습니다.\n"
        "정보는 각 단계별로 1만, 2만, 3만원입니다.\n"
        "주식 종목은 총 5개이며, 기간은 2015년을 기점으로 17년, 19년, 21년, 23년 총 4회 실시됩니다.\n\n";

    // 문자열의 각 글자를 한 글자씩 출력
    for (const char* c = message; *c != '\0'; c++) {
        putchar(*c);
        fflush(stdout);
        Sleep(10);  // Windows에서는 Sleep 함수를 사용
    }
}

//--------홈 메뉴 2.방법 시작--------------------
void saveToUserRanking(const char* filename, const USER* user) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "%s %d\n", user->name, user->amount);

    fclose(file);
}

void printUserRanking(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    printf("\n\n[사용자 랭킹]\n");

    USER user;
    while (fscanf(file, "%s %d", user.name, &user.amount) == 2) {
        printf("이름: %s, 최종자산: %d\n", user.name, user.amount);
    }
    fclose(file);
}

void getUserInput(USER* user) {
    printf("이름: ");
    scanf("%s", user->name);

    printf("최종 자산: ");
    scanf_s("%d", &user->amount);
}