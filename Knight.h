///< @author Yaroslav,Stepan,Timofey
//#ifndef Knight
//#define Knight
class Knight : public BaseFigure{    ///< класс коня
public:
    Knight(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}      ///< конструктор
    virtual void draw(int type0, int x_cell0, int y_cell0) override;                                                           ///< рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;             ///< просчёт возможности ходов
    virtual void change() override{}
};

void Knight::draw(int x, int y, int r){
    txSetFillColor (main_color);
    txSetColor (side_color, 5*r);

    txSetFillColor (main_color);
    POINT Knight[14] = {{r *  400  + x, r *  300   + y},     //тело без ушей
                        {r *  300  + x, r *  500   + y},
                        {r *  350 + x, r *  600   + y},
                        {r *  400  + x, r *  600   + y},
                        {r *  500  + x, r *  500   + y},
                        {r *  500  + x, r *  600   + y},
                        {r *  400  + x, r *  750  + y},
                        {r *  400  + x, r *  800   + y},
                        {r *  750 + x, r *  800   + y},
                        {r *  700  + x, r *  550  + y},
                        {r *  650 + x, r *  450  + y},
                        {r *  550 + x, r *  350  + y},
                        {r *  450 + x, r *  300   + y},
                        {r *  400  + x, r *  300   + y}};
    txPolygon  (Knight, 14);

    txSetFillColor (main_color);
    POINT Ears[7] = {{r *  400  + x, r *  300    + y},      //уши
                     {r *  450 + x, r *  200    + y},
                     {r *  500  + x, r * 325  + y},
                     {r *  550 + x, r *  200    + y},
                     {r *  600  + x, r *  400    + y},
                     {r *  550 + x, r *  350   + y},
                     {r *  450 + x, r *  300    + y}};
    txPolygon  (Ears, 7);

    txSetColor (side_color, 5*r);
    txLine (r *  350 + x, r *  600 + y, r *  400 + x, r *  550 + y);    //полоска рта
}

void Knight::count_move_ability_cells(vector<BaseFigure*> figures){
    if(y_cell > 1){
        if(x_cell > 0){
            int* cell = new int[2];
            cell[0] = y_cell - 2;
            cell[1] = x_cell - 1;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 7){
            int* cell = new int[2];
            cell[0] = y_cell - 2;
            cell[1] = x_cell + 1;

            move_ability_cells.push_back(cell);
        }
    }

    if(y_cell > 0){
        if(x_cell > 1){
            int* cell = new int[2];
            cell[0] = y_cell - 1;
            cell[1] = x_cell - 2;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 6){
            int* cell = new int[2];
            cell[0] = y_cell - 1;
            cell[1] = x_cell + 2;

            move_ability_cells.push_back(cell);
        }
    }

    if(y_cell < 7){
        if(x_cell > 1){
            int* cell = new int[2];
            cell[0] = y_cell + 1;
            cell[1] = x_cell - 2;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 6){
            int* cell = new int[2];
            cell[0] = y_cell + 1;
            cell[1] = x_cell + 2;

            move_ability_cells.push_back(cell);
        }
    }

    if(y_cell < 6){
        if(x_cell > 0){
            int* cell = new int[2];
            cell[0] = y_cell + 2;
            cell[1] = x_cell - 1;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 7){
            int* cell = new int[2];
            cell[0] = y_cell + 2;
            cell[1] = x_cell + 1;

            move_ability_cells.push_back(cell);
        }
    }
}

//#endif
