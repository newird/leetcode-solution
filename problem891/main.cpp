#include <iostream>
#include<vector>
#include <algorithm>

using namespace  std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        constexpr long kMod = 1e9+7;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long sum =0;
        long p = 1;
        for(int i = 0;i < n;++ i ){
            sum = (sum + (nums[i] - nums[n -i -1])*p  ) %kMod;
            p = p<<1 % kMod;
        }
        return sum;
    }

};


int main() {
//    1 2 3 4
//  [1 2] [2 3] [3 4] [1 3]*2 [2 4]*2 [1 4]*4=1+1+1+2+2+2+2+12=23
    vector<int> nums = {1,2,3};
    Solution s;
    cout<<s.sumSubseqWidths(nums);
//    cout << "Hello, World!" << std::endl;
    return 0;
}
