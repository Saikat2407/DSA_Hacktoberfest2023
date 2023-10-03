#include <iostream>

using namespace std;

string integer_to_Roman(int n) {

  string str_romans[] = {
    "M",
    "CM",
    "D",
    "CD",
    "C",
    "XC",
    "L",
    "XL",
    "X",
    "IX",
    "V",
    "IV",
    "I"
  };
  int values[] = {
    1000,
    900,
    500,
    400,
    100,
    90,
    50,
    40,
    10,
    9,
    5,
    4,
    1
  };

  string result = "";

  for (auto int i = 0; i < 13; ++i) {
    while (n - values[i] >= 0) {
      result += str_romans[i];
      n -= values[i];
    }
  }

  return result;
}

int main() {
  int n = 7;
  cout << "Integer " << n << " : Roman " << integer_to_Roman(7) << endl;
  n = 19;
  cout << "Integer " << n << " : Roman " << integer_to_Roman(19) << endl;
  n = 789;
  cout << "Integer " << n << " : Roman " << integer_to_Roman(789) << endl;
  n = 1099;
  cout << "Integer " << n << " : Roman " << integer_to_Roman(1099) << endl;
  n = 23456;
  cout << "Integer " << n << " : Roman " << integer_to_Roman(23456) << endl;
  return 0;
