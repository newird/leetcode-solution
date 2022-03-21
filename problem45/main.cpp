#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        if(n ==1) return 0;
        vector<int> ans(n,INT_MAX/2);
        for(int i = n-2;i >= 0;--i){
            if(i + nums[i] >= n -1) ans[i] = 1;
            else{
                for(int j = i; j<= i+nums[i];++j){
                    ans[i] = min(ans[i],ans[j]+1);
                }
            }
        }
        return ans[0];
    }
};

int main() {
    vector<int> nums={2,3,1,1,4};
    Solution solution;
    cout<<solution.jump(nums);
    return 0;
}
