//companyFunctions.c
#include "JurineeHeader.h"

// Àü¿ªº¯¼ö : ÃÊ±â ÅõÀÚ±Ý
int currentMoney = 700000;

// È¸»ç Á¤º¸ ÃÊ±âÈ­
StockCompany companies[] = {
    {"A ¹ÙÀÌ¿À", {2015, 2017, 2019, 2021, 2023}, {628293, 325432, 286057, 340969, 293818}},
    {"B ºäÆ¼", {2015, 2017, 2019, 2021, 2023}, {216000, 251500, 143500, 157000, 118500}},
    {"C IT", {2015, 2017, 2019, 2021, 2023}, {92300, 192000, 108500, 440000, 178300}},
    {"D ¿î¼Û", {2015, 2017, 2019, 2021, 2023}, {211000, 139500, 190500, 124000, 81300}},
    {"E ¿£ÅÍ", {2015, 2017, 2019, 2021, 2023}, {6875, 5000, 12700, 7925, 27500}},
};

// »ç¿ëÀÚÀÇ ÁÖ½Ä º¸À¯ Á¤º¸ ÃÊ±âÈ­
StockHoldings userHoldings[] = {
    {0, 0}, // A ¹ÙÀÌ¿À
    {0, 0}, // B ºäÆ¼
    {0, 0}, // C IT
    {0, 0}, // D ¿î¼Û
    {0, 0}  // E ¿£ÅÍ
};

void myInfo(int companyIndex){
printf("\n¦¡¦¡¦¡ Æ÷Æ®Æú¸®¿À ¦¡¦¡¦¡\n");
for (int i = 0; i < 5; i++) {
    printf("%s: º¸À¯ ÁÖ½Ä ¼ö = %d ÅõÀÚ ±Ý¾× = %d\n\n", companies[i].name, userHoldings[i].quantity, userHoldings[companyIndex].totalInvestment);
}
printf("\n¦¡¦¡¦¡ ÇöÀç ÀÚº» ¦¡¦¡¦¡\n");
printf("ÇöÀç ÀÚº»: %d", currentMoney);
}

void buyStock(char companySymbol, int year) {
    int quantity;
    printf("\n\n\t\t\t      ¡à¡à¡à¡à¡à¡à¡à\n");
    printf("\t\t\t      ¡à   ¸Å¼ö   ¡à\n");
    printf("\t\t\t      ¡à¡à¡à¡à¡à¡à¡à\n\n\n\n");

    companyColor();

    printf("\t  ¸Å¼öÇÒ ÁÖ½Ä Á¾¸ñÀ» ¼±ÅÃÇÏ¼¼¿ä (A-E) : ");
    scanf(" %c", &companySymbol);

    // ¹®ÀÚ¸¦ ÀÎµ¦½º·Î ¹Ù²Þ (A=0, B=1, ..., E=4)
    int companyIndex = companySymbol - 'A';

    if (companyIndex < 0 || companyIndex >= 5) {
        printf("À¯È¿ÇÑ È¸»ç°¡ ¾Æ´Õ´Ï´Ù.\n");
        printf("´Ù½Ã ½ÃµµÇØÁÖ½Ã±æ ¹Ù¶ø´Ï´Ù.\n");
        return;
    }

    printf("\t  ÇöÀç ¿¬µµ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä(ex. 2015): ");
    scanf("%d", &year);

    if (companies[companyIndex].year[companyIndex] != year) {
        printf("\t  À¯È¿ÇÑ ¿¬µµ°¡ ¾Æ´Õ´Ï´Ù.\n");
        printf("\t  ´Ù½Ã ½ÃµµÇØÁÖ½Ã±æ ¹Ù¶ø´Ï´Ù.\n");
        return;
    }

    printf("\t  %c È¸»çÀÇ %d³âµµ ÁÖ°¡¸¦ ¾ó¸¶³ª ±¸¸ÅÇÏ°í ½ÍÀ¸½Å°¡¿ä?: ", companySymbol, year);
    scanf("%d", &quantity);

    int totalCost = companies[companyIndex].price[year - 2015] * quantity;

    if (totalCost > currentMoney) {
        printf("\t  ÀÚº»ÀÌ ºÎÁ·ÇÏ¿© ±¸¸ÅÇÏÁö ¸øÇÏ¿´½À´Ï´Ù.\n");
        inGameMenu();
    }
    else {
        userHoldings[companyIndex].quantity += quantity;
        userHoldings[companyIndex].totalInvestment += totalCost;
        currentMoney -= totalCost;
        printf("\t  ¸Å¼ö°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù.\n");
        myInfo(companyIndex);
        system("cls");
        inGameTitle();
    }
}



