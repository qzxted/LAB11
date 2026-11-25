#define NOMINMAX
#include <windows.h>

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> removeLastElement(const std::vector<int>& input)
{
    if (input.empty())
    {
        return {};
    }
    return std::vector<int>(input.begin(), input.end() - 1);
}

void printVector(const std::vector<int>& vec)
{
    std::cout << '[';
    bool first = true;
    std::for_each(vec.begin(), vec.end(), [&](int x) {
        if (!first)
        {
            std::cout << ", ";
        }
        first = false;
        std::cout << x;
    });
    std::cout << ']';
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const std::vector<int> original{10, 20, 30, 40};

    std::cout << "Початковий вектор: ";
    printVector(original);
    std::cout << '\n';

    const std::vector<int> withoutLast = removeLastElement(original);

    std::cout << "Початковий вектор після виклику: ";
    printVector(original);
    std::cout << "\nНовий вектор: ";
    printVector(withoutLast);
    std::cout << '\n';
    const std::vector<int> emptyInput{};
    const std::vector<int> emptyOutput = removeLastElement(emptyInput);
    std::cout << "Порожній вектор: ";
    printVector(emptyOutput);
    std::cout << " (розмір = " << emptyOutput.size() << ")\n";

    return 0;
}