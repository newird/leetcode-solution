#include <iostream>
#include <vector>
#include <functional>
#include <queue>

#define N = 1e5+10
using namespace std;

class Solution {
public:

    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        const int n = patience.size();
        vector<vector<int>> graph = vector<vector<int>>(n);
        vector<int> visited(n, 0);
        vector<int> dis(n, INT_MAX / 2);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int src = 0;
        visited[0] = 1;
        dis[0] = 0;
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            for (auto nxt: graph[src]) {
                if (visited[nxt] == 1) continue;
                dis[nxt] = min(dis[nxt], dis[src] + 1);
                q.push(nxt);
            }

            while (!q.empty()) {
                if (visited[q.front()] == 1) {
                    q.pop();
                    continue;
                }
                src = q.front();
                break;
            }
            visited[src] = 1;

        }
        int a;
//        vector<int> ans(n,0);
        for(int i = 0; i< n;++i){
            int wait_time = dis[i] << 1;
            if(wait_time< patience[i]){
                a = max(a,wait_time+1);
            }else{
//                cout<<wait_time<<" "<<patience[i]<<endl;
                if(patience[i]) a = max(a,((wait_time<<1)-((wait_time>>1)/patience[i]-1)*patience[i] +1));
            }
        }
        return a;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2}};
    vector<int> patience = {0,2,1};
    cout<<solution.networkBecomesIdle(edges, patience);
//    cout<<4/3;
    return 0;
}
