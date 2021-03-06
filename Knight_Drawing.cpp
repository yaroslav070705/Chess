//@authors Stepan,
//         Timofey

#include <TXLib.h>

void drawKnight  (int x, int y, int r, COLORREF color, COLORREF color1, COLORREF colorEYES_FOR_BLACK_PUMPKIN, COLORREF colorEYES_FOR_WHITE_FROG_IN_SWOON);

int main()
{
    txCreateWindow (1000, 800);
    drawKnight  (0, 0, 1, RGB(255,255,255), RGB(0,0,0), RGB(255,117,24), RGB(123,145,123));
}

void drawKnight  (int x, int y, int r, COLORREF color, COLORREF color1, COLORREF colorEYES_FOR_BLACK_PUMPKIN, COLORREF colorEYES_FOR_WHITE_FROG_IN_SWOON)
{
    txSetFillColor (color);
    txSetColor (color1, 5*r);

    txSetFillColor (color);
    POINT Knight[14] = {{r *  400  /5 + x, r *  300   /5 + y},     //тело без ушей
                        {r *  300  /5 + x, r *  500   /5 + y},
                        {r *  350 /5 + x, r *  600   /5 + y},
                        {r *  400  /5 + x, r *  600   /5 + y},
                        {r *  500  /5 + x, r *  500   /5 + y},
                        {r *  500  /5 + x, r *  600   /5 + y},
                        {r *  400  /5 + x, r *  750  /5 + y},
                        {r *  400  /5 + x, r *  800   /5 + y},
                        {r *  750 /5 + x, r *  800   /5 + y},
                        {r *  700  /5 + x, r *  550  /5 + y},
                        {r *  650 /5 + x, r *  450  /5 + y},
                        {r *  550 /5 + x, r *  350  /5 + y},
                        {r *  450 /5 + x, r *  300   /5 + y},
                        {r *  400  /5 + x, r *  300   /5 + y}};
    txPolygon  (Knight, 14);

    txSetColor (color, 2*r);
    //txSetFillColor (colorEYES_FOR_BLACK_PUMPKIN);
    txSetFillColor (colorEYES_FOR_WHITE_FROG_IN_SWOON);
    txCircle(425/5*r + x,400/5*r + y,25/5 *r);


    txSetColor (color1, 5*r);
    txSetFillColor (color);
    POINT Ears[7] = {{r *  400  /5 + x, r *  300    /5 + y},      //уши
                     {r *  450 /5 + x, r *  200    /5 + y},
                     {r *  500  /5 + x, r * 325  /5 + y},
                     {r *  550 /5 + x, r *  200    /5 + y},
                     {r *  600  /5 + x, r *  400    /5 + y},
                     {r *  550 /5 + x, r *  350   /5 + y},
                     {r *  450 /5 + x, r *  300    /5 + y}};
    txPolygon  (Ears, 7);

    txSetColor (color1, 2*r);
    txLine (r *  350 /5 + x, r *  600 /5 + y, r *  400 /5 + x, r *  550 /5 + y);    //полоска рта
}
