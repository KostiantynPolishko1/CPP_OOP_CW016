#include "Point2D.h"
#include "Grid.h"
#include "menuWASD.h"
#include "Data.h"


int main()
{
    char** arrGrid = createGrid(sizeGrid);
    fillGrid(arrGrid, sizeGrid, empty);

    Point2D p2d;
    Row = p2d.getRow();
    Col = p2d.getCol();

    arrGrid[Row][Col] = symbol;

    do {
        showGrid(arrGrid, sizeGrid, empty);
        printMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);
        indexMenu(ind, sizeof(arrWASD) / sizeof(arrWASD[0]));
        system("CLS");

        if(!stepByGrid(ind, arrGrid, sizeGrid, Row, Col, symbol, empty))
            continue;

        p2d.setRow(Row);
        p2d.setCol(Col);

        Point2D p2d_copy(p2d);

    } while (true);

    deleteGrid(arrGrid, sizeGrid);
    return 0;
}
;

//p2d.setX(1);
//p2d.setY(1);

//Point2D p2d_copy(p2d);