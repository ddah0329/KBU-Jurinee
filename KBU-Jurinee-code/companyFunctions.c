//companyFunctions.c
#include "JurineeHeader.h"

// �������� : �ʱ� ���ڱ�
int currentMoney = 700000;

// ȸ�� ���� �ʱ�ȭ
StockCompany companies[] = {
    {"A ���̿�", {2015, 2017, 2019, 2021, 2023}, {628293, 325432, 286057, 340969, 293818}},
    {"B ��Ƽ", {2015, 2017, 2019, 2021, 2023}, {216000, 251500, 143500, 157000, 118500}},
    {"C IT", {2015, 2017, 2019, 2021, 2023}, {92300, 192000, 108500, 440000, 178300}},
    {"D ���", {2015, 2017, 2019, 2021, 2023}, {211000, 139500, 190500, 124000, 81300}},
    {"E ����", {2015, 2017, 2019, 2021, 2023}, {6875, 5000, 12700, 7925, 27500}},
};

// ������� �ֽ� ���� ���� �ʱ�ȭ
StockHoldings userHoldings[] = {
    {0, 0}, // A ���̿�
    {0, 0}, // B ��Ƽ
    {0, 0}, // C IT
    {0, 0}, // D ���
    {0, 0}  // E ����
};

void myInfo(int companyIndex){
printf("\n������ ��Ʈ������ ������\n");
for (int i = 0; i < 5; i++) {
    printf("%s: ���� �ֽ� �� = %d ���� �ݾ� = %d\n\n", companies[i].name, userHoldings[i].quantity, userHoldings[companyIndex].totalInvestment);
}
printf("\n������ ���� �ں� ������\n");
printf("���� �ں�: %d", currentMoney);
}

void buyStock(char companySymbol, int year) {
    int quantity;
    printf("\n\n\t\t\t      ��������\n");
    printf("\t\t\t      ��   �ż�   ��\n");
    printf("\t\t\t      ��������\n\n\n\n");

    companyColor();

    printf("\t  �ż��� �ֽ� ������ �����ϼ��� (A-E) : ");
    scanf(" %c", &companySymbol);

    // ���ڸ� �ε����� �ٲ� (A=0, B=1, ..., E=4)
    int companyIndex = companySymbol - 'A';

    if (companyIndex < 0 || companyIndex >= 5) {
        printf("��ȿ�� ȸ�簡 �ƴմϴ�.\n");
        printf("�ٽ� �õ����ֽñ� �ٶ��ϴ�.\n");
        return;
    }

    printf("\t  ���� ������ �Է����ּ���(ex. 2015): ");
    scanf("%d", &year);

    if (companies[companyIndex].year[companyIndex] != year) {
        printf("\t  ��ȿ�� ������ �ƴմϴ�.\n");
        printf("\t  �ٽ� �õ����ֽñ� �ٶ��ϴ�.\n");
        return;
    }

    printf("\t  %c ȸ���� %d�⵵ �ְ��� �󸶳� �����ϰ� �����Ű���?: ", companySymbol, year);
    scanf("%d", &quantity);

    int totalCost = companies[companyIndex].price[year - 2015] * quantity;

    if (totalCost > currentMoney) {
        printf("\t  �ں��� �����Ͽ� �������� ���Ͽ����ϴ�.\n");
        inGameMenu();
    }
    else {
        userHoldings[companyIndex].quantity += quantity;
        userHoldings[companyIndex].totalInvestment += totalCost;
        currentMoney -= totalCost;
        printf("\t  �ż��� �Ϸ�Ǿ����ϴ�.\n");
        myInfo(companyIndex);
        system("cls");
        inGameTitle();
    }
}



void sellStock(char companySymbol, int year) {
    int quantity;
    printf("\n\n\t\t\t      ��������\n");
    printf("\t\t\t      ��   �ŵ�   ��\n");
    printf("\t\t\t      ��������\n\n\n\n");

    companyColor();

    printf("\t  �ŵ��� �ֽ� ������ �����ϼ��� (A-E) : ");
    scanf(" %c", &companySymbol);

    int companyIndex = companySymbol - 'A';

    if (companyIndex < 0 || companyIndex >= 5) {
        printf("\t  ��ȿ�� ȸ�簡 �ƴմϴ�.\n");
        printf("\t  �ٽ� �õ����ֽñ� �ٶ��ϴ�.\n");
        return;
    }

    printf("\t  ���� ������ �Է����ּ���(ex. 2015): ");
    scanf("%d", &year);

    if (companies[companyIndex].year[companyIndex] != year) {
        printf("\t  ��ȿ�� ������ �ƴմϴ�.\n");
        printf("\t  �ٽ� �õ����ֽñ� �ٶ��ϴ�.\n");
        return;
    }

    printf("\t  %c ȸ���� %d�⵵ �ְ��� �󸶳� �Ȱ� �����Ű���?: " , companySymbol, year);
    scanf("\t  %d", &quantity);

    if (quantity > userHoldings[companyIndex].quantity) {
        printf("\t  �ֽ� �������� ���� ���� ���Ͽ����ϴ�.\n");
    }
    else {
        int totalRevenue = companies[companyIndex].price[year - 2015] * quantity;
        userHoldings[companyIndex].quantity -= quantity;
        userHoldings[companyIndex].totalInvestment -= totalRevenue;
        currentMoney += totalRevenue;
        printf("\t  ���Ű� �Ϸ�Ǿ����ϴ�.\n");
        myInfo(companyIndex);
        system("cls");
        inGameTitle();
    }
}


