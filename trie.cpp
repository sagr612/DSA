#include<bits/stdc++.h>
using namespace std;
void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
struct Node {
	Node *links[26];
	bool flag = false;
	bool containsKey(char ch) {
		return links[ch - 'a'] != NULL;
	}
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	Node* get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool getEnd() {
		return flag;
	}
};
class Trie
{
private:
	Node *root;
public:
	Trie() {
		root = new Node();
	}
	void insert(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->getEnd();
	}
	bool startsWith(string prefix) {
		Node *node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containsKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};


int main() {
	fastio();
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "hdaelp", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
	return 0;
}