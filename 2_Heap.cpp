#include<bits/stdc++.h>
using namespace std;


class Minheap {
    private :
    void heapify(int i){
        int left = 2*i , right = left+1;
        int mi= i;
        if(left<v.size() and v[left] <v[mi]){
            mi= left;
        }
        if(right <v.size() and v[right] < v[mi]){
            mi= right;
        }
        if(i !=mi){
            swap(v[i] , v[mi]);
            heapify(mi);
        }

    }
public :
vector<int> v;
Minheap(){
    v.push_back(-1);
}
void push(int data){
v.push_back(data);
int c =v.size() -1;
int p = c/2;

while(p>0 and v[p] > v[c]){
    swap(v[p], v[c]);
    p/= 2;
    c/=2;
}
}

int top(){
return v[1];
}

void pop(){
swap(v[1] , v[v.size() -1]);
v.pop_back();
heapify(1);
}

bool empty(){
    return v.size()== 1;
}
};

int main(){
    Minheap h;
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(4);
    h.push(5);
    h.push(6);
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();

    }
    cout << endl;
    return 0;
    
}