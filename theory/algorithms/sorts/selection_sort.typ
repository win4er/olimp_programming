
== Selection Sort

Сортировка выбором это грубо говоря оптимизированный пузырек. Вместо сравнения 2х соседних элементов по всему массиву, ищется минимальный от i до конечного.

Реализация алгоритма:

  1. Запускаем проход по индексам массива
  2. Ищем индекс минимального элемента от i до конечного
  3. Меняем i-й элемент с минимальным

Таким образом каждый раз поиск минимального элемента будет в уменьшаемом диапазоне. 

#figure(
  image("../../images/selection_sort.png", width: 75%),
  caption: [Схема работы Selection Sort]
)

*Реализация:*
#rect(
  ```cpp
  void selection_sort(int* array, int size) {
    for (int i=0; i<size; ++i) {
        int min = array[i];
        int ind_min = i;
        for (int j=i+1; j<size; ++j) {
            if (array[j] < min) {
                min = array[j];
                ind_min = j;
            }
        }
        array[ind_min] = array[i];
        array[i] = min;
    }
  }
  ```
)
Временная сложность: $O(n^2)$