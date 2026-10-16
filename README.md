# Sorting library

Библиотека с алгоритмами сортировки: bubble, selection, insertion, merge, quick, heap.

## Сборка (Linux)

```
g++ -shared -fPIC -O2 -o libsorting.so sorting.cpp
g++ main.cpp -o main -L. -lsorting -Wl,-rpath,'$ORIGIN'
./main
```