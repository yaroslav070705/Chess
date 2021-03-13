#include "TXLib.h"
#include "base_figure.h"
#include "cell.h"
#include "Rook.h"
#include "Queen.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "chess_field.h"

using namespace std;

int main(){
    txCreateWindow(1200,800);
    HDC bg = txLoadImage("Chess_pic.bmp");
    if(!bg){
        txMessageBox ("Не могу загрузить фон из Chess_pic.bmp");
    }
    ChessField field;
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE)){
        //txSetFillColor(RGB(3, 171, 255));
        txClear();
        txBitBlt(txDC(),0,0,1200,800,bg,0,0);
        field.check_click();
        //field.move_figure();

        field.draw();
        txSleep(10);
    }
    txDeleteDC(bg);
    txEnd();

}
