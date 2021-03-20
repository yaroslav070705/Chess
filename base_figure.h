///< @file base_figure.h

/**
 @author Yaroslav, Roma, Anna

 BaseFigure - базовый класс фигуры;
*/
class BaseFigure{   // базовый класс
 protected:
    /// тип клетки, 1 - чёрная клетка, 0 - белая клетка
    int type;
    /// номер клетки по столбцам
    int x_cell;
    /// номер клетки по строкам
    int y_cell;
    /// цвет заливки фигуры
    COLORREF main_color;
    /// цвет окантовки фигуры
    COLORREF side_color;
    /// массив возможных ходов
    vector <int*> move_ability_cells;

 public:
    /// конструктор
    BaseFigure(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0);
    void move(int x_cell0, int  y_cell0);
    /// функция просчёта возможности хода
    virtual void count_move_ability_cells(vector<BaseFigure*> figures){}
    /// функция изменения
    virtual void change(){}
    /// функция рисования
    virtual void draw(int x, int y, int r){}
    /// функция изменения + рисования
    void update();

    int get_type();
    void set_type(int type0);
    int get_x_cell();
    void set_x_cell(int x_cell0);
    int get_y_cell();
    void set_y_cell(int y_cell0);
    vector <int*> get_move_ability_cells();
    void set_move_ability_cells(vector <int*> move_ability_cells0);
};

BaseFigure::BaseFigure(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0): type(type0), x_cell(x_cell0), y_cell(y_cell0), main_color(main_color0), side_color(side_color0){}
/**
 Функция движения фигур по клеткам поля;
 \param x_cell0  - номер клетки по столбцу;
 \param y_cell0  - номер клетки по строке;
 Присваевает x_cell и y_cell значения x_cell0 и y_cell0 соответственно.
 */
void BaseFigure::move (int x_cell0, int y_cell0){
    x_cell = x_cell0;
    y_cell = y_cell0;
}
void BaseFigure::update(){
    //change();
    //draw();
}
/**
 Функция, которая возвращает тип (type) клетки ;
*/
int BaseFigure::get_type(){
    return type;
}
/**
 Функция, которая присваевает тип (type) клетки ;
 \param type0  - тип клетки
*/
void BaseFigure::set_type(int type0){
    type = type0;
}
/**
 Функция, которая возвращает значение x_cell;
 */
int BaseFigure::get_x_cell(){
    return x_cell;
}
/**
 Функция, которая присваивает значение x_cell;
 \param  x_cell0 - номер клетки в столбце
 */
void BaseFigure::set_x_cell(int x_cell0){
    x_cell = x_cell0;
}
/**
 Функция, которя возвращает значение y_cell;
 */
int BaseFigure::get_y_cell(){
    return y_cell;
}
/**
 Функция, которая присваивает значение y_cell;
 \param  y_cell0 - номер клетки по строке
 */
void BaseFigure::set_y_cell(int y_cell0){
    y_cell = y_cell0;
}
/**
  Возвращает массив возможных ходов;
*/
vector <int*> BaseFigure :: get_move_ability_cells(){
    return move_ability_cells;
}
/**
 Функция, которая присваивает значение move_ability_cells;
 \param  move_ability_cells0 - вектор возможностей хода
 */
void BaseFigure::set_move_ability_cells(vector <int*> move_ability_cells0){
    move_ability_cells = move_ability_cells0;
}
