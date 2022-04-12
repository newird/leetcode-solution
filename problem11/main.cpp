#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for(int i = 0,j = height.size()-1;i<j;)
        {
            int area = (j-i)*min(height[i],height[j]);
            max_area = max(max_area,area);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};
int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
