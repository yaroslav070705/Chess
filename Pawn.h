///< @author Anna,Artiom,Timofey

class Pawn: public BaseFigure{   ///< класс пешки
 public:
    Pawn(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}      ///< конструктор
    virtual void draw(int x, int y, int r) override;                                      ///< рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;           ///< просчёт возможности ходов
    virtual void change() override{}
};

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

void Pawn :: count_move_ability_cells(vector<BaseFigure*> figures) {
    if(type == 0) {     // белая
        int i = y_cell;
        if(y_cell != 0){
            for(auto figura : figures) {
                if((i - 1 == figura->get_y_cell()) && (x_cell + 1 == figura->get_x_cell()) && (type != figura->get_type())) {     //правая верхняя диагональ
                    int* cell = new int[2];
                    cell[0] = i - 1;
                    cell[1] = x_cell + 1;
                    move_ability_cells.push_back(cell);
                }
                if((i - 1 == figura->get_y_cell()) && (x_cell - 1 == figura->get_x_cell()) && (type != figura->get_type())) {     //левая верхняя диагональ
                    int* cell = new int[2];
                    cell[0] = i - 1;
                    cell[1] = x_cell - 1;
                    move_ability_cells.push_back(cell);
                }
                if((i - 1 != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {                                         //клетка вверх
                    int* cell = new int[2];
                    cell[0] = i-1;
                    cell[1] = x_cell;
                    move_ability_cells.push_back(cell);
                }
            }
        }
        if(y_cell == 6){
            for(auto figura : figures) {
                if((i - 1 != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {      //2 клетки вверх
                    int* cell = new int[2];
                    cell[0] = i - 2;
                    cell[1] = x_cell;
                    move_ability_cells.push_back(cell);
                }
            }
        }

    }
    if(type == 1) {     // чёрная
        int i = y_cell;
        if(y_cell != 7){
            for(auto figura : figures) {
                if((i + 1 == figura->get_y_cell()) && (x_cell + 1 == figura->get_x_cell()) && (type != figura->get_type())) {    //правая нижняя диагональ
                    int* cell = new int[2];
                    cell[0] = i + 1;
                    cell[1] = x_cell + 1;
                    move_ability_cells.push_back(cell);
                }
                if((i + 1 == figura->get_y_cell()) && (x_cell - 1 == figura->get_x_cell()) && (type != figura->get_type())) {    //левая нижняя диагональ
                    int* cell = new int[2];
                    cell[0] = i + 1;
                    cell[1] = x_cell - 1;
                    move_ability_cells.push_back(cell);
                }
                if((i != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {             //клетка вниз
                    int* cell = new int[2];
                    cell[0] = i + 1;
                    cell[1] = x_cell;
                    move_ability_cells.push_back(cell);
                }
            }
        }
        if(y_cell == 1){
            for(auto figura : figures) {
                if((i + 1 != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {    //2 клетки вниз
                    int* cell = new int[2];
                    cell[0] = i + 2;
                    cell[1] = x_cell;
                    move_ability_cells.push_back(cell);
                }
            }
        }
    }

}
