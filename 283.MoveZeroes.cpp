#include <vector>
#include <iostream>
using namespace std;
class Solution {

    /*

    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    

    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Example 2:

    Input: nums = [0]
    Output: [0]
    

    Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
    

    Follow up: Could you minimize the total number of operations done?
    
    */

public:
     void moveZeroes1(vector<int>& nums) {
        vector<int>::iterator iterator;
        int count{0};
        for(iterator= nums.begin(); iterator < nums.end();iterator++){
            cout << *iterator << "\n";
            if(*iterator == 0){
                nums.erase(iterator);
                count++;
                iterator--;
            }
        }
        while(count > 0){
            nums.push_back(0);
            count--;
        }
    }

    void moveZeroes2(vector<int>& nums) {
        int lastNonZeroIndex{0};
        for(int i{0}; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[lastNonZeroIndex] = nums[i];
                lastNonZeroIndex++;
            }
        }
        while(lastNonZeroIndex < nums.size()){
            nums[lastNonZeroIndex++] = 0;
        }
    }

    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex{0};
        for(int i{0}; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[lastNonZeroIndex++],nums[i]);
            }
        }
    }
};

int main(){
    Solution s;
    // vector<int> nums{1,3,12,0,0};
    vector<int> nums{0,1,0,3,12};
    s.moveZeroes(nums);
    for(int n: nums){
        cout << n << "\n";
    }
}