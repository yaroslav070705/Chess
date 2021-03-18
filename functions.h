bool end_game;

void start_game(){
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
        end_game = field.check_click();
        //field.pawn_to_queen();
        if(end_game){
            break;
        }
        //field.move_figure();

        field.draw();
        txSleep(10);
    }
    field.end(end_game);
    txDeleteDC(bg);
}