void sellStock(char companySymbol, int year) {
    int quantity;
    printf("\n\n\t\t\t      ¡à¡à¡à¡à¡à¡à¡à\n");
    printf("\t\t\t      ¡à   ¸Åµµ   ¡à\n");
    printf("\t\t\t      ¡à¡à¡à¡à¡à¡à¡à\n\n\n\n");

    companyColor();

    printf("\t  ¸ÅµµÇÒ ÁÖ½Ä Á¾¸ñÀ» ¼±ÅÃÇÏ¼¼¿ä (A-E) : ");
    scanf(" %c", &companySymbol);

    int companyIndex = companySymbol - 'A';

    if (companyIndex < 0 || companyIndex >= 5) {
        printf("\t  À¯È¿ÇÑ È¸»ç°¡ ¾Æ´Õ´Ï´Ù.\n");
        printf("\t  ´Ù½Ã ½ÃµµÇØÁÖ½Ã±æ ¹Ù¶ø´Ï´Ù.\n");
        return;
    }

    printf("\t  ÇöÀç ¿¬µµ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä(ex. 2015): ");
    scanf("%d", &year);

    if (companies[companyIndex].year[companyIndex] != year) {
        printf("\t  À¯È¿ÇÑ ¿¬µµ°¡ ¾Æ´Õ´Ï´Ù.\n");
        printf("\t  ´Ù½Ã ½ÃµµÇØÁÖ½Ã±æ ¹Ù¶ø´Ï´Ù.\n");
        return;
    }

    printf("\t  %c È¸»çÀÇ %d³âµµ ÁÖ°¡¸¦ ¾ó¸¶³ª ÆÈ°í ½ÍÀ¸½Å°¡¿ä?: " , companySymbol, year);
    scanf("\t  %d", &quantity);

    if (quantity > userHoldings[companyIndex].quantity) {
        printf("\t  ÁÖ½Ä º¸À¯·®ÀÌ Àû¾î ÆÈÁö ¸øÇÏ¿´½À´Ï´Ù.\n");
    }
    else {
        int totalRevenue = companies[companyIndex].price[year - 2015] * quantity;
        userHoldings[companyIndex].quantity -= quantity;
        userHoldings[companyIndex].totalInvestment -= totalRevenue;
        currentMoney += totalRevenue;
        printf("\t  µµ¸Å°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù.\n");
        myInfo(companyIndex);
        system("cls");
        inGameTitle();
    }
}


void print2015StockPrices() {
    printf("\n\n\n¦¡¦¡ 2015 ÁÖ°¡ Á¤º¸ ¦¡¦¡\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[0]);
    }
    printf("\n");
    }

void print2017StockPrices() {
    printf("\n\n\n¦¡¦¡ 2017 ÁÖ°¡ Á¤º¸ ¦¡¦¡\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[1]);
    }
    printf("\n");
}

void print2019StockPrices() {
    printf("\n\n\n¦¡¦¡ 2019 ÁÖ°¡ Á¤º¸ ¦¡¦¡\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[2]);
    }
    printf("\n");
}

void print2021StockPrices() {
    printf("\n\n\n¦¡¦¡ 2021 ÁÖ°¡ Á¤º¸ ¦¡¦¡\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[3]);
    }
    printf("\n");
}

void print2023StockPrices() {
    printf("\n\n\n¦¡¦¡ 2023 ÁÖ°¡ Á¤º¸ ¦¡¦¡\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[4]);
    }
    printf("\n");
}


