#import "../template.typ": *

== Stack
Он предоставляет нам две O(1) операции:
- push(): добавление элемента "наверх"
- pop(): удаление элемента "сверху"
А также одну O(1) функцию доступа:
- top(): возвращение "верхнего" элемента

Таким образом в стеке у нас есть доступ только к элементу сверху(top).

Stack = FILO (first in last out)

#rect(
```cpp
stack<int> s;
s.push(3); // {3}
s.push(2); // {2, 3}
s.push(5); // {5, 2, 3} 
cout << s.top(); // 5
s.pop();
cout << s.top(); // 2
```)

#show link: {underline}
Подробнее о стеке можно почитать #link("https://en.cppreference.com/w/cpp/container/stack.html")[здесь].

#figure(
  image("../images/stack.png", width: 100%),
  caption: [
    Схема работы стека
  ],
)
