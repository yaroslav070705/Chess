#include "TXLib.h"
#include <iostream>
#include <windows.h>   //попытка разобраться со звуком
using namespace std;
// @author Arseniy
int main()
{
    int x = 4800;
    int t = 103;
    txCreateWindow(1200,800);
    HDC zastavka = txLoadImage ("Chess_zastavka.bmp");
    HDC logo = txLoadImage ("Сhess_logo.bmp");
    if (!zastavka)
    {
        txMessageBox ("Chumba ti sovsem?");
    }
        if (!logo)
    {
        txMessageBox ("Chumba ti sovsem?");
    }
    for(int i=0; i<=t; i++)
    {
            txBitBlt (txDC(), x, 0, 4800, 800, zastavka , 0, 0);            //не объяснимо, но работает
            x = x-1200;
        if(x==-4800)
            x=0;
        if(i==103)
            txBitBlt (txDC(), 0, 0, 4800, 800, logo , 0, 0);
        if(GetAsyncKeyState(VK_SPACE))
        {
            txBitBlt (txDC(), 0, 0, 4800, 800, logo , 0, 0);
            break;
        }

        txSleep(80);
    }

    txDeleteDC (zastavka);
    txDeleteDC (logo);
}
      //сдохни, но сделай
