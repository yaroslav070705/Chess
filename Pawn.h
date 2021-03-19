///< @file Pawn.h

/**
 @author Anna, Artiom, Timofey

 Pawn - класс фигуры пешки

 ѕотомок класса BaseFigure
*/
class Pawn: public BaseFigure{
 public:
    /// конструктор
    Pawn(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}

    virtual void draw(int x, int y, int r) override;                                      // рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;          // просчЄт возможности ходов
    virtual void change() override{}
};
/**
 ‘ункци€ рисовани€ пешки;
 \param x  - координата пешки по оси x;
 \param y  - координата пешки по оси y;
 \param r  - размер пешки.
 */
void Pawn::draw(int x, int y, int r){
    txSetColor(side_color,2);
    txSetFillColor(main_color);
    POINT pawn[18] = {{2 * r + x, 0 * r + y}, {4 * r + x, 0 * r + y}, {5 * r + x, 1 * r + y}, {5 * r + x, 3 * r + y},
                     {4 * r + x, 4 * r + y}, {4 * r + x, 5 * r + y}, {5 * r + x, 12 * r + y}, {6 * r + x, 12 * r + y},
                     {6 * r + x, 13 * r + y}, {0 * r + x, 13 * r + y}, {0 * r + x, 12 * r + y}, {5 * r + x, 12 * r + y},
                     {1 * r + x, 12 * r + y}, {2 * r + x, 5 * r + y}, {2 * r + x, 4 * r + y}, {1 * r + x, 3 * r + y},
                     {1 * r + x, 1 * r + y}, {2 * r + x, 0 * r + y}};
    txPolygon (pawn, 18);
}
/**
 ‘ункци€ просчЄта возможности хода;

 \param figures  - вектор фигур.

 ѕешка ходит на одну клетку вперЄд, а в свой первый ход может пойти и на две клетки ;

 ≈ст пешка по диагонали на одно поле и только вперЄд;
 */
void Pawn :: count_move_ability_cells(vector<BaseFigure*> figures) {
    move_ability_cells.clear();
    if(type == 0) {     // бела€
        int i = y_cell;
        if(y_cell != 0){
            for(auto figura : figures) {
                if((i - 1 == figura->get_y_cell()) && (x_cell + 1 == figura->get_x_cell()) && (type != figura->get_type()) && (x_cell != 7)) {     // права€ верхн€€ диагональ
                    int* cell = new int[2];
                    cell[0] = i - 1;
                    cell[1] = x_cell + 1;
                    move_ability_cells.push_back(cell);
                }
                if((i - 1 == figura->get_y_cell()) && (x_cell - 1 == figura->get_x_cell()) && (type != figura->get_type()) && (x_cell != 0)) {     // лева€ верхн€€ диагональ
                    int* cell = new int[2];
                    cell[0] = i - 1;
                    cell[1] = x_cell - 1;
                    move_ability_cells.push_back(cell);
                }
            }
            int* cell = new int[2];
            cell[0] = i - 1;                         // клетка вверх
            cell[1] = x_cell;
            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                    move_ability_cells.pop_back();
                    break;
                }
            }
        }
        if(y_cell == 6){                             // 2 клетки вверх
            int* cell = new int[2];
            cell[0] = i - 2;
            cell[1] = x_cell;
            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if(((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1]))
                || (y_cell - 1 == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                    move_ability_cells.pop_back();
                    break;
                }
            }
        }
    }
    if(type == 1) {     //  чЄрна€
        int i = y_cell;
        if(y_cell != 7){
            for(auto figura : figures) {
                if((i + 1 == figura->get_y_cell()) && (x_cell + 1 == figura->get_x_cell()) && (type != figura->get_type()) && (x_cell != 7)) {    // права€ нижн€€ диагональ
                    int* cell = new int[2];
                    cell[0] = i + 1;
                    cell[1] = x_cell + 1;
                    move_ability_cells.push_back(cell);
                }
                if((i + 1 == figura->get_y_cell()) && (x_cell - 1 == figura->get_x_cell()) && (type != figura->get_type()) && (x_cell != 0)) {    // лева€ нижн€€ диагональ
                    int* cell = new int[2];
                    cell[0] = i + 1;
                    cell[1] = x_cell - 1;
                    move_ability_cells.push_back(cell);
                }
            }
            int* cell = new int[2];
            cell[0] = i + 1;                         // клетка вниз
            cell[1] = x_cell;
            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                    move_ability_cells.pop_back();
                    break;
                }
            }
        }
        if(y_cell == 1){
            int* cell = new int[2];
            cell[0] = i + 2;                        // 2 клетки вниз
            cell[1] = x_cell;
            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if(((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1]))
                || (y_cell + 1 == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                    move_ability_cells.pop_back();
                    break;
                }
            }
        }
    }

}
