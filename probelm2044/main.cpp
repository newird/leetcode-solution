#include <iostream>
#include<vector>
#include <functional>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        const int n = nums.size();
        int cnt = 0;
        int maxnum = 0;
        function<void(int, int)> dp = [&](int i, int ans){
           ;if (i == n ) {
            if (ans > maxnum) {
                maxnum = ans;
                cnt = 1;
            } else if (ans == maxnum) {
                cnt++;
            }return;
           }
            dp(i + 1, ans | nums[i]);
            dp(i + 1, ans);
           };
        dp(0, 0);
//        dp(0, 0, 0);
        return cnt;
    }
};

int main() {
    vector<int> nums = {3,1};
    Solution s;
    cout << s.countMaxOrSubsets(nums);

    return 0;
}
