#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> root(n+1,0);
        vector<int> size(n+1,1);
        vector<int> parent(n+1,0);

        vector<int> ans1;
        vector<int> ans2;

        for(auto &edge:edges) {
            int u = edge[0];
            int v = edge[1];

            if (parent[v] > 0) {
                ans1 = {parent[v], v};
                ans2 = edge;
                edge[0] = edge[1] = -1;

            }

            parent[v] = u;
        }
//            parent[u] = u;
            for(auto &edge:edges){
                int u = edge[0];
                int v = edge[1];

                if(u < 0 || v < 0)continue;

                if(!root[u]) root[u] = u;
                if(!root[v]) root[v] = v;
                int pu = find(u,root);
                int pv =find(v,root);

                if(pu == pv) return ans1.empty()?edge:ans1;

                if(size[pu] < size[pv]){
                    swap(pu,pv);
                }
                root[pv] = pu;
                size[pu] += size[pv];
            }

        return ans2;
    }

private:

    int find(int c,vector<int>& p){
        while(c!= p[c]){
            p[c] = p[p[c]];
            c= p[c];
        }
        return c;
    }
};

int main() {
    vector<vector<int>>edges = {{2,1},{3,1},{4,2},{1,4}};
    Solution s;
    vector<int>  ans = s.findRedundantDirectedConnection(edges);
    for(auto v: ans) {
        cout << v << " ";
    }
    return 0;
}
