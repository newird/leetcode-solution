#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        m = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n)));
        return dfs(boxes,0,n-1,0);
    }

private:
    vector<vector<vector<int>>> m;
    int dfs(const vector<int>& boxes,int l,int r,int k){
        if(l > r) return 0;
        while(l < r && boxes[r - 1] == boxes[r] ) {
                r--;k++;
        }
        if(m[l][r][k] > 0) return m[l][r][k] ;
        m[l][r][k] = dfs(boxes,l,r-1,0) + (k+1)*(k+1);
        for(int i = l;i < r ;++i){
            if(boxes[i] == boxes[r]){
                m[l][r][k] = max(m[l][r][k],dfs(boxes,l,i,k+1) + dfs(boxes,i+1,r-1,0));
            }
        }

        return m[l][r][k];

    }
};

int main() {
    Solution s;
    vector<int> box = {1,3,2,2,2,3,4,3,1};
    cout<<s.removeBoxes(box);
    return 0;
}
