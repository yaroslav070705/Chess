///< @file Rook.h

/**
 @author Anna, Andrey, Timofey, Roma

 Rook - класс фигуры ладьи;

 Потомок класса BaseFigure.
*/
class Rook: public BaseFigure{   // класс Ладья
    /// переменная проверки хода ладьи;
    int step = 0;
 public:
    /// конструктор
    Rook(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}
    virtual void draw(int x, int y, int r) override;                                            // рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;                // просчёт возможности ходов
    virtual void change() override{}
    int get_step();
    void set_step(int step0);
};
/**
 Функция рисования ;
 \param x  - координата ладьи по оси x;
 \param y  - координата ладьи по оси y;
 \param r  - размер ладьи.
 */
void Rook::draw (int x, int y, int r){
    txSetColor(side_color,2);
    txSetFillColor(main_color);

    POINT head[12] = {{r+x, (9*r)+y}, {r+x, (4*r)+y}, {(3*r)+x, (4*r)+y}, {(3*r)+x, (7*r)+y }, {(4*r)+x, (7*r)+y}, {(4*r)+x,(5*r)+y}, {(7*r)+x,(5*r)+y}, {(7*r)+x,(7*r)+y}, {(8*r)+x,(7*r)+y}, {(8*r)+x,(4*r)+y},{(10*r)+x,(4*r)+y}, {(10*r)+x,(9*r)+y}}; //"голова", меняется в зависимости от фигуры
    txPolygon (head, 12);

     POINT neck[4] = {{(2*r)+x, (9*r)+y}, {(9*r)+x,(9*r)+y},{(9*r)+x, (10*r)+y},{(2*r)+x,(10*r)+y}};
    txPolygon (neck, 4);

    POINT body[4] = {{(4*r)+x, (10*r)+y}, {(7*r)+x, (10*r)+y}, {(8*r)+x, (20*r)+y}, {(3*r)+x, (20*r)+y}};     // неизменяемое тело
    txPolygon (body, 4);

    POINT stand1[4] = {{(2*r)+x, (20*r)+y}, {(9*r)+x, (20*r)+y}, {(9*r)+x, (21*r)+y}, {(2*r)+x, (21*r)+y}};   // первая подставка для всех, а у пешек только она
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(1*r)+x, (21*r)+y}, {(10*r)+x, (21*r)+y}, {(10*r)+x, (22*r)+y}, {(1*r)+x, (22*r)+y}}; // вторая подставка для средних(ладья,слон,конь) и лучших
    txPolygon (stand2, 4);

    //POINT stand3[4] = {{(0*r)+x, (22*r)+y}, {(11*r)+x, (22*r)+y}, {(11*r)+x, (23*r)+y}, {(0*r)+x, (23*r)+y}};//третья подставка для лучших(ферзей, королей)
    // txPolygon (stand3, 4);
}
/**
 Функция просчёта возможности хода;

 \param figures  - вектор фигур.

 Ладья ходит и ест по вертикали и по горизонтали на любое колличество клеток;

*/
void Rook :: count_move_ability_cells(vector<BaseFigure*> figures) {
    move_ability_cells.clear();
    bool out = false;
    for(int i = y_cell-1; i >= 0; i--) {         // вверх
        int* cell = new int[2];
        cell[0] = i;
        cell[1] = x_cell;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((i == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                if(type == figura->get_type()){
                    move_ability_cells.pop_back();
                }
                out = true;
                break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = y_cell+1; i <= 7; i++) {          // вниз
        int* cell = new int[2];
        cell[0] = i;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((i == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                if(type == figura->get_type()){
                    move_ability_cells.pop_back();
                }
                out = true;
                break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int j = x_cell-1; j >= 0; j--) {          // влево
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = j;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((y_cell == figura->get_y_cell()) && (j == figura->get_x_cell())) {
                if(type == figura->get_type()){
                    move_ability_cells.pop_back();
                }
                out = true;
                break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int j = x_cell+1; j <= 7; j++) {          // вправо
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = j;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((y_cell == figura->get_y_cell()) && (j == figura->get_x_cell())) {
                if(type == figura->get_type()){
                    move_ability_cells.pop_back();
                }
                out = true;
                break;
            }
        }
        if(out){
            break;
        }
    }
}
/**
 Функция, которая возращает переменную step;
*/
int Rook::get_step() {
    return step;
}
/**
 Функция, которая присваевает ход (step) ладьи;
 \param step0  - проверка хода ладьи;
*/
void Rook::set_step(int step0) {
    step = step0;
}
