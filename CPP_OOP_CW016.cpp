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

    Row = p2d_copy.getRow();
    Col = p2d_copy.getCol();

    arrGrid[Row][Col] = symbol;

    do {
        showGrid(arrGrid, sizeGrid, empty);
        printMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);
        indexMenu(ind, sizeof(arrWASD) / sizeof(arrWASD[0]));
        system("CLS");

        if (!stepByGrid(ind, arrGrid, sizeGrid, Row, Col, symbol, empty))
            continue;

        p2d_copy.setRow(Row);
        p2d_copy.setCol(Col);
        p2d_copy.increaseArrRowCol();

    } while (true);

    deleteGrid(arrGrid, sizeGrid);

    return 0;
}
;