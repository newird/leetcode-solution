#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int len1 = s.size();
        int len2 = p.size();
        if(len1 < len2) return res;
        int p_hash[26] = {0};
        int s_hash[26] = {0};
        for(int i = 0; i < len2; i++) {
            p_hash[p[i] - 'a']++;
            s_hash[s[i] - 'a']++;
        }
        for(int i = 0; i < len1 - len2 + 1; i++) {
            if(isAnagram(p_hash, s_hash)) res.push_back(i);
            s_hash[s[i] - 'a']--;
            int t = i + len2;
            s_hash[s[t] - 'a']++;
        }
        return res;
    }

    private:
    bool isAnagram(int p_hash[], int s_hash[]) {
        for(int i = 0; i < 26; i++) {
            if(p_hash[i] != s_hash[i]) return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    string s1 = "abab";
    string p1 = "ab";
    vector<int> res = s.findAnagrams(s1, p1);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
