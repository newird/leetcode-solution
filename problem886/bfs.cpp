#include <iostream>
#include <vector>
#include <queue>

using namespace  std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n);
        for(const auto d: dislikes){
            g[d[0] - 1].push_back(d[1] - 1);
            g[d[1] -1 ].push_back(d[0] - 1);
        }
        queue<int> q;
        vector<int> colors(n,0);

        for(int i = 0; i < n; ++ i){
            if(colors[i] != 0) continue;
            q.push(i);
            colors[i] = 1;
            while(!q.empty()){
                int cur = q.front();q.pop();
                for(const auto nxt:g[cur]){
                    if(colors[nxt] == colors[cur]) return false;
                    if(colors[nxt] != 0) continue;
                    colors[nxt] = -colors[cur];
                    q.push(nxt);
                }
            }
        }
        return true;

    }
};

int main() {
    Solution s;
    int n = 3;
    vector<vector<int>>  dislikes {{1,2},{1,3},{2,3}};
    cout<<s.possibleBipartition(n,dislikes);
    return 0;
}
