#import "../template.typ": *

== Deque

это двуcторонняя очередь. Она предоставляет нам следующие O(1) методы:
- push_back()
- pop_back()
- push_front()
- pop_front()

А также O(1) операции доступа:
- back() 
- front()

#rect(
```cpp
deque<int> d;
d.push_back(5); // {5}
d.push_back(2); // {5, 2} 
d.push_front(3); // {3, 5, 2}
d.pop_back(); // {3, 5}
d.pop_front(); // {5}
```)
Внутреннее устройство сложнее чем у вектора, поэтому deque медленнее, но тем не менее O(1) есть.
#show link: {underline}
Подробнее о деке можно почитать #link("https://en.cppreference.com/w/cpp/container/deque.html")[здесь].

#figure(
  rect(image("../images/deque.png", width: 100%)),
  caption: [
    Схема работы дека
  ],
)

