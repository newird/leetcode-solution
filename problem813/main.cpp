#include <iostream>
#include <vector>
#include <list>

using namespace std;
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        const int n = nums.size();
        vector<double> sums(n+1,0.0);
        vector<double> ans(n+1,0.0);
        for(int i = 1;i<= n;++i){
            sums[i] = sums[i-1] + nums[i -1];
            ans[i] = static_cast<double>(sums[i]) / i;
        }
//        vector<double> ans(ave.begin(), ave.end());
        for(int k = 2;k <= K;++k){
            vector<double> tmp(n+1,0.0);
            for(int i = k;i <= n;++i)
                for(int j = k-1;j < i;++j)
                    tmp[i] = max(tmp[i],ans[j]+ (sums[i] - sums[j])/(i - j));
            ans.swap(tmp);
        }
        return ans[n];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,1,7,5,6,2,3};
    cout<<solution.largestSumOfAverages(nums,4);
    return 0;
}
