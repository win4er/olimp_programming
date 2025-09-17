
== Insertion Sort

Разберем еще один $O(n^2)$ алгоритм - сортировка вставкой.

Алгоритм:
+ проходя по массиву начиная со 2 элемента, берем i-й элемент.
+ ищем позицию для вставки и сдвигаем элементы пока она не будет обнаружена.
+ вставляем элемент в подходящую позицию

#figure(
  image("../../images/insertion_sort2.png", width: 40%),
  caption: "Схема работы Insertion Sort",
)

*Реализация:*
#rect(
  ```cpp
  void insertion_sort(int* array, int size) {
    int j, temp;
    for (int i=0; i<size; ++i) {
        temp = array[i];
        j = i-1;
        while(j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
  }
  ```
)