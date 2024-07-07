#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *children[26];
    bool wordEnd;

    Node(){
        wordEnd = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

void insert(Node *root, string &key){
    Node *cur = root;

    for(auto ch: key){
        if(cur->children[ch-'a'] == NULL){
            Node *newNode = new Node();
            cur->children[ch-'a'] = newNode;
        }

        cur = cur->children[ch-'a'];
    }

    cur->wordEnd = true;
}

bool search(Node *root, string &key){
    Node *cur = root;

    for(auto ch: key){
        if(cur->children[ch-'a'] == NULL) return false;

        cur = cur->children[ch-'a'];
    }

    return cur->wordEnd;
}

int main(){
    Node *root = new Node();

    vector<string> words = {"apple", "animal", "ball", "baseball", "balling"};
    vector<string> query = {"banana", "apple", "ball"};

    for(auto it: words){
        insert(root, it);
    }

    for(auto it: query){
        bool ans = search(root, it);
        cout << it << " : " << ans << endl;
    }

    return 0;
}