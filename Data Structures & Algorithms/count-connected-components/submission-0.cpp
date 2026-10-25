class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, vector<bool>& visited){
        if(i<0 || i >= g.size() || visited[i]) return;
        stack<int>s;
        s.push(i);
        visited[i] = true;
        while(!s.empty()){
            auto t = s.top();
            s.pop();
            for(auto j: g[t]){
                if(!visited[j]){
                    s.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // do dfs and every more dfs call required is the ans
        int c = 0;
        // first create a graph of adj list
        vector<vector<int>>g(n+1);
        for(auto i: edges){
            int x = i[0], y = i[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // then number of dfs calls will be ans
        vector<bool>visited(n+1, false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(g, i, visited);
            }
        }
        return c;
    }
};
