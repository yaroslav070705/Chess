//@author Timofey

#include "TXLib.h"

void draw_splash_screen(int x, int y);


int main()
{
    txCreateWindow(1000,800);

    txClear();
    int y;
    for(y=800;y>-6000;y-=10)
    {
        txClear();
        draw_splash_screen(0,y);
        txSleep(20);
    }

    draw_splash_screen(0,800);

    return 0;
}

void draw_splash_screen(int x, int y)
{
    txSetFillColor(TX_BLACK);
    txRectangle (-1, -1, 1001, 801);
    txSetColor (RGB (255, 0, 156));
    txSelectFont ("impact", 80, 0, FW_BOLD);
    txDrawText (x+0, y+0, x+1000, y+8000, "КОМПАНИЯ PHISICS AND MATHS ENTERTAINMENT ПРЕДСТАВЛЯЕТ: \n \n \n \n \n \n \n ШАХМАТЫ \n \n \n \n \n \n \n В создании дизайна для этого проекта учавствовали: \n \n \n \n \n \n Арсений Ашурков \n \n \n Андрей Берендеев \n \n \n Артём Кузнецов \n \n \n Тимофей Арсеньев  \n (начальник отдела дизайна) \n \n \n \n \n \n Кодеры: \n \n \n Анна Кузьменкова \n \n \n Роман Кашкин \n \n \n Наталья Иванова \n \n \n Лена Амосова \n \n \n Михаил Кулик \n \n \n Лев Горбушин \n \n \n \n \n \n Cтепан Зызников \n (помогал всем) \n \n \n \n \n \n Ярослав Кучер \n (главный начальник)");

    //txSetColor (RGB (236, 193, 156));
    //txSelectFont ("impact", 80, 0, FW_BOLD);
    //txDrawText (x+0, y+0, x+1000, y+8000, "\n \n \n COMPANY PHISICS AND MATHS ENTERTAINMENT PRESENTS: \n \n \n \n \n \n CHESS \n \n \n \n \n \n \n \n In the creation of the design for this project participated: \n \n \n \n \n \n Arsenyev Timofey (queen, king, titre), \n \n \n \n \n Andrey Berendeev (), \n \n \n Artem Kuznetsov () \n \n \n \n \n Arseny Ashurkov will participate when he gets in the mood.");
}
