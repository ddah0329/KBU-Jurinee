//main.c
#include "JurineeHeader.h"

//void getCursorPosition(); //���� Ŀ�� ��ġ ��ǥ ���


int main() {
    //col = ����, lines = ����
    system("mode con:cols=80 lines=200"); //�ܼ�â ���� ������ ����

    //GameState state = { 2015, 500000, "None", 1, 0 };

    char simulationText[] = " ���� �ֽ� �ùķ��̼�";
    printTextWithBorder(simulationText);

    printf("\n\n  �� ���� �ֽ� �ùķ��̼� ���α׷��� ���� �ֽİ��� �ٸ� �� ������ �˷��帳�ϴ�.\n\n\n");
    mainHomeMenu();
    
        return 0;
    
}// main ��

