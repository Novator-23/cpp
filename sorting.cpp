#include "sorting.h"
#include <utility>
#include <vector>

void bubble_sort(int* a, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
}

void selection_sort(int* a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int m = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[m]) m = j;
        std::swap(a[i], a[m]);
    }
}

void insertion_sort(int* a, int n) {
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; }
        a[j + 1] = key;
    }
}

static void merge_impl(int* a, int* t, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_impl(a, t, l, m);
    merge_impl(a, t, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) t[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (k = l; k <= r; ++k) a[k] = t[k];
}

void merge_sort(int* a, int n) {
    std::vector<int> t(n);
    merge_impl(a, t.data(), 0, n - 1);
}

static void quick_impl(int* a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[(lo + hi) / 2], i = lo, j = hi;
    while (i <= j) {
        while (a[i] < p) ++i;
        while (a[j] > p) --j;
        if (i <= j) std::swap(a[i++], a[j--]);
    }
    quick_impl(a, lo, j);
    quick_impl(a, i, hi);
}

void quick_sort(int* a, int n) {
    quick_impl(a, 0, n - 1);
}

static void sift_down(int* a, int i, int n) {
    for (;;) {
        int c = 2 * i + 1;
        if (c >= n) return;
        if (c + 1 < n && a[c + 1] > a[c]) ++c;
        if (a[i] >= a[c]) return;
        std::swap(a[i], a[c]);
        i = c;
    }
}

void heap_sort(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) sift_down(a, i, n);
    for (int e = n - 1; e > 0; --e) {
        std::swap(a[0], a[e]);
        sift_down(a, 0, e);
    }
}