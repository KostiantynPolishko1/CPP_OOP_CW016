#include "Point2D.h"
#include "Grid.h"
#include "menuWASD.h"
#include "Data.h"

int main()
{
    char** arrGrid = createGrid(sizeGrid);
    fillGrid(arrGrid, sizeGrid, symbolCell);

    Point2D p2d;
    Point2D p2d_copy(p2d);

    row = p2d_copy.getRow();
    col = p2d_copy.getCol();

    symbolStep = arrGrid[row][col];
    arrGrid[row][col] = symbolPlayer;
    //arrGrid[1][1] = symbolPrize;
    arrGrid[randomCell(sizeGrid, sizeOffset)][randomCell(sizeGrid, sizeOffset)] = symbolPrize;

    do {
        showGrid(arrGrid, sizeGrid, symbolCell);
        printMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);
        indexMenu(ind, sizeof(arrWASD) / sizeof(arrWASD[0]));
        system("CLS");

        if (!stepByGrid(ind, arrGrid, sizeGrid, row, col, symbolPlayer, symbolCell, symbolStep, p2d_copy))
            continue;

        if (ind == EXIT) {
            //p2d.~Point2D();
            //p2d_copy.~Point2D();
            break;
        }
        else if (ind != Z) {
            p2d_copy.setRow(row);
            p2d_copy.setCol(col);
            p2d_copy.increaseArrRowCol();
        }

    } while (symbolStep != symbolPrize);

    showGrid(arrGrid, sizeGrid, symbolCell);

    p2d.deleteArrRowCol(p2d.getArrRowCol(), p2d.getCount());
    p2d_copy.deleteArrRowCol(p2d_copy.getArrRowCol(), p2d_copy.getCount());
    deleteGrid(arrGrid, sizeGrid);

    return 0;
}
;