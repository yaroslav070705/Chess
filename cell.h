///< @file cell.h
///< @author Yaroslav, Roma, Anna

class Cell{  ///< класс клетки поля
private:
    int side;           ///< длина стороны клетки
    int type;           ///< чёрная/белая
    bool focus;         ///< проверка в фокусе
    int side_bold = 5;  ///< толщина стороны клетки
    int margin_x = 260; ///< отступ по x
    int margin_y = 60;  ///< отступ по y
    BaseFigure* figure = nullptr;        ///< указатель на фигуру
public:
    Cell(int type0, int side0);          ///< конструктор

    void draw(int i_cell, int j_cell);   ///< рисование
    void set_focus(bool focus0);
    int get_type();                      ///< get/set
    void set_figure(BaseFigure* figure0);
    BaseFigure* get_figure();
};


Cell::Cell(int type0, int side0){
    type = type0;
    side = side0;
    focus = false;
}

void Cell::draw(int i_cell, int j_cell){
    if(type == 0){
        txSetColor(TX_WHITE,10);
        txSetFillColor(TX_WHITE);
    }

    else{
        txSetColor(TX_BLACK,10);
        txSetFillColor(TX_BLACK);
    }

    if(focus){
        txSetColor(TX_GREEN,12);
    }
    txRectangle(margin_x+j_cell*(side)+side_bold, margin_y+i_cell*(side)+side_bold, margin_x+(j_cell+1)*(side)-side_bold, margin_y+(i_cell+1)*(side)-side_bold);
}

void Cell::set_focus(bool focus0){
    focus = focus0;
}

int Cell::get_type(){
    return type;
}

void Cell::set_figure(BaseFigure* figure0){
    figure = figure0;
}
BaseFigure* Cell::get_figure(){
    return figure;
}
