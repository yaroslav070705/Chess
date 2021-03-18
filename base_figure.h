///< @file base_figure.h
///< @author Yaroslav, Roma, Anna
using namespace std;

class BaseFigure{   ///< базовый класс
 protected:
    int type;                                ///< 1 - чёрная клетка, 0 - белая клетка
    int x_cell;                              ///< клетка == j
    int y_cell;                              ///< клетка == i
    COLORREF side_color;                     ///< цвет окантовки фигуры
    COLORREF main_color;                     ///< цвет заливки фигуры
    vector <int*> move_ability_cells;        ///< массив возможных ходов

 public:
    BaseFigure(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0);  ///< конструктор
    void move(int x_cell0, int  y_cell0);                                                         ///< функция движения
    virtual void count_move_ability_cells(vector<BaseFigure*> figures){}                          ///< функция просчёта возможности хода
    virtual void change(){}                  ///< изменение
    virtual void draw(int x, int y, int r){} ///< рисование
    void update();                           ///< изменение + рисование

    int get_type();
    void set_type(int type0);
    int get_x_cell();                        ///< get/set
    void set_x_cell(int x_cell0);
    int get_y_cell();
    void set_y_cell(int y_cell0);
    vector <int*> get_move_ability_cells();
    void set_move_ability_cells(vector <int*> move_ability_cells0);
};

BaseFigure::BaseFigure(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0): type(type0), x_cell(x_cell0), y_cell(y_cell0), main_color(main_color0), side_color(side_color0){}

void BaseFigure::move (int x_cell0, int y_cell0){
    x_cell = x_cell0;
    y_cell = y_cell0;
}

void BaseFigure::update(){
    //change();
    //draw();
}

int BaseFigure::get_type(){
    return type;
}

void BaseFigure::set_type(int type0){
    type = type0;
}


int BaseFigure::get_x_cell(){
    return x_cell;
}

void BaseFigure::set_x_cell(int x_cell0){
    x_cell = x_cell0;
}

int BaseFigure::get_y_cell(){
    return y_cell;
}

void BaseFigure::set_y_cell(int y_cell0){
    y_cell = y_cell0;
}

vector <int*> BaseFigure:: get_move_ability_cells(){
    return move_ability_cells;
}

void BaseFigure::set_move_ability_cells(vector <int*> move_ability_cells0){
    move_ability_cells = move_ability_cells0;
}
