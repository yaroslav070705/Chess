

using namespace std;
class Knight : public BaseFigure{
public:
    Knight(int type0, int x_cell0, int y_cell0) : BaseFigure(type0, x_cell0, y_cell0){}      ///< конструктор
    virtual void draw() override{}                                                          ///< рисование
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;               ///< просчёт возможности ходов
    virtual void change() override{}
};

void Knight::count_move_ability_cells(vector<BaseFigure*> figures){
    if(y_cell > 2){
        if(x_cell > 1){
            int* cell = new int[2];
            cell[0] = y_cell - 2;
            cell[1] = x_cell - 1;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 8){
            int* cell = new int[2];
            cell[0] = y_cell - 2;
            cell[1] = x_cell + 1;

            move_ability_cells.push_back(cell);
        }
    }

    if(y_cell > 1){
        if(x_cell > 2){
            int* cell = new int[2];
            cell[0] = y_cell - 1;
            cell[1] = x_cell - 2;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 7){
            int* cell = new int[2];
            cell[0] = y_cell - 1;
            cell[1] = x_cell + 2;

            move_ability_cells.push_back(cell);
        }
    }

    if(y_cell < 8){
        if(x_cell > 2){
            int* cell = new int[2];
            cell[0] = y_cell + 1;
            cell[1] = x_cell - 2;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 7){
            int* cell = new int[2];
            cell[0] = y_cell + 1;
            cell[1] = x_cell + 2;

            move_ability_cells.push_back(cell);
        }
    }

    if(y_cell < 7){
        if(x_cell > 1){
            int* cell = new int[2];
            cell[0] = y_cell + 2;
            cell[1] = x_cell - 1;

            move_ability_cells.push_back(cell);
        }
        if(x_cell < 8){
            int* cell = new int[2];
            cell[0] = y_cell + 2;
            cell[1] = x_cell + 1;

            move_ability_cells.push_back(cell);
        }
    }
}
