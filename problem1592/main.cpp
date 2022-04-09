#include <iostream>
#include<math.h>
class Solution {
public:
    bool isThree(int n) {

        if(sqrt(n) == floor(sqrt(n))){
            int sqrt_n = sqrt(n);
            for(int i = 2; i <= sqrt_n; i++){
                if(n % i == 0){
                    if(i == sqrt_n){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                return false;
            }
        }
    }
};
int main() {
    Solution s;
    std::cout << s.isThree(16) << std::endl;
    return 0;
}
