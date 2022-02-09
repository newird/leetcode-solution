//
// Created by newird on 2022/2/7.
//

#include "solution.h"
#include<vector>
#include<unordered_set>
#include <iostream>

using namespace std;
    class Solution {
    public:
        int subarrayBitwiseORs(vector<int>& A) {
            int n = A.size();

            vector<vector<int>> dp(n,vector<int>(n));
            unordered_set<int> ans(begin(A),end(A));
            for (int l =1;l <= n;l ++){
                for (int i = 0;i < n;i++){
                    int j = i +l -1;

                    if(l == 1){
                        dp[i][j] = A[i];
                        cout<<"a[i]"<<A[i]<<endl;
                    }else{
                        dp[i][j] = dp[i][j-1] | A[j];
                        cout<<"dp"<<i<<j<<dp[i][j]<<endl;
                        ans.insert(dp[i][j]);
                    }
                }
            }
            cout<<"ans="<<ans.size()<<endl;
            return ans.size();

        }

    };

    int main(){
        Solution s;
        vector<int> arr = {1,2,4};
        s.subarrayBitwiseORs(arr);
        return 0;
    }
