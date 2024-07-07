#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
        int capacity;
        list<int> q;
        unordered_map<int, list<int>::iterator> mpp;

        LRUCache(int n){
            capacity = n;
        }

        void store(int x){
            if(mpp.find(x)==mpp.end()){
                // not found in cache
                if(q.size() == capacity){
                    int last = q.back();

                    q.pop_back();

                    mpp.erase(last);
                }
            }else{
                q.erase(mpp[x]);
            }

            q.push_front(x);
            mpp[x] = q.begin();
        }

        void display(){
            for(auto it: q){
                cout << (it) << " ";
            }
        }
};

int main(){
    LRUCache cache(4);

    cache.store(1);
    cache.store(2);
    cache.store(3);
    cache.store(1);
    cache.store(4);
    cache.store(5);

    cache.display();

    return 0;
}