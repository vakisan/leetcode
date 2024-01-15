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


    std::vector<int> productExceptSelf1(std::vector<int>& nums) {
        std::vector<int> answer;

        // 1st element in left array is 1 as there is no product
        // helps to avoid error when accessing i-1, It is the same as above.
        answer.push_back(1);

        // We repeat the same as above
        for(int i{1}; i<nums.size(); i++){
            answer.push_back(answer[i-1] * nums[i-1]);
        }

        // Instead of tracking the products in an array we can use an
        // cached number.
        int right{1};  

        // For each element starting from the right of nums,
        // we compute the product using the products on the left at each index
        // we then update the cached product on the right by multiplying it with the nums at the index.
        for(int i{int(nums.size()) - 1} ; i >= 0; i--){
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }

        // we return the answer at the end of it.
        return answer;
    }

    // Solution which does use division though.
    std::vector<int> productExceptSelf2(std::vector<int>& nums) {
        bool twoZero{false};
        bool oneZero{false};
        int product{1};
        for(int number: nums){
            if(number == 0){
                if(oneZero){
                    twoZero = true;
                }
                oneZero = true;
                continue;
            }
            product = number * product;
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(twoZero){
                 nums[i] = 0;
                 continue;
            }
            if(oneZero){
                if(nums[i] == 0){
                    nums[i] = product;
                }
                else{
                    nums[i]= 0;
                }
                continue;
            }
            nums[i] = product / nums[i];
        }
        return nums;
    }
};

int main(){
    Solution s; 
    std::vector<int> test{4,5,1,8,2};
    std::vector<int> answer;
    answer = s.productExceptSelf(test);
    for(int element: answer){
        std::cout << element << ","; 
    }
    std::cout << "\n";
    test = {4,5,1,8,2};
    answer = s.productExceptSelf1(test);
    for(int element: answer){
        std::cout << element << ","; 
    }
    std::cout << "\n";
    test = {4,5,1,8,2};
    answer = s.productExceptSelf2(test);
    for(int element: answer){
        std::cout << element << ","; 
    }
    std::cout << "\n";
}