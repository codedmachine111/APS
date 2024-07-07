#include <bits/stdc++.h>
using namespace std;

class ConsistentHashing{
    private:
        map<int, string> hashring;
        set<int> keys;
        int replicas;

        int getHash(const string &value){
            hash<string> hash_function;
            return hash_function(value);
        }
    
    public:
        ConsistentHashing(int replicas=3): replicas(replicas){}

        void addNode(const string &node){
            for(int i=0; i<replicas; i++){
                int rkey = getHash(node + "_" + to_string(i));
                hashring[rkey] = node;
                keys.insert(rkey);
            }
        }

        void removeNode(const string &node){
            for(int i=0; i<replicas; i++){
                int rkey = getHash(node + "_" + to_string(i));
                hashring.erase(rkey);
                keys.erase(rkey);
            }
        }

        string getNode(const string &key){
            if (hashring.empty()) return "";

            int hash = getHash(key);
            auto it = keys.lower_bound(hash);


            if(it==keys.end()){
                it =  keys.begin();
            }

            return hashring[*it];
        }
};

int main(){
    ConsistentHashing hashring;

    hashring.addNode("Node_1");
    hashring.addNode("Node_2");
    hashring.addNode("Node_3");

    string key = "First";
    string node = hashring.getNode(key);
    cout << key << " : " << node << endl;
    return 0;
}