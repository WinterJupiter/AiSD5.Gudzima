#include <iostream>
#include <fstream>
#include <chrono>
#include "Tree.h"


int main()
{
    int a[10];
    for (int j = 0; j < 10; ++j)
    {
        Map m;
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 400000; ++i)
        {
            m.insert(j * 400000 + i, "-");
        }
        auto end = std::chrono::steady_clock::now();
        auto dif = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        a[j] = dif.count();
        std::cout << dif.count() << std::endl;
        m.del();
    }
    int sum = 0;
    std::cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        sum += a[i];
    }
    int t = sum / 10;
    std::cout << t << std::endl;
    std::ofstream out("D:\\res.txt", std::ios::app);
    if (out.is_open())
        out << "For 400k elements: " << t << std::endl;
    return 0;
}