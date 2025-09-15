#import "../../template.typ": *

== Merge Sort

Наконец-то поговорим об алгоритме из категории "Разделяй и Властвуй". Для создания эффективного алгоритма сортировки нам недостаточно замены соседних элементов в случае bubble sort, здесь то и появляется merge sort с O(n log n) time. 

Вкратце алгоритм разделяет массив на подмассивы сортирует их, а затем склеивает их сортируя вновь.

Merge sort sorts a subarray array[a…b] as follows:
  1. if $a == b$, skip, cause a subarray with 1 element is already sorted.
  2. Calculate the position of the middle element:
  $ k =  ⌊(a + b)/2⌋ $
  3. Recursively sort the subarray array[a…k].
  4. Recursively sort the subarray array[k+1…b].
  5. Merge the sorted subarrays array[a…k] and array[k+1…b] into sorted subarray [a…b].

#rect(
  figure(
    image("../../images/merge_sort.png", width: 80%),
    caption: "Схема работы Merge Sort",
  )
)

#pagebreak()
*Реализация*
#rect(
  ```cpp
    // thx too my old friend..
    void merge(int* ar, size_t size) {
    int* res_ar = new int[size];
    int ind_res = 0;
    int middle = size >> 1;
    int left = 0;
    int right = middle;
    // sort array while left and right are in right range
    while (left < middle && right < size) {
        // store the least of subarrays into res
        if (ar[left] <= ar[right])
            res_ar[ind_res++] = ar[left++];
        else
            res_ar[ind_res++] = ar[right++];
    }
    // if numbers remain, then sort and store them too
    while (left < middle)
        res_ar[ind_res++] = ar[left++];
    while (right < size)
        res_ar[ind_res++] = ar[right++];
    // rewrite sorted array into primary
    for (size_t i=0; i<size; ++i) {
        ar[i] = res_ar[i];
    }
    delete [] res_ar;
}
void merge_sort(int* ar, size_t size) {
    if (size <= 1)
        return;
    // calculate middle (w/ bit shift)
    int middle = size >> 1;
    // dividing array into 2 subarrays
    merge_sort(&ar[0], middle);
    merge_sort(&ar[middle], size-middle);
    // merge them
    merge(ar, size);
  }
  ```
)

Временная сложность: $O(n log n) = O(n)O(log n)$

_Since there are O(log n) recursive levels, and processing each
level takes a total of O(n) time, the algorithm works in O(n log n) time._