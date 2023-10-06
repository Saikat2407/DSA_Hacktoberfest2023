#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node * children[26];

  bool containsKey(char ch) {
    return ( children[ch - 'a'] != NULL);
  }

  Node * get(char ch) {
    return  children[ch - 'a'];
  }

  void put(char ch, Node * node) {
     children[ch - 'a'] = node;
  }
};

int countDistinctSubstrings(string & s) {
  Node * root = new Node();
  int count = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    Node * node = root;

    for (int j = i; j < n; j++) {
      if (!node -> containsKey(s[j])) {
        node -> put(s[j], new Node());
        count++;
      }
      node = node -> get(s[j]);
    }

  }
  return count + 1;
}

int main() {
  string s1 = "ababaccba";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s1);
  cout << endl;

  string s2 = "ccfdfdc";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s2);

  return 0;
}