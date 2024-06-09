// Your university is organising an event, and you are on the organising committee.
// You have been given the task of managing the event budget. There are various clubs 
// and teams that require money for their tasks. You can only allot them money serially 
// (one after the other). Your goal is to select a contiguous sequence of tasks that 
// maximizes the total cost without exceeding the budget. 

#include <iostream>
#include <vector>
using namespace std;

int maxTasksWithinBudget(vector<int> tasks, int B){
    int n = tasks.size();
    int maxi = 0;

    int start = 0;
    int end=0;
    int currSum=0;

    while(end<n){
        currSum += tasks[end];

        while(currSum > B){
            currSum -= tasks[start];
            start++;
        }
        maxi = max(maxi, end-start+1);
        end++;
    }

    return maxi;
}

int main(){
    
    int N, B;
    cin >> N >> B;

    vector<int> tasks(N);
    for(int i=0; i<N; i++){
        cin >> tasks[i];
    }

    int ans = maxTasksWithinBudget(tasks, B);
    cout << ans;

    return 0;
}