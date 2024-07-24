#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    //accept the string from stdin
    string input_string;
    cin>>input_string;

    unordered_map<char,int> hello;

    for(char i : input_string){
        hello[i] += 1;
    }

    for(auto i : hello){
        if(i.second >= 2){
            cout<<i.first;
        }
    }
}