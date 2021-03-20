///< @file pawn_to_queen.h

#include <TXlib.h>
/// @author Кулик Михаил
/// \version 2.0
/// \data 12.03.21

/// \brief   Это функция превращения пешки в ферзя
/// \details Эта функция предназначена для того, чтобы когда пешка достигла конца поля она могла стать ферзем

void pawn_to_queen()
{
    bool broken = false; // Переменная отвечающая за то побитая фигура или нет (когда пешка становится ферзем она не должна попадать в битые фигуры), изначально true
    bool queen = false; // Переменная отвечающая за то выбран ли ферзь

    auto pPawn = dynamic_cast<Pawn>(pOther); // создаем указатель
    if pPawn //если пешка
    {
        int y = pPawn->get_y_cell()
        int x = pPawn->get_x_cell()

        if(y == 0) // если пешка имеет координату y == 0
        {
            if queen // если выбран ферзь
            {
                // Создаем Ферзя на месте пешки
                figures.push_back(new Queen(0, x, 0));
                cells[0][x]->set_figure(figures.back());
            }
        }
        else if(y == 7) // если пешка i имеет координату y == 7
        {
            if queen // если выбран ферзь
            {
                // Создаем Ферзя на месте пешки
                figures.push_back(new Queen(1, x, 7));
                cells[7][x]->set_figure(figures.back());
            }
        }
    }
}
