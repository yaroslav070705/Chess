///< @author Roma
#include "base_figure.h"


class Bishop: public BaseFigure{   ///< êëàññ ëàäüè
 public:
    Bishop(int type0, int x_cell0, int y_cell0) : BaseFigure(type0, x_cell0, y_cell0){}      ///< êîíñòðóêòîð
    virtual void draw() override{}                                                          ///< ðèñîâàíèå
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;               ///< ïðîñ÷¸ò âîçìîæíîñòè õîäîâ
    virtual void change() override{}
    /*void printArray(){
      cout<<"size="<<move_ability_cells.size()<<'\n';
      for (int i = 0; i < move_ability_cells.size(); i++){
         cout<<"[y"<<i<<"]="<<move_ability_cells[i][0]<<"  ";
         cout<<"[x"<<i<<"]="<<move_ability_cells[i][1]<<'\n';
      }
    } */
};


void Bishop::count_move_ability_cells(vector<BaseFigure*> figures) {
    bool out = false;
    for(int i = 1; (y_cell - i >= 1) && (x_cell + i < 9); i++) {   ///< ââåðõ ïðàâî
        int* cell = new int[2];
        cell[0] = y_cell - i;
        cell[1] = x_cell + i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - i)) && (figura->get_x_cell() == (x_cell + i))) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = 1; (y_cell - i >= 1) && (x_cell - i >= 1); i++) {   ///< ââåðõ ëåâî
        int* cell = new int[2];
        cell[0] = y_cell - i;
        cell[1] = x_cell - i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - i)) && (figura->get_x_cell() == (x_cell - i))) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
    out = false;
    for(int i = 1; (y_cell + i < 9) && (x_cell + i < 9); i++) {   ///< ââåðõ ïðàâî
        int* cell = new int[2];
        cell[0] = y_cell + i;
        cell[1] = x_cell + i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + i)) && (figura->get_x_cell() == (x_cell + i))) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
    out = false;
    for(int i = 1; (y_cell + i < 9) && (x_cell - i >= 1); i++) {   ///< âíèç âëåâî
        int* cell = new int[2];
        cell[0] = y_cell + i;
        cell[1] = x_cell - i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + i)) && (figura->get_x_cell() == (x_cell - i))) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
}

