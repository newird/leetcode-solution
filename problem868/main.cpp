#include <iostream>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int dis = 0;
        int i = 0;
        int j = 0;
        while (n > 0) {
            i++;
            if (n % 2 ) {
                if (j > 0) dis = max(dis, i - j );
                j = i;
            }

            n = n >> 1;
        }
        return dis;
    }
};

int main() {
    Solution s;
    cout << s.binaryGap(5) << endl;
    return 0;
}
