#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n1 = word1.length();
        const int n2 = word2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int i = 0; i<= n1;++i) dp[i][0] = i;
        for(int j = 0; j<= n2;++j) dp[0][j] = j;
        for(int i = 1;i<=n1;++i){
            for(int j = 1;j <= n2;++j){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(word1[i-1] != word2[j-1]));
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    string word1 = "horse", word2 = "ros";
    Solution solution;
    cout<<solution.minDistance(word2,word1);
    return 0;
}
