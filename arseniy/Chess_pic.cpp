#include "TXLib.h"
// @author Arseniy
// @support Arsenyev
//shiza
int main()
{
    txCreateWindow(1200,800);
    HDC arseniy = txLoadImage ("Chess_pic.bmp");
    if (!arseniy)
    {
        txMessageBox ("Chumba ti sovsem?");
    }
    txBitBlt (txDC(), 0, 0, 1200, 800, arseniy, 0, 0);
    txDeleteDC (arseniy);
}
