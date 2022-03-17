#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int palindromePartition(string s, int K) {
        const int n = s.length();
        vector<vector<int>> cost = vector<vector<int>>(n, vector<int>(n));
        for (int l = 2; l <= n; ++l) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j)
                cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];
        }

        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(K+1, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            dp[i][1] = cost[0][i];
            for(int k = 2; k<= K;++k){
                for(int j = 0;j < i;++j){
                    dp[i][k] = min(dp[j][k-1] + cost[j+1][i],dp[i][k]);
                }
            }
        }
        return dp[n-1][K];
    }
};


int main() {
    string str = "abc";
    Solution s;
    cout<<s.palindromePartition(str,2);
    return 0;
}