void print2015StockPrices() {
    printf("\n\n\n���� 2015 �ְ� ���� ����\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[0]);
    }
    printf("\n");
    }

void print2017StockPrices() {
    printf("\n\n\n���� 2017 �ְ� ���� ����\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[1]);
    }
    printf("\n");
}

void print2019StockPrices() {
    printf("\n\n\n���� 2019 �ְ� ���� ����\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[2]);
    }
    printf("\n");
}

void print2021StockPrices() {
    printf("\n\n\n���� 2021 �ְ� ���� ����\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[3]);
    }
    printf("\n");
}

void print2023StockPrices() {
    printf("\n\n\n���� 2023 �ְ� ���� ����\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[4]);
    }
    printf("\n");
}


void buyNews() {
    int year;
    printf("\n\n\t\t\t  ������������\n");
    printf("\t\t\t  ��  �� �� �� �� ��  ��\n");
    printf("\t\t\t  ������������\n\n\n\n\n");
    printf("\t    ������ �� ������ 1~3�ܰ��� ������ �����Ǿ� �ֽ��ϴ�.");

    printf("� ������ � ������ �����Ͻðڽ��ϱ�?");
    scanf("%d %d", &year, &choice);
    if (year == 2017 && choice == 1) {
        printf("\n                           2017�� 1�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� 2017�� 3�� 10�� 11�� 21�� 31�ʡ����� 8��0 ������ġ �ڱ��� ����� �ĸ馢\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 10000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2017 && choice == 2) {
        printf("\n            2017�� 2�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������\n");
        printf("�� E������ �и� �Ű� ���ɼ� ����ǰ� �ִ�.��\n");
        printf("������������������������������������������������������������������������������������\n");
        currentMoney -= 20000;
        printf("���� �ں�: %d", currentMoney);
    }
    else if (year == 2017 && choice == 3) {
        printf("\n                            2017�� 3�ܰ� ����\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� A ���̿��� �Ǹ� ��������  G���̿��� 8050�� �޷�(��ȭ 906�� ��)������ ���ަ�\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 30000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2019 && choice == 1) {
        printf("\n              2019�� 1�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������\n");
        printf("�� B ��Ƽ�� ������� �ι��� �ֽ�ȸ�� H�� ���Ҧ�\n");
        printf("������������������������������������������������������������������������������������������\n");
        currentMoney -= 10000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2019 && choice == 2) {
        printf("\n            2019�� 2�ܰ� ����\n");
        printf("��������������������������������������������������������������������������������\n");
        printf("�� �̱��� �ް��� �ݸ� �λ�� ��ݸ� ���Ӧ�\n");
        printf("��������������������������������������������������������������������������������\n");
        currentMoney -= 20000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2019 && choice == 3) {
        printf("\n                             2019�� 3�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("��  E���� �Ҽ� ���̵��� �ؿܿ����� �������� �α⿡ ���� ��������� ���ߴ�  ��\n");
        printf("�� ���������� �αⰡ  �� ����� ���� ȭ���� ������ �����ϸ� ���� ��� ��� ��\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 30000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2021 && choice == 1) {
        printf("\n                 2021�� 1�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������������������������������\n");
        printf("�� A ���̿�, RSNA�� �׾ƹз��̵����� ���ۿ� �������� ������\n");
        printf("������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 10000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2021 && choice == 2) {
        printf("\n                          2021�� 2�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� A ���̿��� �������̸� ġ������ ������ �� �ƹз��̵� ��ü�� ���� �̱�������\n");
        printf("�� ���ʷ� �����㰡�� ������ �ӻ� ���忡�� ���ǰ� �ִ�.                   ��\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 20000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2021 && choice == 3) {
        printf("\n                        2021�� 3�ܰ� ����\n");
        printf("����������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� C IT ���� �������� ���� �̿��� �漺�� Ȯ���                  ��\n");
        printf("�� ���� ����� ��ȯ ������ �������� ������ ���� ���� ��� 43 % ���妢\n");
        printf("����������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 30000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2023 && choice == 1) {
        printf("\n                      2023�� 1�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� ��Ƽ�� ���� ������ ������ ����Ǵ� '�� ��Ƽ ķ����'�� ������\n");
        printf("������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 10000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2023 && choice == 2) {
        printf("\n                             2023�� 2�ܰ� ����\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� Ÿȸ�� �Ҽ��� ��� ��簡 ���� ��� ������ �����ϴ� �� ����ϴ� ��� �߻���\n");
        printf("������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 20000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else if (year == 2023 && choice == 3) {
        printf("\n                       2023�� 3�ܰ� ����\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("�� �� �������α׷� ���� E ���� �Ҽ� ���̵��� �ٸ� ���̵����� ��ġ��\n");
        printf("�� 1���� ������ �Ű����� ���� ��� 7������ ���.                   ��\n");
        printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
        currentMoney -= 30000;
        printf("\n���� �ں�: %d", currentMoney);
    }
    else {
        printf("�߸��� �Է��Դϴ�");
    }
}