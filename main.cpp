#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

void print(const char* title, const std::vector<int>& v) {
    std::cout << title << ": ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<int> original(10);
    for (int& x : original) x = std::rand() % 100;

    print("Исходный массив", original);
    std::cout << "\n";

    struct Algo {
        const char* name;
        void (*sort)(int*, int);
    };

    Algo algos[] = {
        {"bubble_sort",    bubble_sort},
        {"selection_sort", selection_sort},
        {"insertion_sort", insertion_sort},
        {"merge_sort",     merge_sort},
        {"quick_sort",     quick_sort},
        {"heap_sort",      heap_sort},
    };

    for (const Algo& a : algos) {
        std::vector<int> copy = original;
        a.sort(copy.data(), copy.size());
        print(a.name, copy);
    }
}