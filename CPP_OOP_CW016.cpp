#include "Point2D.h"
#include "Grid.h"
#include "menuWASD.h"
#include "Data.h"


int main()
{
    char** arrGrid = createGrid(sizeGrid);
    fillGrid(arrGrid, sizeGrid, empty);
    arrGrid[Row][Col] = symbol;

    do {
        showGrid(arrGrid, sizeGrid, empty);
        printMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);
        indexMenu(ind, sizeof(arrWASD) / sizeof(arrWASD[0]));
        system("CLS");

        stepByGrid(ind, arrGrid, sizeGrid, Row, Col, symbol, empty);

    } while (true);

    deleteGrid(arrGrid, sizeGrid);
    return 0;
}
;

//Point2D p2d;
//arr[p2d.getX()][p2d.getY()] = 'x';

//p2d.setX(1);
//p2d.setY(1);

//Point2D p2d_copy(p2d);