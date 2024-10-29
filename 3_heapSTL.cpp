#include<bits/stdc++.h>
using namespace std;

class comparator{
public :
//functor
bool operator()(int a, int b){
    return a<b ; // max heap , a>b min heap
 
}
};

int main(){
    // priority_queue<int> h;  // max heap
    priority_queue<int , vector<int> , comparator>h; // max and min for both
    // priority_queue<int , vector<int>,less<int>> h; // max heap without comparator

    h.push(1);
    h.push(17);
    h.push(6);
    h.push(11);
    h.push(13);
    h.push(0);
    while(!h.empty()){
        cout << h.top()<< " " ;
        h.pop();
    }
    cout << endl;
    return 0;
}