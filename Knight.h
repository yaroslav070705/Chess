///< @file Knight.h

/**
 @author Yaroslav, Stepan, Timofey

 Knight - класс фигуры кон€;

 ѕотомок класса BaseFigure.
*/
class Knight : public BaseFigure{
 public:
    /// конструктор
    Knight(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}

    virtual void draw(int x, int y, int r) override;                                         // рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;             // просчЄт возможности ходов
    virtual void change() override{}
};
/**
 ‘ункци€ рисовани€ кон€;
 \param x  - координата кон€ по оси x;
 \param y  - координата кон€ по оси y;
 \param r  - размер кон€.
 */
void Knight::draw(int x, int y, int r){
    txSetFillColor (main_color);
    txSetColor (side_color, 2);

    txSetFillColor (main_color);
    POINT Knight1[13] = {{r *  3  /2 + x, r *  42   /2 + y},     // тело без ушей
                        {r *  19  /2 + x, r *  42   /2 + y},
                        {r *  18 /2 + x, r *  22   /2 + y},
                        {r *  17  /2 + x, r *  15   /2 + y},
                        {r *  15  /2 + x, r *  8   /2 + y},
                        {r *  13  /2 + x, r *  6   /2 + y},
                        {r *  7  /2 + x, r *  6  /2 + y},
                        {r *  0  /2 + x, r *  19  /2 + y},
                        {r *  2 /2 + x, r *  23   /2 + y},
                        {r *  5  /2 + x, r *  23  /2 + y},
                        {r *  10 /2 + x, r *  17  /2 + y},
                        {r *  10 /2 + x, r *  23  /2 + y},
                        {r *  3 /2 + x, r *  40   /2 + y}};
    txPolygon  (Knight1, 13);

    txSetFillColor (main_color);
    POINT Ears[5] = {{r *  7  /2 + x, r *  6    /2 + y},      //уши
                     {r *  9 /2 + x, r *  0    /2 + y},
                     {r *  10  /2 + x, r * 6  /2 + y},
                     {r *  12 /2 + x, r *  0    /2 + y},
                     {r *  13  /2 + x, r *  6    /2 + y}};
    txPolygon  (Ears, 5);

    POINT stand1[4] = {{(2*r/2)+x, (42*r/2)+y}, {(20*r/2)+x, (42*r/2)+y}, {(20*r/2)+x, (44*r/2)+y}, {(2*r/2)+x, (44*r/2)+y}}; //перва€ подставка дл€ всех, а у пешек только она
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(0*r/2)+x, (44*r/2)+y}, {(22*r/2)+x, (44*r/2)+y}, {(22*r/2)+x, (46*r/2)+y}, {(0*r/2)+x, (46*r/2)+y}}; //втора€ подставка дл€ средних(ладь€,слон,конь) и лучших
    txPolygon (stand2, 4);

    txSetColor (side_color, 2);
    txLine (r *  2 /2 + x, r *  23 /2 + y, r *  5 /2 + x, r *  20 /2 + y);    //полоска рта

    txSetFillColor (TX_RED);
    //txSetFillColor (colorEYES_FOR_WHITE_FROG_IN_SWOON);
    txCircle(8/2*r + x,12/2*r + y,2/2 *r);

    txSetFillColor (RGB(255,255,255));
    txCircle(8/2*r + x,12/2*r + y,1/2 *r);
}
/**
 ‘ункци€ просчЄта возможности хода;
 \param figures  - вектор фигур.
  онь ходит и ест на два пол€ по горизонтали или по вертикали, и на одну клетку перпендикул€рную первоначальному направлению;
  онь может "перепрыгивать" через другие фигуры;
*/
void Knight::count_move_ability_cells(vector<BaseFigure*> figures){
    move_ability_cells.clear();
    if(y_cell > 1){
        if(x_cell > 0){
            int* cell = new int[2];
            cell[0] = y_cell - 2;
            cell[1] = x_cell - 1;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
        if(x_cell < 7){
            int* cell = new int[2];
            cell[0] = y_cell - 2;
            cell[1] = x_cell + 1;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
    }

    if(y_cell > 0){
        if(x_cell > 1){
            int* cell = new int[2];
            cell[0] = y_cell - 1;
            cell[1] = x_cell - 2;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
        if(x_cell < 6){
            int* cell = new int[2];
            cell[0] = y_cell - 1;
            cell[1] = x_cell + 2;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
    }

    if(y_cell < 7){
        if(x_cell > 1){
            int* cell = new int[2];
            cell[0] = y_cell + 1;
            cell[1] = x_cell - 2;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
        if(x_cell < 6){
            int* cell = new int[2];
            cell[0] = y_cell + 1;
            cell[1] = x_cell + 2;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
    }

    if(y_cell < 6){
        if(x_cell > 0){
            int* cell = new int[2];
            cell[0] = y_cell + 2;
            cell[1] = x_cell - 1;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
        if(x_cell < 7){
            int* cell = new int[2];
            cell[0] = y_cell + 2;
            cell[1] = x_cell + 1;

            move_ability_cells.push_back(cell);
            for(auto figura : figures) {
                if((figura->get_y_cell() == move_ability_cells.back()[0]) && (figura->get_x_cell() == move_ability_cells.back()[1])) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   break;
                }
            }
        }
    }
}

