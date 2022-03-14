#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;int r = height.size()-1;
        int max_l=height[l],max_r = height[r];
        int ans = 0;
        while(l < r){
            if(max_l < max_r){
                ans += max_l - height[l];
                max_l = max(max_l,height[++l]);
            }else{
                ans += max_r - height[r];
                max_r = max(max_r,height[--r]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.trap(height);
    return 0;
}
