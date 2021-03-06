#include "TXLib.h"
void drawelephant (int x, int y, int r, COLORREF color);   //координаты(начало снизу);размер;цвет
int main()
    {
    txCreateWindow (1200, 800);
    drawelephant (200, 500, 30, RGB (255, 255, 255));
    }
void drawelephant (int x, int y, int r, COLORREF color)
    {
    txSetColor (TX_WHITE, 0.5);
    txSetFillColor (color);
    POINT elephant[4] = {{x, y}, {x , y - 1 * r}, {x + 5 * r, y - 1 * r}, {x + 5 * r, y } };        //подставка
    txEllipse (x - 0.5 * r, y - 2.5 * r, x + 5.5 * r, y - 0.5 * r); //овал у подставки
    POINT elephant1[4] = {{x + 0.1 * r, y - 2.2 * r}, {x + 1.5 * r , y - 6.5 * r}, {x + 3.4 * r, y - 6.5 * r}, {x + 4.8  * r, y - 2.2 * r } }; //тело слона
    txEllipse (x + 1 * r, y - 7.4 * r, x + 3.9 * r,  y - 6.4 * r); //3 овал сверху
    txEllipse (x + 1 * r, y - 10.15 * r, x + 3.9 * r,  y - 7.15 * r); //2 овал сверху
    txEllipse (x + 2 * r, y - 10.65 * r, x + 2.9 * r,  y - 10.1 * r); //1 овал сверху
    txPolygon (elephant, 4);
    txPolygon (elephant1, 4);
    txSetColor (TX_BLACK, 0.085 * r);
    txLine (x + 3.1 * r, y - 10 * r, x + 2.4 * r, y - 8.8 * r);
    txLine (x + 2.4 * r, y - 8.8 * r, x + 2.7 * r, y - 8.65 * r);
    txLine (x + 2.7 * r, y - 8.65 * r, x + 3.359 * r, y - 9.8 * r);
    }
