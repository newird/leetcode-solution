#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> ans(numRows);
        int n = s.length();
        int i = 1;
        ans[0] += s[0];
        while(i < n){
            for (int j = 1; i < n && j < numRows; ++j, ++i) {
                ans[j] += s[i];
            }
            for (int j = numRows - 2; i < n && j >= 0; --j, ++i) {
                ans[j] += s[i];
            }
        }

        string str;
        for(auto c: ans){
            str += c;
        }
        return str;
    }
};

int main() {
    string s = "0123456789";
    Solution solution;
    cout<<solution.convert(s,3);
    return 0;
}
