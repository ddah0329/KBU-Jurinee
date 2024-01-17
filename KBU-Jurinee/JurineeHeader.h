#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 전역변수 : scanf
int choice;

int companyIndex;

// 회사 정보를 담는 구조체
typedef struct {
    const char* name;
    int year[5];
    int price[5];
} StockCompany;

// 주식 보유 정보를 담는 구조체
typedef struct {
    int quantity;
    int totalInvestment;
} StockHoldings;


// companyFunctions.c
#ifndef COMPANY_FUNCTIONS_H
#define COMPANY_FUNCTIONS_H

void myInfo(companyIndex);
void sellStock(int companyIndex);
void buyStock(int companyIndex);
void print2015StockPrices();
void print2017StockPrices();
void print2019StockPrices();
void print2021StockPrices();
void print2023StockPrices();

#endif


// timer.h
#ifndef TIMER_H
#define TIMER_H

void timer5MINS();

#endif

// graph.h

#ifndef GRAPH_H
#define GRAPH_H

void printValueAndDot(double value, int spaces);
void printLineWithNumbers(int start, int end);
void year2015();
void year2017();
void year2019();
void year2021();
void year2023();
#endif


// titleFunctions.h
#ifndef TITLE_FUNCTIONS_H
#define TITLE_FUNCTIONS_H

void mainHomeMenu();
void printBorder(int width);
void printTextWithBorder(char* text);
void showInstructions();

typedef struct user {
    char name[50];
    int amount;
} USER;

void saveToUserRanking(const char* filename, const USER* user);
void printUserRanking(const char* filename);
void getUserInput(USER* user);

/*
void displayStatus(GameState* state);
void buyNews(GameState* state);
void nextYear(GameState* state);
void skipTime(GameState* state);
*/

#endif

// inGameFunctions.h

#ifndef IN_GAME_FUNCTIONS_H
#define IN_GAME_FUNCTIONS_H

void inGameMenu();
void inGameTitle();
void displayGraph();
void showInstructions();
void companyColor();

#endif



// publicFunctions.h

#ifndef PUBLIC_FUNCTIONS_H
#define PUBLIC_FUNCTIONS_H

//color
enum {
    BLACK, DARK_BLUE, DARK_GREEN, DARK_SKYBLUE, DARK_RED, DARK_VIOLET, DARK_YELLOW, GRAY,
    DARK_GRAY, BLUE, GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE,
};

// Function declaration
void setColor(unsigned short text);
void getCursorPosition();
#endif


// sound.h
#ifndef SOUND_H
#define SOUND_H

//void playSound(const char* fileName);

#endif // SOUND_H

//--------파일 입출력 구조체--------------------
//#ifndef HEADER_H
//#define HEADER_H



//#endif