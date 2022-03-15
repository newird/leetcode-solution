#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       const int n = edges.size();
       vector<int> size(n+1,1);
       vector<int> parent(n+1,0);
       for(auto edge : edges){
           auto u = edge[0];
           auto v = edge[1];
           if(!parent[v]) parent[v] = v;
           if(!parent[u]) parent[u] = u;

           int pu = find(u,parent);
           int pv = find(v,parent);

           if( pu == pv) return edge;

           if(size[pu] < size[pv]){
               swap(pu,pv);
           }
           parent[pv] = pu;
           size[pu] += size[pv];
       }
       return {};
    }

private:
    int find(int c,vector<int> p){
        while(c != p[c]){
            p[c] = p[p[c]];
            c = p[c];
        }
        return c;
    }

};
int main() {
    vector<vector<int>> edge = {{2,1},{3,1},{4,2},{1,4}};
    Solution s;
    vector<int> a = s.findRedundantConnection(edge            );
    for(auto  c: a){
        cout<<c<<" ";
    }
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
