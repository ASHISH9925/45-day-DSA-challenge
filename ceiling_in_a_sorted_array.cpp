#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int size;
    cin>>size;
    int n;
    cin>>n;
    vector<int> hello(size);
    for(int i = 0;i<size;i++){
        cin>>hello[i];
    }

    auto it = lower_bound(hello.begin(),hello.end(),n);
    int idx = it - hello.begin(); 

    if(idx != size){
        cout<<hello[idx];
    }
    else{
        cout<<-1;
    }
}