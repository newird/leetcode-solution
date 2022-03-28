#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        if(n ==1) return nums[0];
        vector<int> dp(n+1);
        dp[1] = nums[0];
        for(int i = 2; i <= n;++i){
            dp[i] = max(dp[i-2]+nums[i-1] ,dp[i-1]);
        }
        return dp[n];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
