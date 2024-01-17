#include "JurineeHeader.h"

//--------- Ÿ��Ʋ ������ ���� --------------------------------

void printBorder(int width) {
    for (int i = 0; i < width; i++) {
        printf("��");
    }
    printf("\n");
}

void printTextWithBorder(char* text) {
    printf("\n");
    int textLength = strlen(text);
    int totalWidth = textLength - 7; // �ؽ�Ʈ�� �׵θ��� �� ��
    int leftSpaces = (65 - totalWidth) / 2; // ȭ�� �������� ���÷� 110���� ����

    // ù �� �׵θ� ��� ����
    for (int i = 0; i < leftSpaces; i++) {
        printf(" ");
    }
    printf("��");
    printBorder(totalWidth - 2); // ù �� �׵θ� ���

    // �ؽ�Ʈ ���
    for (int i = 0; i < leftSpaces; i++) {
        printf(" ");
    }
    printf("��");
    printf("%s", text);
    printf(" ��\n");
    for (int i = 0; i < leftSpaces; i++) {
        printf(" ");
    }

    // ������ �׵θ� ��� ����
    printBorder(totalWidth - 1); // ������ �׵θ� ���
}


//--------- Ȩ �޴� ���� --------------------------------
void mainHomeMenu() {

    setColor(YELLOW);
    char homeMenuChoice[5];
    
    printf("\n\t\t\t����      ����      ����\n");
    printf("\n\t\t\t��ŷ      ����      ��ó\n");
    printf("\n\t\t    ���ϴ� �޴��� ���ڷ� �Է��ϼ��� : ");
    scanf("%s", homeMenuChoice);

    if (strcmp(homeMenuChoice, "����") == 0) {
        setColor(WHITE);
        system("cls");
        showInstructions();
        mainHomeMenu();
    }
    else if (strcmp(homeMenuChoice, "����") == 0) {
        setColor(WHITE);
        system("cls");
        Sleep(5);
        printf("\n\n���� �ֽ� �ùķ��̼� ���α׷� �����ϰڽ��ϴ�.\n");
        printf("ó���� 2015���Դϴ�. �־��� �ʱ��ں��� ������ּ���.\n");
        system("cls");
        inGameTitle();
    }
    else if (strcmp(homeMenuChoice, "����") == 0) {
        setColor(WHITE);
        printf("\n\n[����]\n");
        printf("���α׷��� �����մϴ�.\n");
        exit(0);
    }
    else if (strcmp(homeMenuChoice, "��ŷ") == 0) {
        setColor(WHITE);
        printf("\n\n[��ŷ]\n");
        USER user;
        getUserInput(&user);
        saveToUserRanking("userRanking.txt", &user);
        printUserRanking("userRanking.txt");
        printf("\n\n");
        mainHomeMenu();
    }
    else if (strcmp(homeMenuChoice, "����") == 0) {
        setColor(WHITE);
        printf("\n\n[����]\n");
        printf("- ������: ������, ������\n");
        printf("- ��¥: 2023-12-13\n");
        printf("- ���: �ѱ��������б�\n");

        printf("\n");
        mainHomeMenu();
    }
    else if (strcmp(homeMenuChoice, "��ó") == 0) {
        setColor(WHITE);
        printf("\n\n[��ó]\n");
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
        printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
        printf("\n\n");
        mainHomeMenu();
    }
}



//--------- Ȩ �޴� 1.��� ���� --------------------------------
void showInstructions() {
    //playSound("typingSound.mp3");
    setColor(WHITE);

    const char* message = "\n[�̿���]\n"
        "���ǿ����� 5���� �ùķ��̼ǿ����� 2������ ���ֵ˴ϴ�.\n"
        "���� Ư�� ������ ���� �ֽ� �����͸� ������ ���̹Ƿ�,\n"
        "���� ����� �ֽĿ� ���� ������ �ִٸ� �����մϴ�.\n"
        "�����ŷ��ҿ��� �� �ܰ迡 �ش��ϴ� ���� ������ ������ �� �ֽ��ϴ�.\n"
        "������ �� �ܰ躰�� 1��, 2��, 3�����Դϴ�.\n"
        "�ֽ� ������ �� 5���̸�, �Ⱓ�� 2015���� �������� 17��, 19��, 21��, 23�� �� 4ȸ �ǽõ˴ϴ�.\n\n";

    // ���ڿ��� �� ���ڸ� �� ���ھ� ���
    for (const char* c = message; *c != '\0'; c++) {
        putchar(*c);
        fflush(stdout);
        Sleep(10);  // Windows������ Sleep �Լ��� ���
    }
}

//--------Ȩ �޴� 2.��� ����--------------------
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

    printf("\n\n[����� ��ŷ]\n");

    USER user;
    while (fscanf(file, "%s %d", user.name, &user.amount) == 2) {
        printf("�̸�: %s, �����ڻ�: %d\n", user.name, user.amount);
    }
    fclose(file);
}

void getUserInput(USER* user) {
    printf("�̸�: ");
    scanf("%s", user->name);

    printf("���� �ڻ�: ");
    scanf_s("%d", &user->amount);
}