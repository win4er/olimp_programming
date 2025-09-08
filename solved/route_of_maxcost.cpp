#include <iostream>
#include <string>

struct Node {
    std::string path;
    int element;
};

int main() {
	int n, m;
	std::cin >> n >> m;

	int grid[n][m];
    Node array[n][m];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			std::cin >> grid[i][j];
            array[i][j].element = grid[i][j];
            array[i][j].path = "";
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (i == 0 && j == 0) continue;
			if (i == 0 || j == 0) {
				if (i == 0) {
                    array[i][j].element += array[i][j-1].element;
                    array[i][j].path = array[i][j-1].path + 'R';
                }
				if (j == 0) {
                    array[i][j].element += array[i-1][j].element;
                    array[i][j].path = array[i-1][j].path + 'D';
                }
			} else if (array[i][j-1].element >= array[i-1][j].element) {
                array[i][j].element += array[i][j-1].element;
                array[i][j].path = array[i][j-1].path + 'R';
            } else {
                array[i][j].element += array[i-1][j].element;
                array[i][j].path = array[i-1][j].path + 'D';
            }
            if (!(i == n-1 && j == m-1)) {
                array[i][j].path += ' ';
            }
		}
	}

	std::cout << array[n-1][m-1].element << '\n' << array[n-1][m-1].path;
	return 0;
}


/*
description:
В левом верхнем углу прямоугольной таблицы размером N × M находится черепашка.
В каждой клетке таблицы записано некоторое число.
Черепашка может перемещаться вправо или вниз, при этом маршрут черепашки заканчивается в правом нижнем углу таблицы.

Подсчитаем сумму чисел, записанных в клетках, через которую проползла черепашка (включая начальную и конечную клетку).
Найдите наибольшее возможное значение этой суммы и маршрут, на котором достигается эта сумма.

exmple#1:
input:
5 5
9 9 9 9 9
3 0 0 0 0
9 9 9 9 9
6 6 6 6 8
9 9 9 9 9

output:
74
D D R R R R D D

tags: dynamic programming 2D
*/
