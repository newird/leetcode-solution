#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        int l = 0, r = n - 1, up = 0, down = m - 1;
        int i = 0, j = 0,k = 0;
        while (true) {
            for (i = l; i <= r;k++, i++){
                ans.push_back(matrix[j][i]);
            }
            if(++up>down) break;i--;
            for (j = up; j <= down;k++, j++) {
                ans.push_back(matrix[j][i]);
            }
            if(--r<l) break;j--;
            for (i = r; i  >= l; k++,i--) {
                ans.push_back(matrix[j][i]);
            }
            if(--down>up) break;i++;
            for (j = down; j >= up; k++,j--) {
                ans.push_back(matrix[j][i]);
            }
            if(++l> r) break;j++;
        }
        return ans;

    }
};

int main() {
    vector<vector<int>> matric = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};
    Solution solution;
    auto ans = solution.spiralOrder(matric);
    for (auto c: ans) {
        cout << c << " ";
    }
    return 0;
}
