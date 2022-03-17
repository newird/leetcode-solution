#include <iostream>
#include<vector>
#include<string>
using namespace std;
#include<unordered_set>
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string>dict(words.begin(), words.end());
        string best;
        for(auto word:words){
            if(word.length()< best.length() || word.length() == best.length() && word > best) continue;
            string prefix; bool valid = true;
            for(int i = 0;i< word.length()-1 && valid; ++i){
                prefix+=word[i];
                if(!dict.count(prefix)) valid = false;
            }
            if(valid) best= word;
        }
        return best;
    }


};


int main() {
    Solution s;
    vector<string> words = {"w","wo","wor","worl", "world"};
    cout<<s.longestWord(words);
    return 0;
}
