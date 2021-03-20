///< @file chess_field.h

/**
 @author Yaroslav, Roma, Anna, Stephan

 ChessField - класс поля;
*/

class ChessField {  // класс поля
 private:
    /// массив клеток поля
    Cell* cells[8][8];
    /// вектор фигур
    vector<BaseFigure*> figures;

    /// указатель на клетку в фокусе
    Cell* cell_in_focus = nullptr;
    /// указатель на фигуру в фокусе
    BaseFigure* figure_in_focus = nullptr;
    /// вектор съеденных белых фигур
    vector<BaseFigure*> white_dead_figures;
    /// вектор съеденных белых фигур
    vector<BaseFigure*> black_dead_figures;

    /// переменная отступа по x
    int spase_x = 280;
    /// переменная отступа по y
    int space_y = 55;
    /// переменная толщины
    int side = 85;

    /// переменная смены хода
    int turn = 0;
    /// переменная выигравшей стороны
    int win_side;
    /// проверка смены хода
    bool turn_changed = false;

 public:
    /// конструктор
    ChessField();
    void _add_cells();                      // добавление клеток
    void _add_figures();                    // добавление фигур
    void _draw_field();                     // рисование поля
    void _draw_figures();                   // рисование фигур
    void _draw_move_ability_cells();        // рисование возможности ходов
    void _draw_dead_figures();
    void _draw_castling_cells();
    void draw();

   // void check_click();                     // проверка нажатия на клетку
   // void move_figure();                     // передвижение фигуры
    bool check_click();

    //void pawn_to_queen();

    void end(bool end_game);
};