void buyNews() {
    int year;
    printf("\n\n\t\t\t  ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n");
    printf("\t\t\t  ¡à  Á¤ º¸ °Å ·¡ ¼Ò  ¡à\n");
    printf("\t\t\t  ¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n\n\n\n\n");
    printf("\t    Á¤º¸´Â °¢ ¿¬µµ´ç 1~3´Ü°èÀÇ ´º½º·Î ±¸¼ºµÇ¾î ÀÖ½À´Ï´Ù.");

    printf("¾î¶² ¿¬µµÀÇ ¾î¶² Á¤º¸¸¦ ±¸¸ÅÇÏ½Ã°Ú½À´Ï±î?");
    scanf("%d %d", &year, &choice);
    if (year == 2017 && choice == 1) {
        printf("\n                           2017³â 1´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ 2017³â 3¿ù 10ÀÏ 11½Ã 21ºÐ 31ÃÊ¡¦ÇåÀç 8´ë0 ¸¸ÀåÀÏÄ¡ ¹Ú±ÙÇý ´ëÅë·É ÆÄ¸é¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 10000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2017 && choice == 2) {
        printf("\n            2017³â 2´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ E¿£ÅÍÀÇ ºÐ¸® ¸Å°¢ °¡´É¼º Á¦±âµÇ°í ÀÖ´Ù.¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 20000;
        printf("ÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2017 && choice == 3) {
        printf("\n                            2017³â 3´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ A ¹ÙÀÌ¿À´Â ÆÇ¸Å Á¤»êÀ¸·Î  G¹ÙÀÌ¿À¿¡ 8050¸¸ ´Þ·¯(ÇÑÈ­ 906¾ï ¿ø)°¡·®À» Áö±Þ¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 30000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2019 && choice == 1) {
        printf("\n              2019³â 1´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ B ºäÆ¼´Â ³ìÂ÷»ç¾÷ ºÎ¹®À» ÁÖ½ÄÈ¸»ç H·Î ºÐÇÒ¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 10000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2019 && choice == 2) {
        printf("\n            2019³â 2´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ ¹Ì±¹ÀÇ ±Þ°ÝÇÑ ±Ý¸® ÀÎ»ó°ú °í±Ý¸® Áö¼Ó¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 20000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2019 && choice == 3) {
        printf("\n                             2019³â 3´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢  E¿£ÅÍ ¼Ò¼Ó ¾ÆÀÌµ¹ÀÌ ÇØ¿Ü¿¡¼­ÀÇ ÀÎÁöµµ¿Í ÀÎ±â¿¡ ºñÇØ »ó´ëÀûÀ¸·Î ¾àÇß´ø  ¦¢\n");
        printf("¦¢ ±¹³»¿¡¼­ÀÇ ÀÎ±â°¡  ÇÑ ¹æ¼ÛÀ» ÅëÇØ È­Á¦¼º º¸°­¿¡ ¼º°øÇÏ¸ç ´«¿¡ ¶ç°Ô »ó½Â ¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 30000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2021 && choice == 1) {
        printf("\n                 2021³â 1´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ A ¹ÙÀÌ¿À, RSNA¼­ Ç×¾Æ¹Ð·ÎÀÌµåÁ¦Á¦ ºÎÀÛ¿ë ¿µ»óÇÐÀû °íÂû¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 10000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2021 && choice == 2) {
        printf("\n                          2021³â 2´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ A ¹ÙÀÌ¿À°¡ ¾ËÃ÷ÇÏÀÌ¸Ó Ä¡·áÁ¦·Î °³¹ßÇÑ Ç× ¾Æ¹Ð·ÎÀÌµå Ç×Ã¼°¡ ¿ÃÇØ ¹Ì±¹¿¡¼­¦¢\n");
        printf("¦¢ ÃÖÃÊ·Î ½ÃÆÇÇã°¡¸¦ ¹ÞÀ¸¸ç ÀÓ»ó ÇöÀå¿¡¼­ »ç¿ëµÇ°í ÀÖ´Ù.                   ¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 20000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2021 && choice == 3) {
        printf("\n                        2021³â 3´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ C IT À¥Å÷ ÄÜÅÙÃ÷¿¡ ´ëÇÑ ÀÌ¿ëÀÚ Ãæ¼ºµµ È®´ë·Î                  ¦¢\n");
        printf("¦¢ °áÁ¦ »ç¿ëÀÚ ÀüÈ¯ ºñÀ²ÀÌ ³ô¾ÆÁö¸ç ¸ÅÃâÀÌ Àü³â µ¿±â ´ëºñ 43 % ¼ºÀå¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 30000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2023 && choice == 1) {
        printf("\n                      2023³â 1´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ ºäÆ¼°¡ °í°´ÀÇ °ø°¨°ú Âü¿©·Î ÁøÇàµÇ´Â '´º ºäÆ¼ Ä·ÆäÀÎ'À» Àü°³¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 10000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2023 && choice == 2) {
        printf("\n                             2023³â 2´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ Å¸È¸»ç ¼Ò¼ÓÀÇ ¹è¼Û ±â»ç°¡ »õº® ¹è¼Û ¾÷¹«¸¦ ¼öÇàÇÏ´ø Áß »ç¸ÁÇÏ´Â »ç°í°¡ ¹ß»ý¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 20000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else if (year == 2023 && choice == 3) {
        printf("\n                       2023³â 3´Ü°è Á¤º¸\n");
        printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
        printf("¦¢ ÇÑ À½¾ÇÇÁ·Î±×·¥ ¿¡¼­ E ¿£ÅÍ ¼Ò¼Ó ¾ÆÀÌµ¹ÀÌ ´Ù¸¥ ¾ÆÀÌµ¹µéÀ» Á¦Ä¡°í¦¢\n");
        printf("¦¢ 1À§¿¡ ¿À¸£¸ç ½Å°îÀ¸·Î À½¾Ç ¹æ¼Û 7°ü¿ÕÀ» ±â·Ï.                   ¦¢\n");
        printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
        currentMoney -= 30000;
        printf("\nÇöÀç ÀÚº»: %d", currentMoney);
    }
    else {
        printf("Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù");
    }
}