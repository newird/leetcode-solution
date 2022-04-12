#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int count = 0;
        const int n = s.size();
        for(int i = 0;i < n; ++i){
            int index = s[i] - 'a';
            int width = widths[index];
            if(count + width > 100){
                line++;
                count = width;
            }else{
                count += width;
            }
        }
        return vector<int>{line, count};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
