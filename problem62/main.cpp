#include <iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
//        vector<vector<int>> dp(m+1,vector<int>(n+1));
//        for(int i = 0;i <=m ;++i) dp[i][1] = 1;
//        for(int j = 0;j <= n;++j) dp[1][j] = 1;
//        for(int i = 2; i<=m ;++i){
//            for(int j = 2; j<= n;++j){
//                dp[i][j] = dp[i-1][j] + dp[i][j-1];
//            }
//        }
//        return dp[m][n];
//    }
        vector<int> dp (n+1,1);
        for(int i = 2;i <=m ;++i){
            for(int j = 2;j <= n;++j){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    cout<<solution.uniquePaths(3,7);
    return 0;
}
