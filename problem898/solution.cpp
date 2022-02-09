//
// Created by newird on 2022/2/7.
//
#include<vector>
#include<unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int> &A) {
      unordered_set<int> ans;
      unordered_set<int> cur;
      unordered_set<int> next;
      for(int a: A){
        next.clear();
        next.insert({a});
        for(int b :cur){
            next.insert(a|b);
        }
        next.swap(cur);
        ans.insert(begin(cur),end(cur));
      }
      cout<<ans.size();
      return ans.size();
      }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 4};
    s.subarrayBitwiseORs(arr);
    return 0;
}
