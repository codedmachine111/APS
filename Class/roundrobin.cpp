#include <bits/stdc++.h>
using namespace std;

class LoadBalancer{
    private:
        vector<string> servers;
        int index;
    
    public:
        LoadBalancer(vector<string> servers){
            this->servers = servers;
            this->index = 0;
        }

        string getNextServer(){
            string next = servers[index];
            index  = (index +1) % servers.size();
            return next;
        }
};

int main(){

    vector<string> servers;
    servers.push_back("Server1");
    servers.push_back("Server2");
    servers.push_back("Server3");
    
    LoadBalancer lb(servers);
    int requests = 8;
    for(int i=0; i<requests; i++){
        string next = lb.getNextServer();
        cout << "Request " << i+1 << " directed to: " << next << endl;
    }

    return 0;
}