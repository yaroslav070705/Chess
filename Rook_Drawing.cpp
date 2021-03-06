//@author Andrey,
//        Timofey

#include "TXLib.h"

void drawRook (int x, int y, int r, COLORREF color, COLORREF color1);

int main()
{
    txCreateWindow(1000, 800);
    drawRook(50,100,10, RGB(0,0,0), RGB(255,255,255));
}

void drawRook (int x, int y, int r, COLORREF color, COLORREF color1)
{
    txSetColor(color1,2);
    txSetFillColor (color);

    POINT head[12] = {{r+x, (9*r)+y}, {r+x, (4*r)+y}, {(3*r)+x, (4*r)+y}, {(3*r)+x, (7*r)+y }, {(4*r)+x, (7*r)+y}, {(4*r)+x,(5*r)+y}, {(7*r)+x,(5*r)+y}, {(7*r)+x,(7*r)+y}, {(8*r)+x,(7*r)+y}, {(8*r)+x,(4*r)+y},{(10*r)+x,(4*r)+y}, {(10*r)+x,(9*r)+y}}; //"голова", мен€етс€ в зависимости от фигуры
    txPolygon (head, 12);

    POINT neck[4] = {{(2*r)+x, (9*r)+y}, {(9*r)+x,(9*r)+y},{(9*r)+x, (10*r)+y},{(2*r)+x,(10*r)+y}};
    txPolygon (neck, 4);

    POINT body[4] = {{(4*r)+x, (10*r)+y}, {(7*r)+x, (10*r)+y}, {(8*r)+x, (20*r)+y}, {(3*r)+x, (20*r)+y}}; //!неизмен€емое тело
    txPolygon (body, 4);

    POINT stand1[4] = {{(2*r)+x, (20*r)+y}, {(9*r)+x, (20*r)+y}, {(9*r)+x, (21*r)+y}, {(2*r)+x, (21*r)+y}}; //перва€ подставка дл€ всех, а у пешек только она
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(1*r)+x, (21*r)+y}, {(10*r)+x, (21*r)+y}, {(10*r)+x, (22*r)+y}, {(1*r)+x, (22*r)+y}}; //втора€ подставка дл€ средних(ладь€,слон,конь) и лучших
    txPolygon (stand2, 4);

    //POINT stand3[4] = {{(0*r)+x, (22*r)+y}, {(11*r)+x, (22*r)+y}, {(11*r)+x, (23*r)+y}, {(0*r)+x, (23*r)+y}};//треть€ подставка дл€ лучших(ферзей, королей)
   // txPolygon (stand3, 4);
}
