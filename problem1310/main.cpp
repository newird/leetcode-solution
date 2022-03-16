#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int n = arr.size();
        vector<int> xors(n+1);
        for(int i = 0; i < n;++i){
            xors[i+1] = xors[i] ^ arr[i];
        }
        for(auto x:xors){
            cout<<x<<" ";
        }
        cout<<endl;
        vector<int> ans;
        for(auto q:queries){
            int a = xors[q[1]+1] ^ xors[q[0]];
            ans.push_back(a);
        }
        return ans;
    }

};

int main() {
    vector<int> arr={0,1,2,3};
    vector<vector<int>> queries= {{0,1},{0,2},{1,2},{0,3}};
    Solution s;
    auto ans = s.xorQueries(arr,queries);
    for(auto c:ans)
    cout<<c<<" ";
    return 0;
}
