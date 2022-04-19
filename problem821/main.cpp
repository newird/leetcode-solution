#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        const int n = s.length();
        vector<int> res(n, INT_MAX);
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == c) {

                while(i <= j){
                    res[i] = min(j - i, res[i]);
                    i++;
                }
                i--;
            }
        }
        i = n - 1;
        for (int j = n - 1; j >= 0; --j) {
            if (s[j] == c) {
                while(i >= j){
                    res[i] = min(i - j , res[i]);
                    i--;
                }
                i++;
            }
        }
        return res;
    }
};


int main(){

    Solution s;
    vector<int> ans = s.shortestToChar("aaabaab",'b');
    for(int i = 0; i<ans.size();i++){  cout<<ans[i]<<" ";}

    return 0;
}
