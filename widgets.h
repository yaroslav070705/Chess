#include <iostream>
#include "string"
#include <vector>
using namespace std;

class Button{

public:
    int x;
    int y;
    int height;
    int width;
    bool state ;
    double font_height;
    void(*command)();
    const char  *text;
    const char *font;
    COLORREF bg;
    COLORREF tg;
    bool mouse_on = false;
    Button(int x,
            int y,
            void(*command)(),
            const char  *text = "",
            const char *font = "",
            double font_height = 10,
            int height = 40,
            int width = 100,
            COLORREF bg= TX_BLACK,
            COLORREF tg = TX_BLACK,
            bool state = true )
    {
        this -> x = x;
        this -> y = y;
        this -> height = height;
        this -> width = width;
        this -> font_height = font_height;
        this -> command = command;
        this -> text = text;
        this -> font = font;
        this -> bg = bg;
        this -> tg = tg;
        this->state = state;
    }
    void check_mouse_on(){
        if(txMouseY() >= y && txMouseY() <=y+height && txMouseX() >=x && txMouseX() <=x+width){
            mouse_on = true;
        }
        else{
            mouse_on = false;
        }
    }
    bool check_click(){
        if(txMouseButtons() & 1 && mouse_on){
            return true;

        }
        return false;
    }
    void do_comand() {
        (*command)();

    }
    void place(){
        //txSetFillColor(bg);
        txSelectFont(font,font_height);
        if(mouse_on == false){
            txSetColor(tg,3);
            txSetFillColor(bg);
            txRectangle(x,y,x+width,y+height);
            txSetColor(tg);
            txDrawText(x+1,y+1,x+width-1,y+height-1,text);
        }
        if(mouse_on == true){
            txSetColor(TX_GRAY,3);
            txSetFillColor(bg);
            txRectangle(x,y,x+width,y+height);
            txSetColor(tg);
            txDrawText(x+1,y+1,x+width-1,y+height-1,text);
        }

    }

    bool get_state() {
        return state;
    }

    void set_state(bool state) {
        this->state = state;
    }

    void set_function(void(*command)()) {
        this->command = command;
    }

    void set_x(int x) {
        this->x = x;
    }
    void set_y(int y) {
        this->y = y;
    }

    void set_bg_color(COLORREF bg){
        this->bg = bg;
    }
};



class Entry{
    int i = 1;
    int word_width = 0;
    int trash;
public:
    int x;
    int y;
    int height;
    int width;
    bool state;
    char* value = new char[100];
    bool focus = false;
    Entry(int x,int y,int height,int width, bool state = true ){
        value[0] = '\0';

        this -> x = x;
        this -> y = y;
        this -> height = height;
        this -> width = width;
        this->state = state;
    }

    void place(){
        txSetFillColor(TX_WHITE);
        txSetColor(TX_BLACK,3);
        txRectangle(x,y,x+width,y+height);
        if(strlen(value) != 0){
            txSetColor(TX_BLACK,50);
            txSelectFont ("Consolas", 40);
            txTextOut(x+6,y+3,value);
            //x+6+word_width,y+height-6,
        }
        if(focus && i < 30 && i > 20){
            i = i+1;
            txSetColor(TX_BLACK,2);
            if(x+6+word_width<x+6+width){
                txLine(x+8+word_width,y+6,x+8+word_width,y+height-6);
            }
            else{
                txLine(x+width-6,y+6,x+width-6,y+height-6);
            }
        }
        else if (i==30){
            i = 1;
        }
        else{
            i = i+1;
        }
    }

    void check_focus(){
        if(txMouseX() >= x &&
           txMouseX() <= (x+width) &&
           txMouseY() >= y &&
           txMouseY() <= (y+height) &&
           txMouseButtons() & 1
           ){
            focus = true;
            //getch();
        }

        else if ((txMouseX() <= x ||
            txMouseX() >= (x + width)) &&
            (txMouseY() <= y ||
            txMouseY() >= (y + height)) &&
            txMouseButtons() & 1
            ) {
            focus = false;
            //getch();
        }
    }

    void check_input(){
        txSetFillColor(TX_BLACK);
        txSetColor(TX_BLACK);
        txSelectFont ("Consolas", 40);
        if(_kbhit () ){
            char  a = _getch();
            if(strlen(value)==0){
                if(a==8){
                    trash = 1;
                }
                else if(x+6+txGetTextExtentX(value)<=x+width-6){
                    word_width = 10;
                }
                    /*else if( a>='A' && a<='Z' && x+6+txGetTextExtentX(value)<=x+width-6){
                        word_width = 5;
                    }
                    else if(x+6+txGetTextExtentX(value)<=x+width-6){
                        word_width = 5;
                    } */
                if(int(a)==8){
                    value[0]='\0';
                }
                else if(x+6+txGetTextExtentX(value)<=x+width-6){
                    value[0]=a;
                    value[1]='\0';
                }
            }
            else{
                if(a==8){
                    trash = 1 ;
                    word_width=word_width-13;

                }
                else if(x+6+txGetTextExtentX(value)+12<x+width-6){
                    word_width = word_width + 13;
                }
                    /*else if( a>='A' && a<='Z' && x+6+txGetTextExtentX(value)<=x+width-6){
                        word_width = word_width + 8;
                    }

                    else if(x+6+txGetTextExtentX(value)<=x+width-6){
                        word_width = word_width + 8;
                    }*/
                if(int(a)==8){
                    value[strlen(value)-1]='\0';
                }
                else if(x+6+txGetTextExtentX(value) + 12<x+width-6){
                    value[strlen(value)+1]='\0';
                    value[strlen(value)]=a;
                }
            }
        }
    }

    char* get_value() {
        return value;
    }

    bool get_state() {
        return state;
    }

    void set_state(bool state) {
        this->state = state;
    }

};



void update_widgets();


vector <Button*> buttons;
vector <Entry*> entries;
void update_widgets() {
    if (buttons.size() > 0) {
        for (unsigned i = 0; i < buttons.size(); i++) {
            if ((*buttons[i]).get_state() == true) {
                (*buttons[i]).check_mouse_on();
                (*buttons[i]).place();
                if ((*buttons[i]).check_click()) {
                    (*buttons[i]).do_comand();
                }
            }
        }
    }
    if (entries.size() > 0) {
        for (unsigned i = 0; i < entries.size(); i++) {
            if ((*entries[i]).get_state() == true) {
                (*entries[i]).check_focus();
                if ((*entries[i]).focus) {
                    (*entries[i]).check_input();
                }
                (*entries[i]).place();
            }
        }
    }
    txSleep(100);
}
