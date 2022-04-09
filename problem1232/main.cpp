#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const int n = coordinates.size();
        if(n <= 2) return true;
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int d1 = coordinates[0][0]-coordinates[1][0] , d2 = coordinates[0][1] - coordinates[1][1];
        for(int i = 2; i < n; i++) {
            if(d1*(coordinates[i][1]-y1) != d2*(coordinates[i][0]-x1)) return false;
        }  return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
