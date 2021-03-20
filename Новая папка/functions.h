bool off_sound = false;
bool end_game;
int style = 1;
HDC bg_pic_cyberpunk;
HDC settings_pic_cyberpunk;
HDC bg_pic_classic;
HDC settings_pic_classic;
HDC field_pic;
void write_file(string button_name);
void read_file();
void update_style();


void drawKingZast (int x, int y, int r);
void drawQueenZast (int x, int y, int r);
void classic_loading();
void cyberpunk_loading();

void add_widgets();
void load_images();
void delete_images();
void menu();
void settings();
void on_sound_func();
void off_sound_func();
void classic_style_button_func();
void cyberpunk_style_button_func();
void start_game();
Button play_button(395, 250, start_game, "Играть", "Niagara Engraved", 70, 90, 355, RGB(247, 240, 1) , TX_BLACK, false);

Button settings_button(395, 350, settings, "Настройки", "Niagara Engraved", 70, 90, 355, RGB(247, 240, 1) , TX_BLACK, false); //76, 230, 119
Button on_sound_button(460, 395, on_sound_func, "Вкл", "Niagara Engraved", 70, 64, 108, RGB(76, 230, 119) , TX_BLACK, false);
Button off_sound_button(570, 395, off_sound_func, "Выкл", "Niagara Engraved", 50, 64, 115, RGB(230, 76, 76) , TX_BLACK, false);
Button classic_style_button(415, 570, classic_style_button_func, "Classic Style", "Niagara Engraved", 20, 85, 155, RGB(247, 240, 1) , TX_BLACK, false);
Button cyberpunk_style_button(575, 570, cyberpunk_style_button_func, "Cyberpunk Style", "Niagara Engraved", 20, 85, 158, RGB(247, 240, 1) , TX_BLACK, false);

Button back_button(415, 660, menu, "Назад", "Road Rage(RUS BY LYAJKA)", 70, 90, 318, RGB(247, 240, 1) , TX_BLACK, false);

void write_file(string button_name){
    //if(ifstream file("style_file.txt")){
    ofstream file("style_file.txt", ios_base::out);
    if(button_name == "classic_style_button"){
        file<< 2;
        style = 2;
    }
    else if(button_name == "cyberpunk_style_button"){
        file<< 1;
        style = 1;
    }
    update_style();
    file.close();
}

void read_file(){
    ifstream file("style_file.txt");
    file>>style;
    file.close();
}
void update_style(){
    txClear();
    if(style == 2){
        for(auto button:buttons){
            button->set_bg_color(RGB(30,144,255));
        }
        play_button.set_y(350);
        settings_button.set_y(450);
        on_sound_button.set_y(425);
        off_sound_button.set_y(425);

        txBitBlt(txDC(),0,0,1200,800,settings_pic_classic,0,0);
    }
    else{
        for(auto button:buttons){
            button->set_bg_color(RGB(247, 240, 1));
        }
        play_button.set_y(250);
        settings_button.set_y(350);
        on_sound_button.set_y(395);
        off_sound_button.set_y(395);
        txBitBlt(txDC(),0,0,1200,800,settings_pic_cyberpunk,0,0);
    }

}


