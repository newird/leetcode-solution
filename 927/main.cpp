#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& a) {
        int n = a.size();
        int cnt = getOnes(a,0,n);
        if(cnt == 0){
            return {0,n-1};
        }
        else if(cnt % 3 ){
            return {-1,-1};
        }
        int c = cnt /3;
        int i = findOne(a,1),j = findOne(a,c+1),k = findOne(a,2*c+1 );
        for(; k < n && a[i] == a[j] && a[j] == a[k]; i++, j++, k++){}
        if(k == n){
            return {i-1,j};
        }else {
            return {-1,-1};
        }
    }
private:
    int getOnes(vector<int> a,int s,int e){
        int cnt = 0;
        for(int i = s;i< e;++i){
            if(a[i] == 1 )cnt++;
        }
        return cnt;
    }
    int  findOne(vector<int> a,int n){
        int cnt = 0;
        for(int i = 0;i < a.size();i++){
            if(a[i]) cnt++;
            if(cnt == n)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int > a =  {1, 1,0,  0, 1};
    s.threeEqualParts(a );
    return 0;
}
