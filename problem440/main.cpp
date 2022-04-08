#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findKthNumber(int n, int k) {
        if( n < 10 ) return k;
        int base = 1;
        while(n / base >= 10) base *= 10;
        int left = 1, right = base;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i = 1; i <= n; i++) {
                if(i >= mid && i <= mid + base) count += min(i, mid + base) - max(i, mid);
            }
            if(count < k) left = mid + 1;
            else right = mid;
        }  // left = right
        return left + k - 1;

    }
};

int main() {
    Solution solution;
    cout << solution.findKthNumber(13, 1) << endl;
    return 0;
}