void classic_loading() {
    //txCreateWindow(1200, 800);
    txSetFillColor(RGB(30,144,255));
    txClear();
    int t = 500, x = 150, y = 500;
    drawKingZast(320, 130, 5);
    drawQueenZast(720, 130, 10);
    txSetColor(TX_WHITE, 4);

    txSleep(t);  //C
    txLine(x, y, x, y + 200);
    txSleep(t);
    txLine(x, y, x + 100, y);
    txLine(x, y + 200, x + 100, y + 200);
    txSetColor(TX_WHITE, 20);
    txLine(150, 400, 350, 400);
    txSetColor(TX_WHITE, 4);

    txSleep(t);  //H
    txLine(x + 200, y, x + 200, y + 200);
    txSleep(t);
    txLine(x + 200, y + 100, x + 300, y + 100);
    txLine(x + 300, y, x + 300, y + 200);
    txSetColor(TX_WHITE, 20);
    txLine(350, 400, 550, 400);
    txSetColor(TX_WHITE, 4);

    txSleep(t);  //E
    txLine(x + 400, y, x + 400, y + 200);
    txSleep(t);
    txLine(x + 400, y, x + 500, y);
    txLine(x + 400, y + 100, x + 500, y + 100);
    txLine(x + 400, y + 200, x + 500, y + 200);
    txSetColor(TX_WHITE, 20);
    txLine(550, 400, 650, 400);
    txSetColor(TX_WHITE, 4);

    txSleep(t);  //S1
    txLine(x + 600, y, x + 600, y + 100);
    txLine(x + 700, y + 100, x + 700, y + 200);
    txSleep(t);
    txLine(x + 600, y, x + 700, y);
    txLine(x + 600, y + 100, x + 700, y + 100);
    txLine(x + 600, y + 200, x + 700, y + 200);
    txSetColor(TX_WHITE, 20);
    txLine(650, 400, 850, 400);
    txSetColor(TX_WHITE, 4);

    txSleep(t);  //S2
    txLine(x + 800, y, x + 800, y + 100);
    txLine(x + 900, y + 100, x + 900, y + 200);
    txSleep(t);
    txLine(x + 800, y, x + 900, y);
    txLine(x + 800, y + 100, x + 900, y + 100);
    txLine(x + 800, y + 200, x + 900, y + 200);
    txSetColor(TX_WHITE, 20);
    txLine(850, 400, 1050, 400);
    txSetColor(TX_WHITE, 4);
}
void drawKingZast (int x, int y, int r){
    txSetColor(TX_BLACK,2);
    txSetFillColor (RGB (255, 215, 0)); //золото для короны

    POINT headtop[25] = {{(6*r)+x, (0*r)+y}, {(7*r)+x, (6*r)+y}, {(8*r)+x, (0*r)+y},
                     {(9*r)+x, (6*r)+y}, {(10*r)+x, (0*r)+y}, {(11*r)+x, (6*r)+y},
                     {(12*r)+x, (0*r)+y}, {(13*r)+x, (6*r)+y}, {(14*r)+x, (0*r)+y},
                     {(15*r)+x, (6*r)+y}, {(16*r)+x, (0*r)+y}, {(16*r)+x, (8*r)+y},
                     {(14*r)+x, (8*r)+y}, {(12*r)+x, (18*r)+y}, {(13*r)+x, (18*r)+y},
                     {(13*r)+x, (19*r)+y}, {(14*r)+x, (19*r)+y}, {(14*r)+x, (20*r)+y},
                     {(8*r)+x, (20*r)+y}, {(8*r)+x, (19*r)+y}, {(9*r)+x, (19*r)+y},
                     {(9*r)+x, (18*r)+y}, {(10*r)+x, (18*r)+y}, {(8*r)+x, (8*r)+y}, {(6*r)+x, (8*r)+y}}; //"голова", меняется в зависимости от фигуры
    txPolygon (headtop, 25);

    txSetFillColor (RGB (255, 255, 255)); //основной цвет (белый)

    POINT body[4] = {{(10*r)+x, (20*r)+y}, {(12*r)+x, (20*r)+y}, {(16*r)+x, (40*r)+y}, {(6*r)+x, (40*r)+y}}; //неизменяемое тело
    txPolygon (body, 4);

    POINT stand1[4] = {{(4*r)+x, (40*r)+y}, {(18*r)+x, (40*r)+y}, {(18*r)+x, (42*r)+y}, {(4*r)+x, (42*r)+y}}; //первая подставка для всех, а у пешек только она
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(2*r)+x, (42*r)+y}, {(20*r)+x, (42*r)+y}, {(20*r)+x, (44*r)+y}, {(2*r)+x, (44*r)+y}}; //вторая подставка для средних(ладья,слон,конь) и лучших
    txPolygon (stand2, 4);

    POINT stand3[4] = {{(0*r)+x, (44*r)+y}, {(22*r)+x, (44*r)+y}, {(22*r)+x, (46*r)+y}, {(0*r)+x, (46*r)+y}};//третья подставка для лучших(ферзей, королей)
    txPolygon (stand3, 4);
}
void drawQueenZast (int x, int y, int r){
    txSetColor(TX_BLACK,2);
    txSetFillColor (RGB (255, 215, 0));

    POINT head[24] = {{((5)*r)+x, ((0)*r)+y}, {((6)*r)+x, ((0)*r)+y}, {((6)*r)+x, ((1)*r)+y},
                      {((7)*r)+x, ((1)*r)+y}, {((7)*r)+x, ((2)*r)+y}, {((6)*r)+x, ((2)*r)+y},
                      {((6)*r)+x, ((4)*r)+y}, {((8)*r)+x, ((4)*r)+y}, {((6)*r)+x, ((5)*r)+y},
                      {((6)*r)+x, ((6)*r)+y}, {((7)*r)+x, ((6)*r)+y}, {((7)*r)+x, ((8)*r)+y},
                      {((6)*r)+x, ((10)*r)+y}, {((5)*r)+x, ((10)*r)+y}, {((4)*r)+x, ((8)*r)+y},
                      {((4)*r)+x, ((6)*r)+y}, {((5)*r)+x, ((6)*r)+y}, {((5)*r)+x, ((5)*r)+y},
                      {((3)*r)+x, ((4)*r)+y}, {((5)*r)+x, ((4)*r)+y}, {((5)*r)+x, ((2)*r)+y},
                      {((4)*r)+x, ((2)*r)+y}, {((4)*r)+x, ((1)*r)+y}, {((5)*r)+x, ((1)*r)+y}}; //"голова", меняется в зависимости от фигуры
    txPolygon (head, 24);

    txSetFillColor (TX_WHITE);

    POINT body[4] = {{(5*r)+x, (10*r)+y}, {(6*r)+x, (10*r)+y}, {(8*r)+x, (20*r)+y}, {(3*r)+x, (20*r)+y}}; //неизменяемое тело
    txPolygon (body, 4);

    POINT stand1[4] = {{(2*r)+x, (20*r)+y}, {(9*r)+x, (20*r)+y}, {(9*r)+x, (21*r)+y}, {(2*r)+x, (21*r)+y}}; //первая подставка для всех, а у пешек только она
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(1*r)+x, (21*r)+y}, {(10*r)+x, (21*r)+y}, {(10*r)+x, (22*r)+y}, {(1*r)+x, (22*r)+y}}; //вторая подставка для средних(ладья,слон,конь) и лучших
    txPolygon (stand2, 4);

    POINT stand3[4] = {{(0*r)+x, (22*r)+y}, {(11*r)+x, (22*r)+y}, {(11*r)+x, (23*r)+y}, {(0*r)+x, (23*r)+y}};//третья подставка для лучших(ферзей, королей)
    txPolygon (stand3, 4);
}

