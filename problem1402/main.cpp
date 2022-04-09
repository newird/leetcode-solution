#include <iostream>
#include<Vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0;int ans = 0;
        for (int i = n-1; i >= 0; --i) {
            int t = ans + sum + satisfaction[i];
            if(t > ans) {
                ans = t;
                sum += satisfaction[i];
            }else {
                break;
            }

        }
        return  ans;
    }
};

int main() {
    Solution s;
    vector<int> satisfaction = {4,3,2};
    cout << s.maxSatisfaction(satisfaction) << endl;
    return 0;
}
