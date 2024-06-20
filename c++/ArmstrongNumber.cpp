#include <iostream>
#include <cmath>
 
int main()  
{
    int sum, val;
 
    std::cout << "Armstrong numbers => ";
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                val = i * 100 + j * 10 + k;
                sum = pow(i, 3) + pow(j, 3) + pow(k, 3);
                if(val == sum)
                    std::cout << val << "  ";
            }
        }
    }
    std::cout << std::endl;
}
