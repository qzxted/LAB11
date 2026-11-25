#define NOMINMAX
#include <windows.h>

#include <cstddef>
#include <iostream>
#include <numeric>
#include <optional>
#include <ranges>
#include <vector>

namespace
{
    struct SquaresAccumulator
    {
        unsigned long long sum = 0;
        std::size_t count = 0;
    };

    template <std::ranges::input_range R>
    SquaresAccumulator accumulateSquares(R&& range)
    {
        return std::accumulate(
            std::ranges::begin(range),
            std::ranges::end(range),
            SquaresAccumulator{},
            [](SquaresAccumulator acc, int value) {
                acc.sum += static_cast<unsigned long long>(value);
                ++acc.count;
                return acc;
            }
        );
    }

    template <std::ranges::input_range R>
    std::optional<double> averageSquares(R&& range)
    {
        const SquaresAccumulator stats = accumulateSquares(range);
        if (stats.count == 0)
        {
            return std::nullopt;
        }
        return static_cast<double>(stats.sum) / static_cast<double>(stats.count);
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    auto squaresView = std::views::iota(1, 101)
        | std::views::filter([](int x) { return x % 3 == 0; })
        | std::views::transform([](int x) { return x * x; });

    const SquaresAccumulator stats = accumulateSquares(squaresView);
    const std::optional<double> avg = averageSquares(squaresView);

    std::cout << "Діапазон: std::views, кратні 3, квадрат\n"
              << "Кількість елементів: " << stats.count << '\n'
              << "Сума квадратів: " << stats.sum << '\n'
              << "Середнє арифметичне квадратів: ";
    if (avg.has_value())
    {
        std::cout << *avg << '\n';
    }
    else
    {
        std::cout << "std::nullopt\n";
    }

    const std::vector<int> emptyVec{};
    const auto emptyAvg = averageSquares(emptyVec);
    std::cout << "Порожній діапазон середнє: ";
    if (emptyAvg.has_value())
    {
        std::cout << *emptyAvg << '\n';
    }
    else
    {
        std::cout << "std::nullopt\n";
    }

    return 0;
}