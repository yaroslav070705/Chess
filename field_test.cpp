#include "TXLib.h"
#include "base_figure.h"
#include "cell.h"
#include "Rook.h"
#include "chess_field.h"

using namespace std;

int main(){
    ChessField field;
    field._add_figures();
    txCreateWindow(1200,800);
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE)){
        txSetFillColor(RGB(3, 171, 255));
        txClear();
        field.check_click();
        field.draw();
        txSleep(10);
    }
    txEnd();

}
