#include "Point2D.h"
#include "Grid.h"
#include "menuWASD.h"
#include "Data.h"


int main()
{
    createGrid(arrGrid, size);
    showGrid(arrGrid, size);

    selectMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);
    printMenu(arrWASD, sizeof(arrWASD) / sizeof(arrWASD[0]), "WASD", ind);

    switch (ind)
    {
    case W:
        Row++;
        break;
    case A:
        Col--;
        break;
    case S:
        Row--;
        break;
    case D:
        Col++;
        break;
    default:
        exit(0);
    }

    //do {

    //} while (true);
  

    deleteGrid(arrGrid, size);
    return 0;
}
;
//const int size = 5;
//char arr[size][size]{};

//Point2D p2d;
//arr[p2d.getX()][p2d.getY()] = 'x';

//p2d.setX(1);
//p2d.setY(1);

//Point2D p2d_copy(p2d);