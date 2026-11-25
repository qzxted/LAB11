#define NOMINMAX
#include <windows.h>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <optional>
#include <ranges>
#include <vector>

void task1Fixed()
{
    std::vector<int> v{1, -2, 3, -4, 5};
    v.erase(
        std::remove_if(v.begin(), v.end(), [](int x) { return x < 0; }),
        v.end()
    );

    std::cout << "Завдання 1  розмір: " << v.size() << ", елементи: ";
    for (int x : v)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void task2Analysis()
{
    int k = 2;
    auto byValue = [k](int x) { return x * k; };
    auto byRef = [&k](int x) { return x * k; };

    k = 10;
    std::cout << "Завдання 2  byValue = " << byValue(3)
              << ", byRef = " << byRef(3) << '\n';
}

std::vector<int> make()
{
    return {3, 1, 4};
}

void task3Fixed()
{
    const auto data = make();
    const auto it = std::ranges::max_element(data);
    if (it != data.end())
    {
        std::cout << "Завдання 3  максимальний елемент: " << *it << '\n';
    }
}

template <std::ranges::input_range R>
std::optional<double> average(R&& r)
{
    double sum = 0.0;
    std::size_t n = 0;
    for (auto&& x : r)
    {
        sum += static_cast<double>(x);
        ++n;
    }
    if (n == 0)
    {
        return std::nullopt;
    }
    return sum / static_cast<double>(n);
}

void task4Fixed()
{
    auto r = std::views::iota(1, 31)
        | std::views::filter([](int x) { return x % 3 == 0; })
        | std::views::transform([](int x) { return x * x; });

    const auto result = average(r);
    std::cout << "Завдання 4  середнє значення: ";
    if (result)
    {
        std::cout << *result << '\n';
    }
    else
    {
        std::cout << "відсутнє\n";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    task1Fixed();
    task2Analysis();
    task3Fixed();
    task4Fixed();
    return 0;
}