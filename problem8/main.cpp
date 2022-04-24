#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int first = 0;
        long long ans = 0;
        const int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ' && first == 0) continue;
            if (s[i] == '-' && first == 0) {
                sign = -1;
                first = 1;
            } else if (s[i] == '+' && first == 0) {
                sign = 1;
                first = 1;
            } else if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + s[i] - '0';
                first = 1;
                if (ans *sign> 2147483647) return 2147483647;
                if (ans *sign< -2147483648) return -2147483648;
            } else {
                break;
            }
        }
        return ans*sign;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("123") << endl;
    return 0;
}
