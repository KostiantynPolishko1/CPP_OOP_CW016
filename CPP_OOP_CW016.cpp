#include <iostream>
#include "Point2D.h"

using std::cout;

int main()
{
    std::cout << "Start!\n";

    const int size = 5;
    char arr[size][size]{};

    Point2D p2d;
    arr[p2d.getX()][p2d.getY()] = 'x';

    for (short i = 0; i < size; i++) {
        for (short j = 0; j < size; j++) {
            if (arr[i][j]) {
                cout << arr[i][j] << " ";
                continue;
            }
            cout << "-" << " ";
        }
        cout << "\n";
    }

    p2d.setX(1);
    p2d.setY(1);

    Point2D p2d_copy(p2d);



    return 0;
}