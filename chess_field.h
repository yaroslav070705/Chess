//#include "cell.h"
//#include "BaseFigure.h"
///< @file base_figure.h
///< @author Yaroslav, Roma, Anna

class ChessField{  ///< класс поля
 private:
    Cell* cells[8][8];                      ///< массив клеток поля
    vector<BaseFigure*> figures;            ///< массив фигур

    Cell* cell_in_focus = nullptr;          ///< указатель на клетку в фокусе
    BaseFigure* figure_in_focus = nullptr;  ///< указатель на фигуру в фокусе
    vector<BaseFigure*> white_dead_figures;
    vector<BaseFigure*> black_dead_figures;

    int spase_x = 280;                      ///< отступ по x
    int space_y = 55;                       ///< отступ по y
    int side = 85;                          ///< толщина
 public:
    ChessField();                           ///< конструктор
    void _add_cells();                      ///< добавление клеток
    void _add_figures();                    ///< добавление фигур
    void _draw_field();                     ///< рисование поля
    void _draw_figures();                   ///< рисование фигур
    void _draw_move_ability_cells();        ///< рисование возможности ходов
    void _draw_dead_figures();
    void draw();

   // void check_click();                     ///< проверка нажатия на клетку
   // void move_figure();                     ///< передвижение фигуры
    void check_click();


};

ChessField::ChessField(){
    _add_cells();
    _add_figures();
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
    /*figures.push_back(new Rook(0,0,1,TX_WHITE,TX_BLACK));
    cells[1][0]->set_figure(figures.back());
    figures.push_back(new Rook(1,5,7,TX_BLACK,TX_WHITE));
    cells[7][5]->set_figure(figures.back());
    figures.push_back(new Rook(0,5,1,TX_WHITE,TX_BLACK));
    cells[1][5]->set_figure(figures.back());
    figures.push_back(new Queen(1,3,5,TX_BLACK,TX_WHITE));
    cells[5][3]->set_figure(figures.back());
    figures.push_back(new King(0,6,7,TX_WHITE,TX_BLACK));
    cells[7][6]->set_figure(figures.back());
    figures.push_back(new King(1,2,4,TX_BLACK,TX_WHITE));
    cells[4][2]->set_figure(figures.back());
    figures.push_back(new Bishop(0,5,6,TX_BLACK,TX_WHITE));
    cells[6][5]->set_figure(figures.back());
    figures.push_back(new Pawn(1,1,4,TX_WHITE,TX_BLACK));
    cells[4][1]->set_figure(figures.back());*/
    for(int i = 7; i >= 0; i--){ // пешки белые
        figures.push_back(new Pawn(0,i,6,TX_WHITE,TX_BLACK));
        cells[6][i]->set_figure(figures.back());
    }

    for(int j = 7; j >= 0; j--){ // пешки чёрные
        figures.push_back(new Pawn(1,j,1,TX_BLACK,TX_WHITE));
        cells[1][j]->set_figure(figures.back());
    }

    // ладьи белые
    figures.push_back(new Rook(0, 0, 7,TX_WHITE,TX_BLACK));
    cells[7][0]->set_figure(figures.back());
    figures.push_back(new Rook(0,7,7,TX_WHITE,TX_BLACK));
    cells[7][7]->set_figure(figures.back());

    // ладьи чёрные
    figures.push_back(new Rook(1, 0, 0,TX_BLACK,TX_WHITE));
    cells[0][0]->set_figure(figures.back());
    figures.push_back(new Rook(1, 7, 0,TX_BLACK,TX_WHITE));
    cells[0][7]->set_figure(figures.back());

    // кони белые
    figures.push_back(new Knight(0, 1, 7,TX_WHITE,TX_BLACK));
    cells[7][1]->set_figure(figures.back());
    figures.push_back(new Knight(0, 6, 7,TX_WHITE,TX_BLACK));
    cells[7][6]->set_figure(figures.back());

    // кони чёрные
    figures.push_back(new Knight(1, 1, 0,TX_BLACK,TX_WHITE));
    cells[0][1]->set_figure(figures.back());
    figures.push_back(new Knight(1, 6, 0,TX_BLACK,TX_WHITE));
    cells[0][6]->set_figure(figures.back());

    // слоны белые
    figures.push_back(new Bishop(0, 2, 7,TX_WHITE,TX_BLACK));
    cells[7][2]->set_figure(figures.back());
    figures.push_back(new Bishop(0, 5, 7,TX_WHITE,TX_BLACK));
    cells[7][5]->set_figure(figures.back());

    // слоны чёрные
    figures.push_back(new Bishop(1, 2, 0,TX_BLACK,TX_WHITE));
    cells[0][2]->set_figure(figures.back());
    figures.push_back(new Bishop(1, 5, 0,TX_BLACK,TX_WHITE));
    cells[0][5]->set_figure(figures.back());

    // ферзь белый
    figures.push_back(new Queen(0, 3, 7,TX_WHITE,TX_BLACK));
    cells[7][3]->set_figure(figures.back());

    // ферзь чёрный
    figures.push_back(new Queen(1, 3, 0,TX_BLACK,TX_WHITE));
    cells[0][3]->set_figure(figures.back());

    // король белый
    figures.push_back(new King(0, 4, 7,TX_WHITE,TX_BLACK));
    cells[7][4]->set_figure(figures.back());

    // король чёрный
    figures.push_back(new King(1, 4, 0,TX_BLACK,TX_WHITE));
    cells[0][4]->set_figure(figures.back());

}

