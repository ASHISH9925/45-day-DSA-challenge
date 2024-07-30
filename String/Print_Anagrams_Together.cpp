//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {

        map<map<char,int>,vector<string>> result;
        
        for(int i = 0;i<string_list.size();i++){
            map<char,int> freq;
            for(int j = 0;j<string_list[i].size();j++){
                freq[string_list[i][j]] += 1;
            }
            
            result[freq].push_back(string_list[i]);
        }
        
        vector<vector<string>> hello;
        
        for(auto i:result){
            hello.push_back(i.second);
        }
        
        return hello;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends