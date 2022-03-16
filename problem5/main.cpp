#include <iostream>
#include<vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        function<int(int,int)> getlen =[&](int l,int r){
            while( l>=0 && r < n &&s[l] == s[r]) {
                l--;
                r++;
            }
            return r - l -1;
        };
        int max_len = 0;
        int start = 0;
        for(int i = 0; i < n; ++i){
            int len = max(getlen(i,i), getlen(i,i+1));
            if(len > max_len) {
                max_len = len;
                start = i - (len-1)/2;
            }

        }
        cout<<max_len<<" "<<start<<endl;
//        return "hello";
        return s.substr(start, max_len);

    }
};

int main() {
    Solution s;
    string str = "babad";
    cout<<s.longestPalindrome(str);
    return 0;
}
