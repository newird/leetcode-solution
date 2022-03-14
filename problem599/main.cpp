#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map1;
        unordered_map<string,int> map2;
        vector<string> order;
        int n1 = list1.size();
        int n2 = list2.size();
        for(int i = 0; i < n1; ++i){
            map1[list1[i]]=i;
        }
        int index = 0x7ffffffb;
        for(int i = 0; i < n2; ++ i) {
            if(map1.count(list2[i])){
                int t = i + map1[list2[i]] ;
                if(t< index){
                    order.clear();
                    index = t;
                    order.push_back(list2[i]);
                }else if(t == index){
                    order.push_back(list2[i]);
                }
            }
        }
        return order;

    }
};

int main() {
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    Solution s;
    vector<string> order = s.findRestaurant(list1,list2);
    for(auto c: order){
        cout<<c<<endl;
    }
    return 0;
}
