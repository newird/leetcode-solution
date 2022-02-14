#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int res = 0;
        for(int a : nums){
            res ^= a;
        }
        return res;
    }
};
int main() {
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    Solution s;
    cout<<s.singleNonDuplicate(arr);
    return 0;
}
