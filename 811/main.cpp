#include <iostream>
using namespace std;
#include<vector>
#include <set>
#include <map>
#include <sstream>

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& c) {
        map<string,int> vitime;
        for(auto cc:c) {
            stringstream out(cc);
            int time;
            string domain;
            out >> time >> domain;
            vitime[domain] += time;
            int pos = -1;
            while ((pos = domain.find(".", pos + 1)) != string::npos) {
                string s = domain.substr(pos + 1);
                vitime[s] += time;
            }
        }
        vector<string> ans;
        for(auto item : vitime){
            ans.push_back(to_string(item.second) +" " + item.first);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<string>  c = {"9001 discuss.leetcode.com"};
    s.subdomainVisits(c);
    return 0;
}
