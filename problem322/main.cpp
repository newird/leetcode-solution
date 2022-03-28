#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        const int n = coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount ;++i){
            for(int j = 0; j< n;++j){
                if(coins[j] <= i) dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount] <= amount ? dp[amount]:-1;
    }
};

int main() {
    vector<int> coid = {1,2,5};
    Solution solution;
    cout<<solution.coinChange(coid,11);
    return 0;
}
