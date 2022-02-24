#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>> (n);
        for(const auto d:dislikes){
            graph[d[0] - 1].push_back(d[1] -1 );
            graph[d[1] -1 ].push_back(d[0] -1 );
        }

        colors = vector<int>(n,0);
        for(int i = 0; i < n; ++ i){
            if(colors[i] == 0 && !dfs(i,1)) return false;
        }
        return true;
    }

private:
    vector<vector<int>> graph;
    vector<int> colors;
    bool dfs(int cur,int color){
        colors[cur] = color;
        for( auto nxt:graph[cur]){
            if(colors[nxt] == colors[cur]) return false;
            if(colors[nxt]==0 && !dfs(nxt,-color)) return false;
        }
        return true;
    }
};


int main() {
    Solution2 s;
    int n = 3;
    vector<vector<int>>  dislikes {{1,2},{1,3},{2,3}};
    cout<<s.possibleBipartition(n,dislikes);
    return 0;
}