void ChessField::_draw_field() {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cells[i][j]->draw(i, j);
        }
    }

}

void ChessField::_draw_figures(){
    King* king;
    Bishop* bishop;
    Queen* queen;
    Pawn* pawn;
    for(auto figure:figures){
        king = dynamic_cast<King*>(figure);
        bishop = dynamic_cast<Bishop*>(figure);
        queen = dynamic_cast<Queen*>(figure);
        pawn = dynamic_cast<Pawn*>(figure);
        if(king){
            spase_x = 280;
            space_y = 50;
            figure->draw(figure->get_x_cell()*side+spase_x,figure->get_y_cell()*side+space_y,2);
        }
        else if(queen){
            spase_x = 280;
            space_y = 50;
            figure->draw(figure->get_x_cell()*side+spase_x,figure->get_y_cell()*side+space_y,4);
        }
        else if(bishop){
            spase_x = 290;
            space_y = 115;
            figure->draw(figure->get_x_cell()*side+spase_x,figure->get_y_cell()*side+space_y,5);
        }
        else if(pawn){
            spase_x = 288;
            space_y = 75;
            figure->draw(figure->get_x_cell()*side+spase_x,figure->get_y_cell()*side+space_y,5);
        }
        else{
            spase_x = 280;
            space_y = 55;
            figure->draw(figure->get_x_cell()*side+spase_x,figure->get_y_cell()*side+space_y,4);
        }
    }
}

