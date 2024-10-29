#include<bits/stdc++.h>
using namespace std;
void printheap(priority_queue<int , vector<int>, greater<int>>h){
    while(!h.empty()){
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}
int main(){
    priority_queue<int , vector<int>, greater<int>>h;
    int k=3 , count = 0;
    while(1){
        int data ;
        cin>> data ;
        if(data == -1){
            printheap(h);
            continue;
        }
        if(count <k){
            h.push(data);
            count++;        
    }
    else{
        if(h.top() < data ){
            h.pop();
            h.push(data);
        }
    }
    }
return 0;
}
