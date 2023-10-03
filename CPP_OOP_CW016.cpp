#include "Point2D.h"
#include "Grid.h"
#include "menuWASD.h"
#include "Data.h"


int main()
{
    char** arrGrid = createGrid(sizeGrid);
    fillGrid(arrGrid, sizeGrid, empty);

    Point2D p2d;
    Point2D p2d_copy(p2d);

    row = p2d_copy.getRow();
    col = p2d_copy.getCol();

    arrGrid[row][col] = symbol;

    do {
        showGrid(arrGrid, sizeGrid, empty);
        printMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);
        indexMenu(ind, sizeof(arrWASD) / sizeof(arrWASD[0]));
        system("CLS");

        if (!stepByGrid(ind, arrGrid, sizeGrid, row, col, symbol, empty, p2d_copy))
            continue;

        if (ind != Z) {
            p2d_copy.setRow(row);
            p2d_copy.setCol(col);
            p2d_copy.increaseArrRowCol();
        }

    } while (true);

    deleteGrid(arrGrid, sizeGrid);

    return 0;
}
;