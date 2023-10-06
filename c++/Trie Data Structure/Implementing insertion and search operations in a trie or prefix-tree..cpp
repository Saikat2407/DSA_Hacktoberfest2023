#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
struct Node {
	Node *children[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (children[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		children[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return children[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

int main()
{
	int n = 6;
	vector<int>type = {1, 1, 2, 3, 2 ,1};
	vector<string>value = {"hello", "help", "help", "hel", "hel" ,"helloworld"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}
	}
}