#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        vector<long long> dp( 5,1);
        for(int i = 1; i< n;++i){
            vector<long long> temp(5,0);
            temp[0] = ((dp[1] + dp[2] ) % 1000000007 + dp[4] ) % 1000000007;
            temp[1] = (dp[0] + dp[2]) % 1000000007;
            temp[2] = (dp[1] + dp[3]) % 1000000007;
            temp[3] = dp[2] % 1000000007;
            temp[4] = (dp[2] + dp[3]) % 1000000007;
            dp = temp;
        }
        //return sum of dp
        long long ans = 0;
        for(auto i : dp) ans = (ans + i) % 1000000007;
        return (int)ans;
    }
};

int main() {
    Solution s;
    cout<<s.countVowelPermutation(158)<<endl;
    return 0;
}