void ChessField::_draw_move_ability_cells(){
    //cout<<"4"<<'\n';
    int side_bold = 5;
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
            txSetColor(RGB(194, 0, 94),12);
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

void ChessField::_draw_dead_figures(){
    King* king;
    Bishop* bishop;
    Queen* queen;
    Pawn* pawn;
    Knight* knight;
    int count_white = 0;
    int count_black = 0;
    for(auto figure:white_dead_figures){
        king = dynamic_cast<King*>(figure);
        bishop = dynamic_cast<Bishop*>(figure);
        queen = dynamic_cast<Queen*>(figure);
        pawn = dynamic_cast<Pawn*>(figure);
        knight = dynamic_cast<Knight*>(figure);
        if(king){
            figure->draw(10 + count_white*5,100,2);
        }
        else if(queen){
            figure->draw(10 + count_white*5,100,4);
        }
        else if(bishop){
            figure->draw(10 + count_white*20,400,5);
        }
        else if(pawn){
            figure->draw(30 + count_white*5,100,5);
        }
        else if(knight){
            figure->draw(10 + count_white*20,200,5);
        }
        else{
            figure->draw(10 + count_white*5,100,4);
        }
        count_white += 1;
    }
    for(auto figure:black_dead_figures){
        king = dynamic_cast<King*>(figure);
        bishop = dynamic_cast<Bishop*>(figure);
        queen = dynamic_cast<Queen*>(figure);
        pawn = dynamic_cast<Pawn*>(figure);
        knight = dynamic_cast<Knight*>(figure);
        if(king){
            figure->draw(1000 + count_black*5,100,2);
        }
        else if(queen){
            figure->draw(1000 + count_black*5,100,4);
        }
        else if(bishop){
            figure->draw(1010 + count_black*20,400,5);
        }
        else if(pawn){
            figure->draw(1000 + count_black*5,100,5);
        }
        else if(knight){
            figure->draw(980 + count_black*20,200,5);
        }
        else{
            figure->draw(1000 + count_black*5,100,4);
        }
        count_black += 1;
    }
}

void ChessField::draw(){
    _draw_field();
    _draw_move_ability_cells();
    _draw_figures();
    _draw_dead_figures();
}

/*void ChessField::check_click(){
    if(txMouseButtons() & 1){
        cout<<"22222";
        while(1){
            if(txMouseButtons() & 1){
            }
            else{
                cout<<"3333";
                break;
            }
        }
        int mouse_x = txMouseX();
        int mouse_y = txMouseY();
        if((mouse_y >= 60 && mouse_x < 940) && (mouse_x >= 260 && mouse_y < 740)){
            if(cell_in_focus){
                cell_in_focus->set_focus(false);
            }
            if(figure_in_focus){
                figure_in_focus = nullptr;
            }
            cell_in_focus = cells[int((mouse_y - 60)/85)][int((mouse_x - 260)/85)];
            cell_in_focus-> set_focus(true);
            if(cell_in_focus->get_figure()){
                figure_in_focus = cell_in_focus->get_figure();
                if(figure_in_focus->get_move_ability_cells().size() == 0){
                    cell_in_focus->get_figure()->count_move_ability_cells(figures);
                }
            }
        }
    }
}

void ChessField::move_figure(){
    if(figure_in_focus){
        int chosen_y_cell;
        int chosen_x_cell;
        if(txMouseButtons() & 1){
            while(1){
                if(txMouseButtons() & 1){
                }
                else{
                    cout<<"phjr";
                    break;
                }
            }
            cout<<"111";
            int mouse_x = txMouseX();
            int mouse_y = txMouseY();
            if((mouse_y >= 60 && mouse_x < 940) && (mouse_x >= 260 && mouse_y < 740)){
                chosen_y_cell = int((mouse_y - 60)/85);
                chosen_x_cell = int((mouse_x - 260)/85);
                for(auto cell:figure_in_focus->get_move_ability_cells()){
                    if((chosen_y_cell == cell[0]) && (chosen_x_cell == cell[1])){
                        figure_in_focus->set_y_cell(chosen_y_cell);
                        figure_in_focus->set_x_cell(chosen_x_cell);
                        cells[chosen_y_cell][chosen_x_cell]->set_figure(cell_in_focus->get_figure());
                        cell_in_focus->set_figure(nullptr);
                        //cell_in_focus = cells[chosen_y_cell][chosen_x_cell];
                        return;
                    }
                }
            }
        }
    }

} */

void ChessField::check_click(){
    if(txMouseButtons() & 1){
        while(txMouseButtons() & 1){
        }
        int mouse_x = txMouseX();
        int mouse_y = txMouseY();
        if((mouse_y >= 60 && mouse_x < 940) && (mouse_x >= 260 && mouse_y < 740)){
            int chosen_y_cell = int((mouse_y - 60)/85);
            int chosen_x_cell = int((mouse_x - 260)/85);
 ////////////////////////////////////////////////////
            if(cell_in_focus){
                cell_in_focus->set_focus(false);
            }
  ///////////////////////////
            if(figure_in_focus){
                for(auto cell:figure_in_focus->get_move_ability_cells()){
                    if((chosen_y_cell == cell[0]) && (chosen_x_cell == cell[1])){
                        figure_in_focus->set_y_cell(chosen_y_cell);
                        figure_in_focus->set_x_cell(chosen_x_cell);

                        //if(cells[chosen_y_cell][chosen_x_cell]){ //
                        for(int i = 0; i < figures.size(); i++){
                            if(figures[i] == cells[chosen_y_cell][chosen_x_cell]->get_figure()){
                                //delete figures[i];
                                if(figures[i]->get_type() == 0){
                                    white_dead_figures.push_back(figures[i]);
                                }
                                else{
                                    black_dead_figures.push_back(figures[i]);
                                }
                                figures.erase(figures.begin() + i);
                                break;
                            }
                        }
                       // }

                        cells[chosen_y_cell][chosen_x_cell]->set_figure(cell_in_focus->get_figure());
                        cell_in_focus->set_figure(nullptr);
                        cell_in_focus = cells[chosen_y_cell][chosen_x_cell];
                        break;
                    }
                }
            }
            cell_in_focus = cells[chosen_y_cell][chosen_x_cell];
            cell_in_focus-> set_focus(true);
            if(cell_in_focus->get_figure()){
                figure_in_focus = cell_in_focus->get_figure();
                cell_in_focus->get_figure()->count_move_ability_cells(figures);
            }
            else{
                figure_in_focus = nullptr;
            }
        }
    }
}
