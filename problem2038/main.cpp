#include <iostream>
#include<string>
#include<Vector>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        const int n = colors.length();
        int a=0,b = 0;
        int cnt_A =0 ,cnt_B = 0;
        for(int i = 0;i< n;++i){
            if( colors[i] == 'A'){
                cnt_A++;
                cnt_B=0;
                if(cnt_A>=3) a++;
            }else{
                cnt_B++;
                cnt_A = 0;
                if(cnt_B >= 3) b++;
            }

        }
        return a>b;

    }
};

int main() {
    string colosr= "AAABBBBBBBBBABB";
    Solution solution;
    cout<<solution.winnerOfGame(colosr);
    return 0;
}
