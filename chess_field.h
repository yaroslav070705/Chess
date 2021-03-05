//#include "cell.h"
//#include "BaseFigure.h"
using namespace std;

class ChessField{
private:
    Cell* cells[8][8];
    vector<BaseFigure*> figures;
    Cell* cell_in_focus = nullptr;
public:
    ChessField();
    void _add_cells();
    void _add_figures();
    void _draw_field();
    void _draw_figures();
    void _draw_move_ability_cells();
    void draw();

    void check_click();


};

ChessField::ChessField(){
    _add_cells();
}

void ChessField::_add_cells(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i%2 == 0){
                if(j%2 == 0){
                    cells[i][j] = new Cell(0,85);
                }
                else{
                    cells[i][j] = new Cell(1,85);
                }
            }
            else{
                if(j%2 == 0){
                    cells[i][j] = new Cell(1,85);
                }
                else{
                    cells[i][j] = new Cell(0,85);
                }
            }
        }
    }
}

void ChessField::_add_figures(){
    figures.push_back(new Rook(0,0,1));
    cells[1][0]->set_figure(figures.back());
    figures.push_back(new Rook(1,5,7));
    cells[7][5]->set_figure(figures.back());
    figures.push_back(new Rook(0,5,1));
    cells[1][5]->set_figure(figures.back());

}

void ChessField::_draw_field() {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cells[i][j]->draw(i, j);
        }
    }

}

void ChessField::_draw_figures(){
    for(auto figure:figures){
        Rook* fig = dynamic_cast<Rook*>(figure);
        figure->draw(figure->get_x_cell()*85+280,figure->get_y_cell()*85+55,4);
    }
}

void ChessField::draw(){
    _draw_field();
    _draw_move_ability_cells();
    _draw_figures();
}

void ChessField::_draw_move_ability_cells(){
    int side_bold = 4;
    int side = 85;
    vector <int*> move_ability_cells;
    if(cell_in_focus){
        if(cell_in_focus->get_figure()){
            move_ability_cells = cell_in_focus->get_figure()->get_move_ability_cells();
        }
    }
    if(move_ability_cells.size() != 0){
        for(int i=0;i<move_ability_cells.size();i++){
            int x_cell = move_ability_cells[i][1];
            int y_cell = move_ability_cells[i][0];
            txSetColor(RGB(194, 0, 94),10);
            if(cells[y_cell][x_cell]->get_type() == 0){
                txSetFillColor(TX_WHITE);
            }
            else{
                txSetFillColor(TX_BLACK);
            }

            txRectangle(260+x_cell*(side)+side_bold, 60+y_cell*(side)+side_bold, 260+(x_cell+1)*(side)-side_bold, 60+(y_cell+1)*(side)-side_bold);
        }
    }
}

void ChessField::check_click(){
    if(txMouseButtons() & 1){
        int mouse_x = txMouseX();
        int mouse_y = txMouseY();
        if((mouse_y >= 60 && mouse_x <= 940) && (mouse_x >= 260 && mouse_y <= 740)){
            if(cell_in_focus){
                cell_in_focus->set_focus(false);
            }
            cell_in_focus = cells[int((mouse_y - 60)/85)][int((mouse_x - 260)/85)];
            cell_in_focus-> set_focus(true);
            if(cell_in_focus->get_figure()){
                cell_in_focus->get_figure()->count_move_ability_cells(figures);
            }
        }
    }


}
