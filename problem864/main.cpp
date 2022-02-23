#include <iostream>
#include<vector>
#include <queue>

using namespace  std;

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int all_keys = 0;
        queue<int> q;
        vector<vector<vector<int>>> seen(m, vector<vector<int>>(n, vector<int>(64, 0)));
        //init
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const char c = grid[i][j];
                if (c == '@') {
                    q.push((i << 16) | (j << 8));
                    seen[i][j][0] = 1;
                } else if (c <= 'f' && c >= 'a') {
                    all_keys |= (1 << (c - 'a'));
                }
            }
        }

        const vector<int> dirs{-1, 0, 1, 0, -1};

        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int s = q.front();
                q.pop();
                int x = s >> 16;
                int y = (s >> 8) & 0xff;
                int key = s & 0xff;
                if (key == all_keys) return step;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dirs[i];
                    int ny = y + dirs[i + 1];
                    int nkey = key;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    const char c = grid[nx][ny];
                    if (c == '#') continue;
                    if (c >= 'A' && c <= 'F' && !(nkey & 1 << (c - 'A'))) continue;
                    if (c >= 'a' && c <= 'f') {
                        nkey |= (1 << (c - 'a'));
//                        cout<<1;
                    }
                    if (seen[nx][ny][nkey]) continue;
                    q.push((nx << 16) | (ny << 8) | nkey);
                    seen[nx][ny][nkey] = 1;
                }
            }
            ++step;

        }
        return -1;

    }
};


int main() {

    vector<string> grid = {"@..aA","..B#.","....b"};
    Solution s;
    cout<<s.shortestPathAllKeys(grid);
    return 0;
}
