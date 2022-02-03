#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> rhymes;
    std::string str;
    int k, t, counter = 1, maxim = 0;
    std::cin >> k >> t;
    for (int i = 0; i <= k; i++)
    {
        std::getline(std::cin, str);
        if (t <= str.length())
            str = str.substr(str.length() - t);
        rhymes.push_back(str);
        for (int j = 1; j <= i; j++)
            if (rhymes[i] == rhymes[i - j])
                counter++;
        if (counter > maxim)
            maxim = counter;
        counter = 1;
    }
    std::cout << maxim << std::endl;
}