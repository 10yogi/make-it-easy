#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node * links[26];
  bool flag = false;

  bool containsKey(char ch){
    return (links[ch-'a'] != NULL);
  }

  void setEnd(){
    flag = true;
  }

  Node * get(char ch){
    return links[ch-'a'];
  }

  void put(char ch, Node * node){
    links[ch-'a'] = node;
  }

  bool isEnd(){
    return flag;
  }

};

class Trie {
  private: 
    Node* root;
  public:
    Trie(){
      root = new Node();
    }

    void insert(string word){
      Node * tnode = root;
      for(char c : word){
        if(!tnode->containsKey(c)){
          tnode -> put(c, new Node());
        }
        tnode = tnode->get(c);
      }
      tnode->setEnd();
    }

    bool search(string word){
      Node* tnode = root;
      for(char ch: word){
        if(!tnode->containsKey(ch)){
          return false;
        }
        tnode = tnode->get(ch);
      }
      return tnode->isEnd();
    }

    bool startsWith(string prefix){
      Node* tnode = root;
      for(char ch: prefix){
        if(!tnode->containsKey(ch)){
          return false;
        }
        tnode = tnode->get(ch);
      }
      return true;
    }
};



// To execute C++, please define "int main()"
int main() {
  int n = 5;
  vector<int>type = {1, 1, 2, 3, 2};
  vector<string>value = {"hello", "help", "help", "hel", "hel"};
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
