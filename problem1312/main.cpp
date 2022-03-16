#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        const int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int l = 2;l <=n ; ++l){
            for(int i =0,j = l -1;j < n;++i,++j){
                dp[i][j] = s[i] == s[j] ? dp[i+1][j-1]:min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
        return dp[0][n-1];
    }
};
int main() {
//    std::cout << "Hello, World!" << std::endl;
    string s = "vsrgaxxpgfiqdnwvrlpddcz";
    Solution solution;
    cout<<solution.minInsertions(s);
    return 0;
}
