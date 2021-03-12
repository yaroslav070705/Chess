#include "TXLib.h"
#include <iostream>
using namespace std;
int main()
{

    txCreateWindow(1200,800);
    HDC chessdoska= txLoadImage ("Chess_pic.bmp");
    txBitBlt(txDC(),0,0,1200,800,chessdoska,0,0);
    txDeleteDC(chessdoska);
    txSleep(10000);
}


