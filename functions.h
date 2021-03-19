bool off_sound = false;
bool end_game;
HDC bg_pic;
HDC settings_pic;
HDC field_pic;
void add_widgets();
void load_images();
void menu();
void settings();
void on_sound_func();
void off_sound_func();
void start_game();
Button play_button(395, 243, start_game, "Играть", "Road Rage(RUS BY LYAJKA)", 70, 90, 355, RGB(247, 240, 1) , TX_BLACK, false);

Button settings_button(395, 348, settings, "Настройки", "Road Rage(RUS BY LYAJKA)", 70, 90, 355, RGB(247, 240, 1) , TX_BLACK, false); //76, 230, 119
Button on_sound_button(460, 395, on_sound_func, "Вкл", "Road Rage(RUS BY LYAJKA)", 70, 64, 108, RGB(76, 230, 119) , TX_BLACK, false);
Button off_sound_button(570, 395, off_sound_func, "Выкл", "Road Rage(RUS BY LYAJKA)", 70, 64, 115, RGB(230, 76, 76) , TX_BLACK, false);
Button classic_style_button(415, 570, settings, "Classic Style", "Road Rage(RUS BY LYAJKA)", 40, 85, 155, RGB(247, 240, 1) , TX_BLACK, false);
Button cyberpunk_style_button(575, 570, settings, "Cyberpunk Style", "Road Rage(RUS BY LYAJKA)", 30, 85, 158, RGB(247, 240, 1) , TX_BLACK, false);

Button back_button(415, 660, menu, "Назад", "Road Rage(RUS BY LYAJKA)", 70, 90, 318, RGB(247, 240, 1) , TX_BLACK, false);


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
    bg_pic = txLoadImage("Chess_menu.bmp");
    settings_pic = txLoadImage("Chess_settings_menu1.bmp");
    field_pic = txLoadImage("Chess_pic.bmp");
}

void menu(){
    if(!off_sound){
        txPlaySound("bg_music.wav",SND_LOOP);
    }
    on_sound_button.set_state(false);
    off_sound_button.set_state(false);
    classic_style_button.set_state(false);
    cyberpunk_style_button.set_state(false);
    back_button.set_state(false);
    play_button.set_state(true);
    settings_button.set_state(true);
    txBitBlt(txDC(),0,0,1200,800,bg_pic,0,0);
}

void settings(){
    play_button.set_state(false);
    settings_button.set_state(false);
    on_sound_button.set_state(true);
    off_sound_button.set_state(true);
    classic_style_button.set_state(true);
    cyberpunk_style_button.set_state(true);
    back_button.set_state(true);
    txBitBlt(txDC(),0,0,1200,800,settings_pic,0,0);
}

void on_sound_func(){
    off_sound = false;
    txPlaySound("bg_music.wav",SND_ASYNC);
}

void off_sound_func(){
    off_sound = true;
    txPlaySound(NULL);
}

void start_game(){
    play_button.set_state(false);
    if(!field_pic){
        txMessageBox ("Не могу загрузить фон из Chess_pic.bmp");
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
    //txDeleteDC(bg_pic);
    //txDeleteDC(field_pic);
}

