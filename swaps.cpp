#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

template<typename T>
struct CountingItem {
    CountingItem(const T& val = T()) : val_(val) {}

    bool operator<(const CountingItem<T>& rhs) const {
        ++compares;
        return val_ < rhs.val_;
    }

    static size_t compares;
    static size_t swaps;
    T val_;
};

template<typename T>
size_t CountingItem<T>::compares = 0;
template<typename T>
size_t CountingItem<T>::swaps = 0;

template<typename T>
void swap(CountingItem<T>& a, CountingItem<T>& b) {
    ++CountingItem<T>::swaps;
    std::swap(a, b);
}

int main()
{
    const size_t num_items = 10000;
    CountingItem<int> items[num_items];
    for(int i = 0; i < num_items; i++) items[i] = rand() % 100;
    sort(items, items+num_items);
    cout << "Compares = " << CountingItem<int>::compares << endl;
    cout << "Swaps    = " << CountingItem<int>::swaps << endl;

    // Reset CountingItem<int>::compares and swaps here if you're running another test
}
