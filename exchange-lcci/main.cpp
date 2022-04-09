#include <iostream>
class Solution {
public:
    int exchangeBits(int num) {
        int a = num & 0x55555555;
        int b = num & 0xaaaaaaaa;
        return (a << 1) | (b >> 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