void cyberpunk_loading(){
    int x = 4800;
    int t =280;
    if(!off_sound){
        txPlaySound("cyberpunk_2077_music_trailer_320kbps.wav", SND_ASYNC);
    }
    //txCreateWindow(1200,800);
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
        if(i==t)
            txBitBlt (txDC(), 0, 0, 4800, 800, logo , 0, 0);
        if(GetAsyncKeyState(VK_SPACE))
        {
             txPlaySound(NULL);
            txBitBlt (txDC(), 0, 0, 4800, 800, logo , 0, 0);
            break;
        }

        txSleep(80);
    }

    txDeleteDC (zastavka);
    txDeleteDC (logo);
}

void add_widgets(){
    buttons.push_back(&play_button);
    buttons.push_back(&settings_button);
    buttons.push_back(&on_sound_button);
    buttons.push_back(&off_sound_button);
    buttons.push_back(&classic_style_button);
    buttons.push_back(&cyberpunk_style_button);
    buttons.push_back(&back_button);
}

void load_images(){
    bg_pic_cyberpunk = txLoadImage("Chess_menu1.bmp");
    settings_pic_cyberpunk = txLoadImage("Chess_settings_menu1.bmp");
    field_pic = txLoadImage("Chess_pic.bmp");
    bg_pic_classic = txLoadImage("Chess_menu2.bmp");
    settings_pic_classic = txLoadImage("Chess_settings_menu2.bmp");
}
void delete_images(){
    txDeleteDC(bg_pic_cyberpunk);
    txDeleteDC(field_pic);
    txDeleteDC(settings_pic_cyberpunk);
    txDeleteDC(bg_pic_classic);
    txDeleteDC(settings_pic_classic);
}

void menu(){
   /* if(!off_sound){
        txPlaySound("bg_music.wav",SND_LOOP);
    } */
    on_sound_button.set_state(false);
    off_sound_button.set_state(false);
    classic_style_button.set_state(false);
    cyberpunk_style_button.set_state(false);
    back_button.set_state(false);
    play_button.set_state(true);
    settings_button.set_state(true);
    if(style == 1){
        txBitBlt(txDC(),0,0,1200,800,bg_pic_cyberpunk,0,0);
    }
    else{
        txBitBlt(txDC(),0,0,1200,800,bg_pic_classic,0,0);
    }
}

void settings(){
    play_button.set_state(false);
    settings_button.set_state(false);
    on_sound_button.set_state(true);
    off_sound_button.set_state(true);
    classic_style_button.set_state(true);
    cyberpunk_style_button.set_state(true);
    back_button.set_state(true);
    if(style == 1){
        txBitBlt(txDC(),0,0,1200,800,settings_pic_cyberpunk,0,0);
    }
    else{
        txBitBlt(txDC(),0,0,1200,800,settings_pic_classic,0,0);
    }
}

void on_sound_func(){
    off_sound = false;
    txPlaySound("bg_music.wav",SND_ASYNC);
}

void off_sound_func(){
    off_sound = true;
    txPlaySound(NULL);
}

void classic_style_button_func(){
    write_file("classic_style_button");
}
void cyberpunk_style_button_func(){
    write_file("cyberpunk_style_button");
}

void start_game(){
    play_button.set_state(false);
    if(!field_pic){
        txMessageBox ("Не могу загрузить фон из Chess_pic.bmp");
    }
    if(style == 2){
        classic_loading();
    }
    else{
        cyberpunk_loading();
    }
    ChessField field;
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE)){
        //txSetFillColor(RGB(3, 171, 255));
        txClear();
        txBitBlt(txDC(),0,0,1200,800,field_pic,0,0);
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
    menu();
    //txDeleteDC(bg_pic);
    //txDeleteDC(field_pic);
}

