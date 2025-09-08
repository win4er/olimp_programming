#include <iostream>
#include <set>
int main() {
    std::set<int> numbers;

    int number;
    while(std::cin >> number) {
        numbers.insert(number);
    }
    std::cout << numbers.size();
	return 0;
}

/*
description:
Дан список чисел, который может содержать до 100000 чисел. Определите, сколько в нём встречается различных чисел.

exmpl#1:
input:
1 2 3 2 1

output:
3

tags: set, stl, sort
 */
