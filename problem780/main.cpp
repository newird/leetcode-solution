#include <iostream>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty) return false;
        if (tx > ty) {
            if (sy == ty) return sx >= (tx % ty) && (tx - sx) % sy == 0;
            else return reachingPoints(sx, sy, tx % ty, ty);

        } else {
            if (sx == tx) return sy >= (ty % tx) && (ty - sy) % sx == 0;
            else return reachingPoints(sx, sy, tx, ty % tx);
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.reachingPoints(1, 1, 3, 5) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
