
== Counting Sort

Но нижняя оценка временной сложности не подходит для сортировок, не основанных на сравнениях. Сортировка подсчетом основана на подсчете элементов и работает за $O(m)$, где m - диапазон чисел.

Рассмотрим первое приближение алгоритма, когда числа строго неотрицательные.

Логика алгоритма:

  1. инициализируется массив с max+1 количеством нулей, где max максимальный элемент массива.
  2. затем начинается проход по исходному массиву c подсчетом включений:
  counting_array[array[i]] += 1; 
  3. Затем сортируем исходный массив:
  array[index++] = i,
  повторяя counting_array[array[i]] раз, чтобы учесть повторения.

*Реализация*:

#rect(
  ```cpp
  void counting_sort(int* array, size_t size) {
    int max = array[get_ind_max(array, size)];
    int counting_array[max+1] = {0};
    for (int i=0; i<size; ++i) {
        counting_array[array[i]] += 1;
    }
    int index = 0;
    for (int i=0; i < max; ++i) {
        for (int j=0; j<counting_array[i]; ++j) {
            array[index++] = i;
        }
    }
  }
  ```
)

Но можно улучшить алгоритм, чтобы он учитывал и отрицательные числа:

#rect(
  ```cpp
  void counting_sort2(int* array, size_t size) {
    int max = array[get_ind_max(array, size)];
    int min = array[get_ind_min(array, size)];
    int counting_array[max-min+1] = {0};
    for (int i=0; i<size; ++i) {
        counting_array[array[i]-min] += 1;
    }
    int index = 0;
    for (int i=min; i < max; ++i) {
        for (int j=0; j<counting_array[i-min]; ++j) {
            array[index++] = i;
        }
    }
  }
  ```
)

_Теоретически можно сделать алгоритм рабочим не только для целых чисел, но для этого нужно использовать hashmap._(но это кал какой-то)
