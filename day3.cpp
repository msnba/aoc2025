#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int p1()
{
    std::ifstream input("day3input.txt");
    if (!input.is_open())
    {
        return -1;
    }
    string line;
    int sum = 0;
    while (getline(input, line)) // brute force
    {
        int maxVal = 0;
        for (int i = 0; i < line.size(); i++)
        {
            int d1 = line[i] - '0';
            for (int j = i + 1; j < line.size(); j++)
            {
                int d2 = line[j] - '0';
                int val = d1 * 10 + d2;
                if (val > maxVal)
                    maxVal = val;
            }
        }
        sum += maxVal;
    }

    return sum;
}
long long p2()
{
    std::ifstream input("day3input.txt");
    if (!input.is_open())
    {
        return -1;
    }
    string line;
    long long sum = 0;
    while (getline(input, line))
    {
        string result = "";
        int start = 0;
        int sizeCounter = 12;
        while (sizeCounter > 0) // in place to count top 12
        {
            char max = '0';                                          // using characters to build output easier
            int pos = start;                                         // index of max
            for (int i = start; i <= line.size() - sizeCounter; i++) // greedy algorithm that finds largest digit in terms of not going over size limit
            {
                if (line[i] > max)
                {
                    max = line[i];
                    pos = i;
                }
            }
            result += max;
            start = pos + 1; // the digits have to be in order l->r
            sizeCounter--;
        }
        sum += stoll(result); // i hate large numbers
    }

    return sum;
}

int main()
{
    cout << p1() << endl;
    cout << p2() << endl;
    return 0;
}