#include <iostream>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    int array[n][m];

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            array[i][j] = 0;
        }
    }

    array[0][0] = 1;
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (i-2 >= 0 && j-1 >= 0) {
                array[i][j] += array[i-2][j-1];
            }
            if (i-1 >= 0 && j-2 >= 0) {
                array[i][j] += array[i-1][j-2];
            }
        }
    }

    std::cout << array[n-1][m-1];
    return 0;
}

/*
description:
Дана прямоугольная доска N×M (N строк и M столбцов).
В левом верхнем углу находится шахматный конь, которого необходимо переместить в правый нижний угол доски.
В данной задаче конь может перемещаться на две клетки вниз и одну клетку вправо или на одну клетку вниз и две клетки вправо.

Необходимо определить, сколько существует различных маршрутов, ведущих из левого верхнего в правый нижний угол.

exmpl#1:
input:
3 2

output:
1

exmpl#2:
input:
31 34

output:
293930

tags: dynamic programming 2D (but yes you can solve it without DP)

*/
