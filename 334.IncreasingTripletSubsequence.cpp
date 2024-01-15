#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first{INT_MAX}, second{INT_MAX};
        for(int n: nums){
            if(n <= first){
                first = n;
            }
            else if(n <= second){
                second = n;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums {1,2,3,4,5,6};
    cout << s.increasingTriplet(nums) << "\n";
    nums = {6,5,4,3,2,1};
    cout << s.increasingTriplet(nums) << "\n";
    nums = {2,1,5,0,4,6};
    cout << s.increasingTriplet(nums) << "\n";
}