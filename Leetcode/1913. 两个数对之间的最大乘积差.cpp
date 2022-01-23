class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = nums[0];
        int min1 = nums[0];
        int max_index = 0;
        int min_index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max1) {
                max1 = nums[i];
                max_index = i;
            }
            if(nums[i] < min1) {
                min1 = nums[i];
                min_index = i;
            }
        }
        int delete_num1;
        int delete_num2;
        if(max_index > min_index) {
            delete_num1 = max_index;
            delete_num2 = min_index;
        }
        else if(max_index < min_index) {
            delete_num2 = max_index;
            delete_num1 = min_index;
        }
        else {
            return 0;
        }
        nums.erase(nums.begin() + delete_num1);
        nums.erase(nums.begin() + delete_num2);
        int max2 = nums[0];
        int min2 = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max2) {
                max2 = nums[i];
            }
            if(nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return max1*max2 - min1*min2;
    }
};
