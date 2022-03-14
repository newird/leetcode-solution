#include <iostream>
#include <vector>
#include <functional>
using namespace std;


class Solution {
public:
    int minimumDistance(string word) {
        const int n = word.size();
        vector<vector<vector<int>>>  distance =vector<vector<vector<int>>>(27,vector<vector<int>>(27,vector<int>(n)));
         function<int(int,int,int)> dp = [&](int l,int r,int i){
             if(i == n) return 0;
             if(distance[l][r][i]) return distance[l][r][i];
             int c = word[i] - 'A';
             if(l == c){
                distance[l][r][i] = dp(c,r,i+1);
                return distance[l][r][i];
             }
             if(r == c){
                distance[l][r][i] = dp(l,c,i+1);
                return distance[l][r][i];
             }
            distance[l][r][i] = min(dp(c,r,i+1)+ cost(l,c),dp(l,c,i+1)+ cost(r,c));
//            cout<<i<<" "<<l<<" "<<r<<" "<<distance[l][r][i]<<endl;
             return distance[l][r][i];
         };

         return dp(26,26,0);
    }

    int cost(char l, char r){
        if( l ==26 || r == 26) return 0;
        return abs(r % 6 - l%6) + abs(r/6 - l/6);

    }
};
int main() {
    string word = "HAPPY";
    Solution s;
    cout<<s.minimumDistance(word);
    return 0;
}
