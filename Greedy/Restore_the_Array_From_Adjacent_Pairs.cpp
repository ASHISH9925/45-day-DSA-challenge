class Solution {
public:
    //make a function dp that takes a map as an input and a number
    //then it performs dfs on all the relations of that map

    void dfs(map<int,vector<int>>& relations,map<int,bool>& visited,vector<int>& result,int num){

        visited[num] = true;
        result.push_back(num);
        
        for(int i :relations[num]){
            if(!visited[i]){
                dfs(relations,visited,result,i);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& ap) {
        map<int,vector<int>> relations;
        for(auto i:ap){
            relations[i[0]].push_back(i[1]);
            relations[i[1]].push_back(i[0]);
        }

        int head;
        for(auto i:relations){
            if(i.second.size() == 1){
                head = i.first;
            }
        }
        vector<int> result;
        map<int,bool> visited;

        dfs(relations,visited,result,head);

        return result;
    }
};