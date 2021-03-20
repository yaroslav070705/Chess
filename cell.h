///< @file cell.h

/**
 @author Yaroslav, Roma, Anna, Stephan

 Cell - класс клетки поля;
*/

class Cell{
private:
    /// длина стороны клетки
    int side;
    /// тип клетки, 1 - чёрная клетка, 0 - белая клетка
    int type;
    /// проверка фокуса
    bool focus;
    /// толщина стороны клетки
    int side_bold = 5;
    /// отступ по x
    int margin_x = 260;
    /// отступ по y
    int margin_y = 60;
    /// указатель на фигуру
    BaseFigure* figure = nullptr;
public:
    /// конструктор
    Cell(int type0, int side0);

    void draw(int i_cell, int j_cell);
    void set_focus(bool focus0);
    int get_type();
    void set_figure(BaseFigure* figure0);
    BaseFigure* get_figure();
};

Cell::Cell(int type0, int side0){
    type = type0;
    side = side0;
    focus = false;
}
/**
 Функция рисования клетки;
 \param i_cell  - номер клетки по строке
 \param j_cell  - номер клетки по столбцу
*/
void Cell::draw(int i_cell, int j_cell){
    if(focus){
        txSetColor(TX_GREEN, 12);
        txSetFillColor(TX_NULL);
        txRectangle (margin_x+j_cell*(side)+side_bold, margin_y+i_cell*(side)+side_bold, margin_x+(j_cell+1)*(side)-side_bold, margin_y+(i_cell+1)*(side)-side_bold);
    }
}
/**
 Функция присваивания фокуса;
 \param focus0  - проверка фокуса
*/
void Cell::set_focus(bool focus0){
    focus = focus0;
}
/**
 Функция, которая возвращает тип клетки;
*/
int Cell::get_type(){
    return type;
}
/**
 Функция, которая присваевает фигуру клетки;
 \param figure0  - указатель на фигуру
*/
void Cell::set_figure(BaseFigure* figure0){
    figure = figure0;
}
/**
  Возвращает указатель на фигуру;
*/
BaseFigure* Cell::get_figure(){
    return figure;
}


