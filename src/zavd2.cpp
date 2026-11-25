#define NOMINMAX
#include <windows.h>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

class LessThan
{
public:
    explicit LessThan(int threshold) : threshold_(threshold) {}

    bool operator()(int value) const noexcept
    {
        return value < threshold_;
    }

private:
    int threshold_;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const std::vector<int> numbers{3, 12, 8, 25, 1, 10, 6};
    constexpr int threshold = 10;
    const auto countByFunctor = std::count_if(
        numbers.begin(),
        numbers.end(),
        LessThan(threshold)
    );

    const auto lessThanLambda = [threshold](int value) noexcept {
        return value < threshold;
    };

    const auto countByLambda = std::count_if(
        numbers.begin(),
        numbers.end(),
        lessThanLambda
    );

    std::cout << "Вектор: ";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << x << ' ';
    });

    std::cout << "\nПоріг: x " << threshold
              << "\nКількість LessThan: " << countByFunctor
              << "\nКількість лямбда виразу: " << countByLambda << '\n';

    return 0;
}