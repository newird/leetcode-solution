#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;int sum = 0;
        for(int c:nums){
            sum += c;
            if(sum > max) max= sum;
            if(sum < 0){
                sum = 0;
            }

        }
        return max;
    }
};

int main() {
    vector<int> nums = {-2};
    Solution s;
    cout<<s.maxSubArray(nums);
    return 0;
}
