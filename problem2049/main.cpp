#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int l[100001],r[100001]; int n;int size[100001] = {0};
    void weight(int n){
        size[n] = 1;
//        cout<<n<<endl;
        if(l[n]) {
            weight(l[n]);
            size[n] += size[l[n]];
//            cout<<"ln"<<size[l[n]]<<endl;
        }
        if(r[n]){
            weight(r[n]);
            size[n] += size[r[n]];
//            cout<<"rn"<<size[r[n]]<<endl;
        }

    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        for(int i = 1; i < n; ++i){
            int t = parents[i];
            if( l[t])
                r[t] = i;
            else
                l[t] = i;
        }
        weight(0);
//        for(auto i:size){
//           if(i) cout<<i<<endl;
//        }
//        return size[0];
        int y = 0;
        long long x = 0;
        for(int i = 0;i < n; ++ i){
            int p1,p2,p3;
            if(n - size[i])
                 p1 = n -size[i];
            else p1 =1;
            if (l[i]){
                p2 = size[l[i]];
            }
            else
                p2 = 1;
            p3 = r[i]?size[r[i]]:1;
//            cout<<"i="<<i<<endl;
//            cout<<l[i]<<" "<<r[i]<<endl;
//            cout<<size[l[i]]<<" "<<size[r[i]]<<endl;
//            cout<<"p1 "<<p1<<" p2 "<<p2<<" p3 "<<p3<<endl;

            if(1ll * p1 * p2 * p3 > x){
                x =1ll * p1 * p2 * p3 ;
                y = 1;
//                cout<<1<<x<<endl;
            }else if(1ll * p1 * p2 * p3 == x){
                y ++;
//                cout<<2<<x<<endl;
            }
        }
        return y;
    }

};

int main() {
    vector<int> parents  = {-1,2,0};
    Solution s;
    cout<<s.countHighestScoreNodes(parents);
    return 0;
}
