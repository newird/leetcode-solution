#include <iostream>
#include<Vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int m = img.size();
        const int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for(int x = i - 1; x <= i + 1; x++) {
                    for(int y = j - 1; y <= j + 1; y++) {
                        if(x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> result = solution.imageSmoother(img);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
