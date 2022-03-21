#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n  = nums.size();
        int k = 0;
        for(int i = 0; i<= k;++i){
            k = max(k,i+nums[i]);
        }
        return k > n-1;
    }
};

int main() {
    vector<int> nums = {3,2,1,0,4};
    Solution s;
    cout<<s.canJump(nums);
    return 0;
}