ChessField::ChessField(){
    _add_cells();
    _add_figures();
}
/**
 Функция добавления клеток на поле;
*/
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
/**
 Функция добавления фигур на поле;
*/
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
/**
 Функция рисования поля;
*/
void ChessField::_draw_field() {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cells[i][j]->draw(i, j);
        }
    }
}
/**
 Функция рисования фигур на поле;
*/
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
/**
 Функция рисования возможности хода для фигур;

 Клетка, на которую может сходить ваша фигура, подсвечивается розовым цветом;
*/
void ChessField::_draw_move_ability_cells(){
    //cout<<"4"<<'\n';
    int side_bold = 5;
    vector <int*> move_ability_cells;
    if(cell_in_focus){
        if((cell_in_focus->get_figure()) && (figure_in_focus->get_type() == turn)){
            move_ability_cells = cell_in_focus->get_figure()->get_move_ability_cells();
        }
    }
    if(move_ability_cells.size() != 0){
        for(unsigned i=0;i<move_ability_cells.size();i++){
            int x_cell = move_ability_cells[i][1];
            int y_cell = move_ability_cells[i][0];
            txSetColor(RGB(194, 0, 94),12);
            txSetFillColor(TX_NULL);

            txRectangle(260+x_cell*(side)+side_bold, 60+y_cell*(side)+side_bold, 260+(x_cell+1)*(side)-side_bold, 60+(y_cell+1)*(side)-side_bold);
        }
    }
}
/**
 Функция рисования съеденных фигур;

 На экране рисуется специальное поле для съеденных фигур каждого цвета;
*/
void ChessField::_draw_dead_figures(){
    King* king;
    Bishop* bishop;
    Queen* queen;
    Pawn* pawn;
    Knight* knight;
    Rook* rook;
    int count_white_pawns = 0;
    int count_white_bishops = 0;
    int count_white_knights = 0;
    int count_white_rooks = 0;

    int count_black_pawns = 0;
    int count_black_bishops = 0;
    int count_black_knights = 0;
    int count_black_rooks = 0;
    for(auto figure:white_dead_figures){
        king = dynamic_cast<King*>(figure);
        bishop = dynamic_cast<Bishop*>(figure);
        queen = dynamic_cast<Queen*>(figure);
        pawn = dynamic_cast<Pawn*>(figure);
        knight = dynamic_cast<Knight*>(figure);
        rook = dynamic_cast<Rook*>(figure);
        if(king){
            figure->draw(10,450,2);
        }
        else if(queen){
            figure->draw(80,450,4);
        }
        else if(bishop){
            figure->draw(20 + count_white_bishops*60,400,5);
            count_white_bishops += 1;
        }
        else if(pawn){
            figure->draw(10 + count_white_pawns*10,100,5);
            count_white_pawns += 1;
        }
        else if(knight){
            figure->draw(10 + count_white_knights*50,200,5);
            count_white_knights += 1;
        }
        else if(rook){
            figure->draw(10 + count_white_rooks*60,600,4);
            count_white_rooks += 1;
        }
    }
    for(auto figure:black_dead_figures){
        king = dynamic_cast<King*>(figure);
        bishop = dynamic_cast<Bishop*>(figure);
        queen = dynamic_cast<Queen*>(figure);
        pawn = dynamic_cast<Pawn*>(figure);
        knight = dynamic_cast<Knight*>(figure);
        rook = dynamic_cast<Rook*>(figure);
        if(king){
            figure->draw(1000,450,2);
        }
        else if(queen){
            figure->draw(1080,450,4);
        }
        else if(bishop){
            figure->draw(1020 + count_black_bishops*60,400,5);
            count_black_bishops += 1;
        }
        else if(pawn){
            figure->draw(1000 + count_black_pawns*10,100,5);
            count_black_pawns += 1;
        }
        else if(knight){
            figure->draw(1000 + count_black_knights*50,200,5);
            count_black_knights += 1;
        }
        else if(rook){
            figure->draw(1010 + count_black_rooks*60,600,4);
            count_black_rooks += 1;
        }
    }
}
/**
 Функция рисование возможности рокировки для фигур;

 После нажатия на короля, при возможности рокировки, клетка ладьи подсвечивается жёлтым цветом;
*/
void ChessField::_draw_castling_cells(){
    int side_bold = 5;
    auto king = dynamic_cast<King*>(figure_in_focus);
    if(figure_in_focus){
        if(king){
           for(unsigned i=0;i < king->get_castling_cells().size();i++)
           {
                int x_cell = king->get_castling_cells()[i][1];
                int y_cell = king->get_castling_cells()[i][0];
                txSetColor(RGB(255, 251, 0),12);
                txSetFillColor(TX_NULL);
                txRectangle(260+x_cell*(side)+side_bold, 60+y_cell*(side)+side_bold, 260+(x_cell+1)*(side)-side_bold, 60+(y_cell+1)*(side)-side_bold);
           }
        }
    }
}
/**
 Совмещённая функция всех рисований;

 В неё включается: рисование поля, фигур на поле, возможности хода фигур, клеток рокировки, съеденных фигур;
*/
void ChessField::draw(){
    _draw_field();
    _draw_move_ability_cells();
    _draw_castling_cells();
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
/**
 Основная функция проверок нажатия на клетки поля;
*/
bool ChessField::check_click(){
    King* king = nullptr;
    King* king1 = nullptr;
    Rook* rook = nullptr;
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
            turn_changed = false;
            if(figure_in_focus){
                if(figure_in_focus->get_type() == turn){

                    for(auto cell:figure_in_focus->get_move_ability_cells()){
                        if((chosen_y_cell == cell[0]) && (chosen_x_cell == cell[1])){
                            //////////////
                            king1 = dynamic_cast<King*>(figure_in_focus);
                            rook = dynamic_cast<Rook*>(figure_in_focus);
                            if(king1) {
                               king1->set_step(1);
                            }

                            else if (rook) {
                                rook->set_step(1);
                            }
                            ////////////

                            figure_in_focus->set_y_cell(chosen_y_cell);
                            figure_in_focus->set_x_cell(chosen_x_cell);

                            if(turn == 0){
                                turn = 1;
                            }
                            else{
                                turn = 0;
                            }
                            turn_changed = true;

                            //if(cells[chosen_y_cell][chosen_x_cell]){ //
                            for(unsigned i = 0; i < figures.size(); i++){
                                if(figures[i] == cells[chosen_y_cell][chosen_x_cell]->get_figure()){
                                    //delete figures[i];
                                    if(figures[i]->get_type() == 0){
                                        white_dead_figures.push_back(figures[i]);
                                    }
                                    else{
                                        black_dead_figures.push_back(figures[i]);
                                    }
                                    king = dynamic_cast<King*>(figures[i]);
                                    if(figures[i]->get_type() == 0){
                                        win_side = 1;
                                    }
                                    else{
                                        win_side = 0;
                                    }
                                    figures.erase(figures.begin() + i);
                                    break;
                                }
                            }
                           // }

                            cells[chosen_y_cell][chosen_x_cell]->set_figure(cell_in_focus->get_figure());
                            cell_in_focus->set_figure(nullptr);
                           // cell_in_focus = cells[chosen_y_cell][chosen_x_cell];
                            break;
                        }
                    }
                    ///////////
                    king1 = dynamic_cast<King*>(figure_in_focus);
                    if(king1){
                        if(!turn_changed){
                            if(turn == 0){
                                turn = 1;
                            }
                            else{
                                turn = 0;
                            }
                        }
                        for(auto cell:king1->get_castling_cells()) {
                            if(chosen_y_cell == cell[0] && chosen_x_cell == cell[1]) {
                                if(chosen_x_cell == 7) {
                                    king1->set_x_cell(6);
                                    cells[chosen_y_cell][chosen_x_cell]->get_figure()->set_x_cell(5);
                                    cells[king1->get_y_cell()][5]->set_figure(cells[chosen_y_cell][chosen_x_cell]->get_figure());
                                    cells[king1->get_y_cell()][6]->set_figure(king1);
                                }
                                else if(chosen_x_cell == 0) {
                                    king1->set_x_cell(2);
                                    cells[chosen_y_cell][chosen_x_cell]->get_figure()->set_x_cell(3);
                                    cells[king1->get_y_cell()][3]->set_figure(cells[chosen_y_cell][chosen_x_cell]->get_figure());
                                    cells[king1->get_y_cell()][2]->set_figure(king1);
                                }
                                cell_in_focus->set_figure(nullptr);
                                cells[chosen_y_cell][chosen_x_cell]->set_figure(nullptr);
                                break;
                            }
                        }
                    }
                    ////////
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
            if(king){
                return true;
            }
        }
    }
    return false;
}

/*void ChessField::pawn_to_queen(){ ///< \parametr pOther - массив фигур
    bool broken = false; ///< Переменная отвечающая за то побитая фигура или нет (когда пешка становится ферзем она не должна попадать в битые фигуры), изначально true
    bool queen = false; ///< Переменная отвечающая за то выбран ли ферзь


    auto pPawn = dynamic_cast<Pawn*>(figures); ///< создаем указатель
    if pPawn ///< если пешка
    {
        int y = pPawn->get_y_cell()
        int x = pPawn->get_x_cell()

        if(y == 0) ///< если пешка имеет координату y == 0
        {
            if queen ///< если выбран ферзь
            {
                /// Создаем Ферзя на месте пешки
                figures.push_back(new Queen(0, x, 0));
                cells[0][x]->set_figure(figures.back());
            }
        }
        else if(y == 7) ///< если пешка i имеет координату y == 7
        {
            if queen ///< если выбран ферзь
            {
                /// Создаем Ферзя на месте пешки
                figures.push_back(new Queen(1, x, 7));
                cells[7][x]->set_figure(figures.back());
            }
        }
    }
} */
/**
 Функция вывода текста окончания игры;
 \param end_game  - флажок окончания игры;
*/
void ChessField::end(bool end_game){
    txSetFillColor(RGB(0, 191, 255));
    txSelectFont("Impact",100);
    txClear();
    if(end_game){
        if(win_side == 0){
            int x_cor = txGetTextExtentX("White side Win");
            int y_cor = txGetTextExtentY("White side Win");
            txSetColor(TX_WHITE);
            txTextOut((1200-x_cor)/2,(800-y_cor)/2,"White side Win");
        }
        else{
            int x_cor = txGetTextExtentX("Black side Win");
            int y_cor = txGetTextExtentY("Black side Win");
            txSetColor(TX_BLACK);
            txTextOut((1200-x_cor)/2,(800-y_cor)/2,"Black side Win");
        }
    }
    else{
        int x_cor = txGetTextExtentX("нИЧЬЯ!");
        int y_cor = txGetTextExtentY("нИЧЬЯ!");
        txSetColor(TX_GRAY);
        txTextOut((1200-x_cor)/2,(800-y_cor)/2,"НИЧЬЯ!");
    }
}

