class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;// 左区间下标
        int right = nums.size() - 1; // 右区间下标
        int mid = (left + right) / 2; // 中间数下标
        while(left <= right) {
            if(nums[mid] > target) {
                right = mid - 1;
                mid = (left + right) / 2;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
