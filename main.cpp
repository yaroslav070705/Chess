#include "TXLib.h"
#include <fstream>
#include "widgets.h"
#include "base_figure.h"
#include "cell.h"
#include "Rook.h"
#include "Queen.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "chess_field.h"
#include "functions.h"

using namespace std;

int main(){
    txCreateWindow(1200,800);
    txBegin();
    read_file();
    add_widgets();
    load_images();
    update_style();
    menu();
    while(!GetAsyncKeyState(VK_ESCAPE)){
        update_widgets();
    }
    //start_game();
    txEnd();
    delete_images();
}
