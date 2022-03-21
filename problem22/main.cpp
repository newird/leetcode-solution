#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return {""};
        vector<vector<string>> ans(n+1);
        ans[0] = {""};
        ans[1] = {"()"};
        for(int i = 2;i <= n;++i){
            for(int j = 0;j < i;++j){
                for(auto s1:ans[j]){
                    for(auto s2:ans[i-j-1]){
                        string s;
                        s = "("+s1+")" +s2;
                        ans[i].push_back(s);
                    }
                }
            }
        }
    return ans[n];

    }
};

int main() {
    Solution solution;
    auto str = solution.generateParenthesis(3);
    for(auto s:str){
        cout<<s<<" ";
    }
    return 0;
}
