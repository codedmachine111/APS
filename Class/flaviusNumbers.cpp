#include <bits/stdc++.h>
using namespace std;

bool isFlavius(int n){
    int i;
    for(i=2;;i++){
        if(n%i == 0) return 0;
        if(i>n) return 1;

        n = n - n/i;
    }
    return 0;
}

int main(){
    int n = 13;
    bool check = isFlavius(n);
    cout << check;

    return 0;
}