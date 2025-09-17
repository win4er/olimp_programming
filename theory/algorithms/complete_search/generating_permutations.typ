
== Generating Permutations

Next step is making permutations. For example the permutations for {0, 1, 2} are {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1} and {2, 1, 0}.

*Method 1*

Используя рекурсию, можно сгенерировать перестановки.

#rect(
  ```cpp
  vector<int> permutation;

  void search() {
    if (permutation.size() == n) {
      // process permutation
    } else {
      for (int i=0; i<n; ++i) {
        if (chosen[i]) continue;
        chosen[i]=true;
        permutation.push_back(i);
        search();
        chosen[i]=false;
        permutation.pop_back();
      }
    }
  }
  ```
)


Каждый вызов функции добавляет новый элемент в перестановку, учитывая те, которые уже созданы.

*Method 2*

Также есть метод из STL:

#rect(
  ```cpp
  vector<int> permutation;
  for (int i=0; i<n; ++i) {
    permutation.push_back(i);
  }
  do {
    // process permutation
  } while (next_permutation(permutation.begin(), permutation.end()));
  ```
)
