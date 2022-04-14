#include <iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        const int n = accounts.size();
        int max_asert = 0;
        for(int i = 0; i < n; ++i){
            max_asert = max(max_asert,accumulate(accounts[i].begin(),accounts[i].end(),0));
        }
        return max_asert;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
