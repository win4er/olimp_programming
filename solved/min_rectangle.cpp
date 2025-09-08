#include <iostream>
#include <algorithm>


int main()  {
	int n;
    std::cin >> n;

    int max_x, max_y;
    int min_x, min_y;
    int x, y;
    for (int i=0; i<n; ++i) {
        std::cin >> x >> y;
        if (!i) {
            max_x = x;
            max_y = y;
            min_x = x;
            min_y = y;
            continue;
        }
        if (max_x < x)
            max_x = x;
        if (max_y < y)
            max_y = y;
        if (min_x > x)
            min_x = x;
        if (min_y > y)
            min_y = y;
    }

    std::cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << '\n';

	return 0;
}

/*
description:
На клетчатой плоскости закрашено K клеток.
Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все закрашенные клетки.

exmpl#1:
input:
3
1 1
1 10
5 5

output:
1 1 5 10

tags: linear search
 */
