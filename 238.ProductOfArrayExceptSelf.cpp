#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {

        // Hold products on left of a specific index starting from first nums element
        std::vector<int> left;
        // Hold products on right of a specific index starting from last nums element
        std::vector<int> right;

        // there is no product on left or right of first or last element respectively.
        // we can set the product to 1 for these situations.
        left.push_back(1);
        right.push_back(1);

        for(int i{1}; i<nums.size(); i++){
            // calculate left product using the product at left[i-1] * nums[i-1]
            int left_product = left[i-1] * nums[i-1];
            // calculate right product using the product at right[i-1] * nums[nums.size()-i]
            // we need nums.size() - 1 because we want to get the element from the right side
            int right_product = right[i-1] * nums[nums.size() - i];
            // We then push back the products in to the left and right vectors for use in the next iteration
            left.push_back(left_product);
            right.push_back(right_product);
        }
        // we then modify in place the nums vector so that each index is calculated using the left and right vectors
        for(int i{0} ; i<nums.size(); i++){
            nums[i] = left[i] * right[nums.size() - 1 - i];
        }
        // return the modified nums vector.
        return nums;
    }
};

int main(){
    Solution s; 
    std::vector<int> test{4,5,1,8,2};
    test = s.productExceptSelf(test);
    for(int element: test){
        std::cout << element << "\n"; 
    }
}