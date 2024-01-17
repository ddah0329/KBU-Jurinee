//companyFunctions.c
#include "JurineeHeader.h"

// 瞪羲滲熱 : 蟾晦 癱濠旎
int currentMoney = 700000;

// �蜓� 薑爾 蟾晦��
StockCompany companies[] = {
    {"A 夥檜螃", {2015, 2017, 2019, 2021, 2023}, {628293, 325432, 286057, 340969, 293818}},
    {"B 箔じ", {2015, 2017, 2019, 2021, 2023}, {216000, 251500, 143500, 157000, 118500}},
    {"C IT", {2015, 2017, 2019, 2021, 2023}, {92300, 192000, 108500, 440000, 178300}},
    {"D 遴歎", {2015, 2017, 2019, 2021, 2023}, {211000, 139500, 190500, 124000, 81300}},
    {"E 縛攪", {2015, 2017, 2019, 2021, 2023}, {6875, 5000, 12700, 7925, 27500}},
};

// 餌辨濠曖 輿衝 爾嶸 薑爾 蟾晦��
StockHoldings userHoldings[] = {
    {0, 0}, // A 夥檜螃
    {0, 0}, // B 箔じ
    {0, 0}, // C IT
    {0, 0}, // D 遴歎
    {0, 0}  // E 縛攪
};

void myInfo(int companyIndex){
printf("\n式式式 んおィ葬螃 式式式\n");
for (int i = 0; i < 5; i++) {
    printf("%s: 爾嶸 輿衝 熱 = %d 癱濠 旎擋 = %d\n\n", companies[i].name, userHoldings[i].quantity, userHoldings[companyIndex].totalInvestment);
}
printf("\n式式式 ⑷營 濠獄 式式式\n");
printf("⑷營 濠獄: %d", currentMoney);
}

void buyStock(char companySymbol, int year) {
    int quantity;
    printf("\n\n\t\t\t      ﹤﹤﹤﹤﹤﹤﹤\n");
    printf("\t\t\t      ﹤   衙熱   ﹤\n");
    printf("\t\t\t      ﹤﹤﹤﹤﹤﹤﹤\n\n\n\n");

    companyColor();

    printf("\t  衙熱й 輿衝 謙跡擊 摹鷗ж撮蹂 (A-E) : ");
    scanf(" %c", &companySymbol);

    // 僥濠蒂 檣策蝶煎 夥翎 (A=0, B=1, ..., E=4)
    int companyIndex = companySymbol - 'A';

    if (companyIndex < 0 || companyIndex >= 5) {
        printf("嶸�褲� �蜓蝪� 嬴椎棲棻.\n");
        printf("棻衛 衛紫п輿衛望 夥奧棲棻.\n");
        return;
    }

    printf("\t  ⑷營 翱紫蒂 殮溘п輿撮蹂(ex. 2015): ");
    scanf("%d", &year);

    if (companies[companyIndex].year[companyIndex] != year) {
        printf("\t  嶸�褲� 翱紫陛 嬴椎棲棻.\n");
        printf("\t  棻衛 衛紫п輿衛望 夥奧棲棻.\n");
        return;
    }

    printf("\t  %c �蜓蝩� %d喇紫 輿陛蒂 橡葆釭 掘衙ж堅 談戲褐陛蹂?: ", companySymbol, year);
    scanf("%d", &quantity);

    int totalCost = companies[companyIndex].price[year - 2015] * quantity;

    if (totalCost > currentMoney) {
        printf("\t  濠獄檜 睡褶ж罹 掘衙ж雖 跤ж艘蝗棲棻.\n");
        inGameMenu();
    }
    else {
        userHoldings[companyIndex].quantity += quantity;
        userHoldings[companyIndex].totalInvestment += totalCost;
        currentMoney -= totalCost;
        printf("\t  衙熱陛 諫猿腎歷蝗棲棻.\n");
        myInfo(companyIndex);
        system("cls");
        inGameTitle();
    }
}



void sellStock(char companySymbol, int year) {
    int quantity;
    printf("\n\n\t\t\t      ﹤﹤﹤﹤﹤﹤﹤\n");
    printf("\t\t\t      ﹤   衙紫   ﹤\n");
    printf("\t\t\t      ﹤﹤﹤﹤﹤﹤﹤\n\n\n\n");

    companyColor();

    printf("\t  衙紫й 輿衝 謙跡擊 摹鷗ж撮蹂 (A-E) : ");
    scanf(" %c", &companySymbol);

    int companyIndex = companySymbol - 'A';

    if (companyIndex < 0 || companyIndex >= 5) {
        printf("\t  嶸�褲� �蜓蝪� 嬴椎棲棻.\n");
        printf("\t  棻衛 衛紫п輿衛望 夥奧棲棻.\n");
        return;
    }

    printf("\t  ⑷營 翱紫蒂 殮溘п輿撮蹂(ex. 2015): ");
    scanf("%d", &year);

    if (companies[companyIndex].year[companyIndex] != year) {
        printf("\t  嶸�褲� 翱紫陛 嬴椎棲棻.\n");
        printf("\t  棻衛 衛紫п輿衛望 夥奧棲棻.\n");
        return;
    }

    printf("\t  %c �蜓蝩� %d喇紫 輿陛蒂 橡葆釭 つ堅 談戲褐陛蹂?: " , companySymbol, year);
    scanf("\t  %d", &quantity);

    if (quantity > userHoldings[companyIndex].quantity) {
        printf("\t  輿衝 爾嶸榆檜 瞳橫 つ雖 跤ж艘蝗棲棻.\n");
    }
    else {
        int totalRevenue = companies[companyIndex].price[year - 2015] * quantity;
        userHoldings[companyIndex].quantity -= quantity;
        userHoldings[companyIndex].totalInvestment -= totalRevenue;
        currentMoney += totalRevenue;
        printf("\t  紫衙陛 諫猿腎歷蝗棲棻.\n");
        myInfo(companyIndex);
        system("cls");
        inGameTitle();
    }
}


