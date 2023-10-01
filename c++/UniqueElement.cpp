#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//  code for getting unique elements of a vector
int main()
{
    vector<string> fruits{"apple", "banana", "apple", "cherry", "cherry"};
    vector<string> result;

    for (unsigned i = 0; i < fruits.size(); ++i)
    {
        if (count(result.begin(), result.end(), fruits.at(i)) == 0)
        {
            result.push_back(fruits.at(i));
        }
    }

    for (auto &element : result)
    {
        cout << element << "  ";
    }
}