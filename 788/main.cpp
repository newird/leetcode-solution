#include<iostream>
using namespace std;
class Solution {
private:
    int reserve(int i){
        int log = 1;int ri = 0;
        while(i){
            int t = i % 10;
            switch (t){
                case 1:
                    t = 1;
                    break;
                case 2 :
                    t = 5;
                    break;
                case 5:
                    t = 2;
                    break;
                case 6:
                    t = 9;
                    break;
                case 9:
                    t= 6;
                    break;
                case 8:
                    t = 8;
                    break;
                case 0:
                    t = 0;
                    break;
                default :
                    return 0;
            }
            ri = t * log + ri;
            log *=10 ;
            i/= 10;
        }
        return ri;
    }
    bool check(int i,int ri){
        return i != ri;
    }
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1;i<= n;++i){
            int ri = reserve(i);
            if(ri){
                if(check(i,ri)) {
                    ans ++;
                    printf("%d %d\n",ri,i);
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.rotatedDigits(857);
    return 0;
}