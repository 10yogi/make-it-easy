#include<bits/stdc++.h>
using namespace std;


struct Node {
  Node* links[2];

  bool containsKey(int k){
    return (links[k] != NULL);
  }  

  void put(int l, Node* node){
    links[l] = node;
  }

  Node* get(int l){
    return links[l];
  }
};

class Trie {
  private:
    Node* root;

  public:
    Trie(){
      root = new Node();
    }

    void insert(int n){
      Node * tnode = root;
      for(int i = 31; i >= 0; i--){
        int b = (n >> i) & 1;
        if(!tnode->containsKey(b)){
          tnode->put(b, new Node());
        }
        tnode = tnode->get(b);
      }
    }

    int maxXor(int n){
      Node * tnode = root;
      int res = 0;
      for(int i = 31; i>=0; i--){
        int b = (n>>i) & 1;
        if(tnode->containsKey(!b)){
          res |= (1<<i);
          tnode = tnode->get(!b);
        } else {
          tnode = tnode->get(b);
        }
      }
      return res;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2){
  Trie trie;
  for(int i = 0; i<n; ++i){
    trie.insert(arr1[i]);
  }
  int maxi = 0;
  for(int i = 0; i<m;++i){
    maxi = max(maxi, trie.maxXor(arr2[i]));
  }
  return maxi;
}

int main(){
  vector<int> arr1 = {6, 8};
  vector<int> arr2  = {7, 8, 2};
  int n = 2, m= 3;
  cout<<maxXOR(n, m, arr1, arr2)<<endl;
  return 0;
}
