///< @file Start_part.h

#include <TXlib.h>
/** @author Michael Kulik
 Функция начальной расстановки фигур
*/

void start_part()
{
    for(int i = 7; i >= 0; i--) // пешки белые
    {
        figures.push_back(new Pawn(0,i,1));
        cells[6][i]->set_figure(figures.back());
    }

    for(int j = 7; j >= 0; j--) // пешки чёрные
    {
        figures.push_back(new Pawn(1,j,6));
        cells[1][j]->set_figure(figures.back());
    }

    // ладьи белые
    figures.push_back(new Rook(0, 0, 7));
    cells[7][0]->set_figure(figures.back());
    figures.push_back(new Rook(0,7,7));
    cells[7][7]->set_figure(figures.back());

    // ладьи чёрные
    figures.push_back(new Rook(1, 0, 0));
    cells[0][0]->set_figure(figures.back());
    figures.push_back(new Rook(1, 7, 0));
    cells[0][7]->set_figure(figures.back());

    // кони белые
    figures.push_back(new Knight(0, 1, 7));
    cells[7][1]->set_figure(figures.back());
    figures.push_back(new Knight(0, 6, 7));
    cells[7][6]->set_figure(figures.back());

    // кони чёрные
    figures.push_back(new Knight(1, 1, 0));
    cells[0][1]->set_figure(figures.back());
    figures.push_back(new Knight(1, 6, 0));
    cells[0][6]->set_figure(figures.back());

    // слоны белые
    figures.push_back(new Bishop(0, 2, 7));
    cells[7][2]->set_figure(figures.back());
    figures.push_back(new Bishop(0, 5, 7));
    cells[7][5]->set_figure(figures.back());

    // слоны чёрные
    figures.push_back(new Bishop(1, 2, 0));
    cells[0][2]->set_figure(figures.back());
    figures.push_back(new Bishop(1, 5, 0));
    cells[0][5]->set_figure(figures.back());

    // ферзь белый
    figures.push_back(new Queen(0, 3, 7));
    cells[7][3]->set_figure(figures.back());

    // ферзь чёрный
    figures.push_back(new Queen(1, 3, 0));
    cells[0][3]->set_figure(figures.back());

    // король белый
    figures.push_back(new King(0, 4, 7));
    cells[7][4]->set_figure(figures.back());

    // король чёрный
    figures.push_back(new King(1, 4, 0));
    cells[0][4]->set_figure(figures.back());
}