void print2015StockPrices() {
    printf("\n\n\n式式 2015 輿陛 薑爾 式式\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[0]);
    }
    printf("\n");
    }

void print2017StockPrices() {
    printf("\n\n\n式式 2017 輿陛 薑爾 式式\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[1]);
    }
    printf("\n");
}

void print2019StockPrices() {
    printf("\n\n\n式式 2019 輿陛 薑爾 式式\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[2]);
    }
    printf("\n");
}

void print2021StockPrices() {
    printf("\n\n\n式式 2021 輿陛 薑爾 式式\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[3]);
    }
    printf("\n");
}

void print2023StockPrices() {
    printf("\n\n\n式式 2023 輿陛 薑爾 式式\n");
    for (int j = 0; j < 5; j++) {
        printf("%s: %d\n", companies[j].name, companies[j].price[4]);
    }
    printf("\n");
}


void buyNews() {
    int year;
    printf("\n\n\t\t\t  ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤\n");
    printf("\t\t\t  ﹤  薑 爾 剪 楚 模  ﹤\n");
    printf("\t\t\t  ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤\n\n\n\n\n");
    printf("\t    薑爾朝 陝 翱紫渡 1~3欽啗曖 景蝶煎 掘撩腎橫 氈蝗棲棻.");

    printf("橫雯 翱紫曖 橫雯 薑爾蒂 掘衙ж衛啊蝗棲梱?");
    scanf("%d %d", &year, &choice);
    if (year == 2017 && choice == 1) {
        printf("\n                           2017喇 1欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 2017喇 3錯 10橾 11衛 21碟 31蟾’ь營 8渠0 虜濰橾纂 夢斬�� 渠鱔滄 だ賊弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 10000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2017 && choice == 2) {
        printf("\n            2017喇 2欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 E縛攪曖 碟葬 衙陝 陛棟撩 薯晦腎堅 氈棻.弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 20000;
        printf("⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2017 && choice == 3) {
        printf("\n                            2017喇 3欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 A 夥檜螃朝 っ衙 薑骯戲煎  G夥檜螃縑 8050虜 殖楝(и�� 906橘 錳)陛榆擊 雖晝弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 30000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2019 && choice == 1) {
        printf("\n              2019喇 1欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 B 箔じ朝 喬離餌機 睡僥擊 輿衝�蜓� H煎 碟й弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 10000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2019 && choice == 2) {
        printf("\n            2019喇 2欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 嘐措曖 晝問и 旎葬 檣鼻婁 堅旎葬 雖樓弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 20000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2019 && choice == 3) {
        printf("\n                             2019喇 3欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛  E縛攪 模樓 嬴檜給檜 п諼縑憮曖 檣雖紫諦 檣晦縑 綠п 鼻渠瞳戲煎 擒ц湍  弛\n");
        printf("弛 措頂縑憮曖 檣晦陛  и 寞歎擊 鱔п �俯汝� 爾鬼縑 撩奢ж貊 換縑 嗥啪 鼻蝓 弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 30000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2021 && choice == 1) {
        printf("\n                 2021喇 1欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 A 夥檜螃, RSNA憮 о嬴塵煎檜萄薯薯 睡濛辨 艙鼻з瞳 堅雞弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 10000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2021 && choice == 2) {
        printf("\n                          2021喇 2欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 A 夥檜螃陛 憲隴ж檜該 纂猿薯煎 偃嫦и о 嬴塵煎檜萄 о羹陛 螢п 嘐措縑憮弛\n");
        printf("弛 譆蟾煎 衛っъ陛蒂 嫡戲貊 歜鼻 ⑷濰縑憮 餌辨腎堅 氈棻.                   弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 20000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2021 && choice == 3) {
        printf("\n                        2021喇 3欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 C IT 壎矗 夔蘸隴縑 渠и 檜辨濠 醱撩紫 �捎賰�                  弛\n");
        printf("弛 唸薯 餌辨濠 瞪�� 綠徽檜 堪嬴雖貊 衙轎檜 瞪喇 翕晦 渠綠 43 % 撩濰弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 30000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2023 && choice == 1) {
        printf("\n                      2023喇 1欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 箔じ陛 堅偌曖 奢馬婁 霤罹煎 霞ч腎朝 '景 箔じ 譟む檣'擊 瞪偃弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 10000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2023 && choice == 2) {
        printf("\n                             2023喇 2欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 顫�蜓� 模樓曖 寡歎 晦餌陛 億漁 寡歎 機鼠蒂 熱чж湍 醞 餌蜂ж朝 餌堅陛 嫦儅弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 20000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else if (year == 2023 && choice == 3) {
        printf("\n                       2023喇 3欽啗 薑爾\n");
        printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("弛 и 擠學Щ煎斜極 縑憮 E 縛攪 模樓 嬴檜給檜 棻艇 嬴檜給菟擊 薯纂堅弛\n");
        printf("弛 1嬪縑 螃腦貊 褐堊戲煎 擠學 寞歎 7婦諾擊 晦煙.                   弛\n");
        printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        currentMoney -= 30000;
        printf("\n⑷營 濠獄: %d", currentMoney);
    }
    else {
        printf("澀跤脹 殮溘殮棲棻");
    }
}