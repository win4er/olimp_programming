#import "../template.typ": *

== Queue 
Очередь тоже предоставляет две O(1) операции:
- push(): добавление элемента в "конец" очереди
- pop(): удаление первого элемента из очереди

А также одну O(1) операцию доступа:
- front(): возвращает первый элемент очереди
Таким образом в очереди у нас есть доступ к первому и последнему элементам, а сама queue это FIFO(first in first out).
#rect(
```cpp
queue<int> q;
q.push(3); // {3}
q.push(2); // {3, 2}
q.push(5); // {3, 2, 5}
cout << q.front(); // 3
q.pop();
cout << q.front() // 2
```)
#show link: {underline}
Подробнее про очередь можно почитать #link("https://en.cppreference.com/w/cpp/container/queue.html")[здесь].
#figure(
  image("../images/queue.png", width: 100%),
  caption: [
    Схема работы очереди (да, тут другие названия, но суть та же)
  ],
)
