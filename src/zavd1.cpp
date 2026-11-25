#define NOMINMAX
#include <windows.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const std::vector<int> source{7, 2, 9, 2, 5, 7, 1, 9, 5};
    std::vector<int> uniqueSorted = source;
    std::sort(uniqueSorted.begin(), uniqueSorted.end());
    const auto newEnd = std::unique(uniqueSorted.begin(), uniqueSorted.end());
    uniqueSorted.erase(newEnd, uniqueSorted.end());

    std::cout << "Початковий вектор: ";
    std::for_each(source.begin(), source.end(), [](int x) {
        std::cout << x << ' ';
    });
    std::cout << "\nЗначення за зростанням: ";
    std::for_each(uniqueSorted.begin(), uniqueSorted.end(), [](int x) {
        std::cout << x << ' ';
    });
    std::cout << '\n';

    return 0;
}