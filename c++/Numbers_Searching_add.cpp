// For this challenge you will traverse a string searching for all the numbers and then you will add them up
// have the function NumberSearch(str) take the str parameter, search for all the numbers in the string, add them together, then return that final number divided by the total amount of letters in the string. For example: if str is "Hello6 9World 2, Nic8e D7ay!" the output should be 2. First if you add up all the numbers, 6 + 9 + 2 + 8 + 7 you get 32. Then there are 17 letters in the string. 32 / 17 = 1.882, and the final answer should be rounded to the nearest whole number, so the answer is 2. Only single digit numbers separated by spaces will be used throughout the whole string (So this won't ever be the case: hello44444 world). Each string will also have at least one letter. 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int NumberSearch(string str) {

	int totalNum = 0;
	int totalLetters = 0;

	for (int x = 0; x < str.length(); x++)
	{
		if ((str[x] >= 'a' && str[x] <= 'z') || (str[x] >= 'A' && str[x] <= 'Z'))
		{
			totalLetters++;
		}
		else if (str[x] >= '0' && str[x] <= '9')
		{
			totalNum += int(str[x]) - 48;
		}
	}

	int total = round(double(totalNum) / totalLetters);
	return total;
}

int main() {

	// keep this function call here
	cout << NumberSearch("H3ello9-9") << endl; // 4
	cout << NumberSearch("One Number*1*") << endl; // 0
	cout << NumberSearch("Hello6 9World 2, Nic8e D7ay!") << endl; // 2
	return 0;

}