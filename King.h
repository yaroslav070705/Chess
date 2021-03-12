///< @author Roma,Timofey,Yaroslav


class King: public BaseFigure{   ///< класс короля
    King(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}      ///< конструктор
    virtual void draw(int type0, int x_cell0, int y_cell0) override;                                                          ///< рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;               ///< просчёт возможности ходов
    virtual void change() override{}
    /*void printArray(){
      cout<<"size="<<move_ability_cells.size()<<'\n';
      for (int i = 0; i < move_ability_cells.size(); i++){
         cout<<"[y"<<i<<"]="<<move_ability_cells[i][0]<<"  ";
         cout<<"[x"<<i<<"]="<<move_ability_cells[i][1]<<'\n';
      }
    } */
};

void King::draw(int x, int y, int r){
    txSetColor(side_color,2);
    txSetFillColor (RGB (255, 215, 0)); //золото для короны

    POINT headtop[25] = {{(6*r)+x, (0*r)+y}, {(7*r)+x, (6*r)+y}, {(8*r)+x, (0*r)+y},
                     {(9*r)+x, (6*r)+y}, {(10*r)+x, (0*r)+y}, {(11*r)+x, (6*r)+y},
                     {(12*r)+x, (0*r)+y}, {(13*r)+x, (6*r)+y}, {(14*r)+x, (0*r)+y},
                     {(15*r)+x, (6*r)+y}, {(16*r)+x, (0*r)+y}, {(16*r)+x, (8*r)+y},
                     {(14*r)+x, (8*r)+y}, {(12*r)+x, (18*r)+y}, {(13*r)+x, (18*r)+y},
                     {(13*r)+x, (19*r)+y}, {(14*r)+x, (19*r)+y}, {(14*r)+x, (20*r)+y},
                     {(8*r)+x, (20*r)+y}, {(8*r)+x, (19*r)+y}, {(9*r)+x, (19*r)+y},
                     {(9*r)+x, (18*r)+y}, {(10*r)+x, (18*r)+y}, {(8*r)+x, (8*r)+y}, {(6*r)+x, (8*r)+y}}; //"голова", меняется в зависимости от фигуры
    txPolygon (headtop, 25);

    /*POINT headnottop[26] = {{(2*r)+x, (0*r)+y}, {(3*r)+x, (4*r)+y}, {(3*r)+x, (0*r)+y},
                           {(4*r)+x, (4*r)+y}, {(4*r)+x, (0*r)+y}, {(5*r)+x, (4*r)+y},
                           {(6*r)+x, (4*r)+y}, {(7*r)+x, (0*r)+y}, {(7*r)+x, (4*r)+y},
                           {(8*r)+x, (0*r)+y}, {(8*r)+x, (4*r)+y}, {(9*r)+x, (0*r)+y},
                           {(9*r)+x, (5*r)+y}, {(7*r)+x, (5*r)+y}, {(6*r)+x, (9*r)+y},
                           {(7*r)+x, (9*r)+y}, {(7*r)+x, (10*r)+y}, {(8*r)+x, (10*r)+y},
                           {(8*r)+x, (11*r)+y}, {(3*r)+x, (11*r)+y}, {(3*r)+x, (10*r)+y},
                           {(4*r)+x, (10*r)+y}, {(4*r)+x, (9*r)+y}, {(5*r)+x, (9*r)+y},
                           {(4*r)+x, (5*r)+y}, {(2*r)+x, (5*r)+y}}; //"голова", меняется в зависимости от фигуры
    txPolygon (headnottop, 26);*/

    txSetFillColor (main_color); //основной цвет (белый)
    //txSetFillColor (RGB (255, 255, 255)); //основной цвет (чёрный)

    POINT body[4] = {{(10*r)+x, (20*r)+y}, {(12*r)+x, (20*r)+y}, {(16*r)+x, (40*r)+y}, {(6*r)+x, (40*r)+y}}; //неизменяемое тело
    txPolygon (body, 4);

    POINT stand1[4] = {{(4*r)+x, (40*r)+y}, {(18*r)+x, (40*r)+y}, {(18*r)+x, (42*r)+y}, {(4*r)+x, (42*r)+y}}; //первая подставка для всех, а у пешек только она
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(2*r)+x, (42*r)+y}, {(20*r)+x, (42*r)+y}, {(20*r)+x, (44*r)+y}, {(2*r)+x, (44*r)+y}}; //вторая подставка для средних(ладья,слон,конь) и лучших
    txPolygon (stand2, 4);

    POINT stand3[4] = {{(0*r)+x, (44*r)+y}, {(22*r)+x, (44*r)+y}, {(22*r)+x, (46*r)+y}, {(0*r)+x, (46*r)+y}};//третья подставка для лучших(ферзей, королей)
    txPolygon (stand3, 4);
}

void King :: count_move_ability_cells(vector<BaseFigure*> figures) {
    bool out = false;
    if((x_cell+1) < 8 && (y_cell-1) >= 0)
    {                                           ///< вверх право
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((x_cell -1) >= 0 && (y_cell-1) >= 0)
    {                                           ///< вверх влево
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((x_cell+1) < 8 && (y_cell+1) < 8)
    {                                           ///< вниз вправо
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((x_cell-1) >= 0 && (y_cell+1) < 8)
    {                                           ///< вниз влево
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((y_cell-1) >= 0)
    {                                           ///< вверх
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((y_cell+1) < 8)
    {                                           ///< вниз
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((x_cell+1) < 8)
    {                                           ///< вправо
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
    if((x_cell-1) >= 0)
    {                                           ///< влево
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
    }
}
