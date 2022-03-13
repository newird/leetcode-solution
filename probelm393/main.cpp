#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i = 0; i < n; ++i){
            if(data[i] < 128) continue;
            int cnt = 0;
            int j;
            for( j = 7;j > 0;--j){
                if((data[i] >> j) & 1) cnt++;
                else break;
            }
            if(cnt > 4 || i + cnt > n || cnt == 1) return false;

            for(j = 1; j <  cnt;++j){
                int t = i + j;
                if(data[t] < 128 || data[t] > 191) return false;
            }
            i = i + cnt -1;

        }
        return true;
    }
};
int main() {
    Solution s;
    vector<int> data = {240,162,138,147};
    cout<<s.validUtf8(data);

return 0;

}
