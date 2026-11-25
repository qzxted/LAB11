#define NOMINMAX
#include <windows.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>

int calculateClassicSTL(const std::vector<int>& data)
{
    std::vector<int> filtered;
    std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered),
        [](int x) { return x > 10; }
    );

    std::vector<int> transformed(filtered.size());
    std::transform(
        filtered.begin(),
        filtered.end(),
        transformed.begin(),
        [](int x) { return x - 2; }
    );

    return std::accumulate(transformed.begin(), transformed.end(), 0);
}

int calculateRangesViews(const std::vector<int>& data)
{
    auto pipeline = data
        | std::views::filter([](int x) { return x > 10; })
        | std::views::transform([](int x) { return x - 2; });

    return std::accumulate(pipeline.begin(), pipeline.end(), 0);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const std::vector<int> numbers{4, 12, 7, 15, 10, 20, 3};

    const int classicSum = calculateClassicSTL(numbers);
    const int rangesSum = calculateRangesViews(numbers);

    std::cout << "Вхідні дані- 4, 12, 7, 15, 10, 20, 3\n"
              << "Відібрані: 12, 15, 20  після -2: 10, 13, 18\n"
              << "Сума STL: " << classicSum << '\n'
              << "Сума std::ranges: " << rangesSum << '\n'
              << "Результати збігаються?: " << (classicSum == rangesSum ? "так" : "ні") << '\n';

    return 0;
}