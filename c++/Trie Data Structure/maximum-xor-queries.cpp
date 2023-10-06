#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node * children[2];

  bool containsKey(int ind) {
    return (children[ind] != NULL);
  }
  Node * get(int ind) {
    return children[ind];
  }
  void put(int ind, Node * node) {
    children[ind] = node;
  }
};

class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }

  public:
    void insert(int num) {
      Node * node = root;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};

vector < int > maxXorQueries(vector < int > & arr, vector < vector < int 
>> & queries) {
  vector < int > ans(queries.size(), 0);
  vector < pair < int, pair < int, int >>> offlineQueries;
  sort(arr.begin(), arr.end());
  int index = 0;
  for (auto & it: queries) {
    offlineQueries.push_back({
      it[1],
      {
        it[0],
        index++
      }
    });
  }
  sort(offlineQueries.begin(), offlineQueries.end());
  int i = 0;
  int n = arr.size();
  Trie trie;

  for (auto & it: offlineQueries) {
    while (i < n && arr[i] <= it.first) {
      trie.insert(arr[i]);
      i++;
    }
    if (i != 0) ans[it.second.second] = trie.findMax(it.second.first);
    else ans[it.second.second] = -1;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector < vector < int >> queries;

    for (int i = 0; i < m; i++) {
      vector < int > temp;
      int xi, ai;
      cin >> xi >> ai;
      temp.push_back(xi);
      temp.push_back(ai);
      queries.push_back(temp);
    }

    vector < int > ans = maxXorQueries(arr, queries);
    for (int j = 0; j < ans.size(); j++) {
      cout << ans[j] << " ";
    }
    cout << endl;
  }

}