#include <bits/stdc++.h>
using namespace std;

int search(string text, string word, int q){
    int n = text.size();
    int m = word.size();

    int i,j;
    int p=0, t=0, h=1;
    int d = 256;

    for(i=0; i<m-1; i++){
        h = (h* d)%q;
    }

    for(i=0; i<m; i++){
        p = (d*p + word[i]) % q;
        t = (d*t + text[i]) % q;
    }

    for(i=0; i<=n-m; i++){
        if(p==t){
            for(j=0; j<m; j++){
                if(text[i+j] != word[j]) break;
            }
            if(j==m){
                return i;
            }
        }

        if(i < n-m){
            t = (d *(t-text[i]*h) + text[i+m])%q;

            if(t<0) t = t+q;
        }
    }
    return -1;
}

int main(){
    string text = "This is an example of explicit word detection, The word is HATE";
    string word = "HATE";

    int q = INT_MAX;

    int idx = search(text, word, q);
    if(idx!=-1){
        cout << "Word found at index : " << idx;
    }else{
        cout << "Word not found";
    }

    return 0;
}