#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char ch, int freq){
        left = right = NULL;
        this->data = ch;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(Node *left, Node *right){
        return left->freq > right->freq;
    }
};

void printHuffmanCodes(Node *root, string str){
    if(!root) return;

    if(root->data != '$'){
        cout << root->data << ":" << str << endl;
    }

    printHuffmanCodes(root->left, str+"0");
    printHuffmanCodes(root->right, str+"1");
}

void HuffmanCodes(char data[], int freq[], int size){
    Node *left, *right, *top;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(int i=0; i<size; i++){
        minHeap.push(new Node(data[i], freq[i]));
    }

    while(minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printHuffmanCodes(minHeap.top(), "");
}

int main(){
    char data[] = {'y', 'o', 'u', 'n', 'g'};
    int freq[] = {4,5,6,10, 15};

    int size = sizeof(data)/sizeof(data[0]);

    HuffmanCodes(data, freq, size);

    return 0;
}