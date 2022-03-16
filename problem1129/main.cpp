#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> graph_r(n);
        vector<vector<int>> graph_b(n);
        vector<int> seen_r(n);
        vector<int> seen_b(n);
        vector<int> dis(n,-1);

        for(auto c: redEdges){
            graph_r[c[0]].push_back(c[1]);
        }
        for(auto c: blueEdges){
            graph_b[c[0]].push_back(c[1]);
        }
        seen_r[0] = 1;
        seen_b[0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});int step =0;
        while(!q.empty()){
            int s = q.size();
            while (s --){
                auto cur = q.front();q.pop();
                int is_red = cur.second;
                int cur_node = cur.first;
                dis[cur_node] =dis[cur_node]>0? min(dis[cur_node],step):step;
                auto &seen = is_red?seen_r:seen_b;
                auto graph = is_red?graph_r:graph_b;
                for(auto c:graph[cur_node]){
                    if(seen[c] == 1) continue;
                    seen[c] = 1;
                    q.push({c,1-is_red});
                }
            }
            ++step;
        }
        return dis;
    }
};

int main() {
    int n = 3;
    vector<vector<int>>red_edges = {{0,1},{1,2}};
    vector<vector<int>>blue_edges = {};
    Solution s;
    auto ans = s.shortestAlternatingPaths(n,red_edges,blue_edges);
    for(int c:ans){
        cout<<c<<" ";
    }
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
