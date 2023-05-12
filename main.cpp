#include "TXLib.h"

struct Forma
{
    string text_question;
    string text_answer1;
    string text_answer2;
    string text_answer3;
};

void drawAnswer(int y, string text_answer)
{
    txSelectFont("Times New Roman", 40);
    txSetColor(TX_WHITE, 7);
    txRectangle(50, 400, 90, 440);
    txDrawText(100,400, 800, 450, text_answer.c_str());
}

int main()
{
txCreateWindow (800, 600);

    Forma quest;

    Forma quest1 = {"какой стан длится дольше?","primal roar","sacred arrow","ice path"};

    Forma quest2 = {"коково максимальное кол-во эффектов,\n способности corrosive weapory?","8","9","11"};

    int n_question = 1;
    int kol_question = 2;

    while(n_question <= kol_question or !GetAsyncKeyState (VK_ESCAPE))
    {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear();
        txBegin();

        if(n_question == 1) quest = quest1;

        else if(n_question == 2) quest = quest2;

        //ШАБЛОН
        txSetColor (TX_WHITE);
        txSetFillColor (TX_TRANSPARENT);
        txRectangle (10, 10, 790, 590);
        //Номер и количество вопросов
        char str[50];
        sprintf(str, "Вопрос %d/%d", n_question, kol_question);
        txDrawText(0, 20, 800, 50, str);
        //Вопрос
        txSelectFont("Times New Roman", 40);
        txDrawText(0, 50, 800, 250, quest.text_question.c_str());
        //Ответы
        txSelectFont("Times New Roman", 40);
        txRectangle(50, 400, 90, 440);
        txDrawText(100,390, 300, 450, quest.text_answer1.c_str());
        txRectangle (50, 450, 90, 490);
        txDrawText(100,440, 300, 500, quest.text_answer2.c_str());
        txRectangle (50, 500, 90, 540);
        txDrawText(100, 490, 300, 550, quest.text_answer3.c_str());

        if( txMouseButtons() == 1 &&
            txMouseX() > 50 && txMouseX() < 250 &&
            txMouseY() > 320 && txMouseY() < 470)
        {
            txSleep(200);
            n_question++;
        }

        if( txMouseButtons() == 1 &&
            txMouseX() > 300 && txMouseX() < 500 &&
            txMouseY() > 320 && txMouseY() < 470)
        {
            txSleep(200);
            n_question++;
        }

        if( txMouseButtons() == 1 &&
            txMouseX() > 550 && txMouseX() < 750 &&
            txMouseY() > 320 && txMouseY() < 470)
        {
            txSleep(200);
            n_question++;
        }
        txEnd();
        txSleep(20);
    }

txTextCursor (false);
return 0;
}
