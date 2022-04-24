#include <iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<string> g;

    void split(string input){
        int i = 0, j = 0;
        while(j < input.size()){
            while(i < input.size() && input[i] == '\n') i++;
            j = i;
            while(j < input.size() && input[j] != '\n') j++;
            if(i < input.size()) g.push_back(input.substr(i, j-i));
            i = j;
        }
    }
    int getDepth(string& input){
        int ret = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '\t') ret++;
        }

        input = input.substr(ret);
        return ret;
    }
    int lengthLongestPath(string input) {
        stack<string> st;
        split(input);

        int cur = 0, ans = 0;
        for(int i = 0; i < g.size(); i++){
            int depth = getDepth(g[i]);


            while(st.size() > depth){
                cur = cur - st.top().size() - 1;
                st.pop();
            }


            st.push(g[i]);
            cur += g[i].size()+1    ;

            bool isFile = false;
            for(auto ch : g[i]) if(ch == '.') isFile = true;
            if(isFile) ans = max(ans, cur);
        }
        return ans - 1 < 0 ? 0 : ans - 1;
    }
};

int main() {
    Solution s;
    cout << s.lengthLongestPath(
            "dir\n\tfile.txt");

    return 0;
}
