class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;// �������±�
        int right = nums.size() - 1; // �������±�
        int mid = (left + right) / 2; // �м����±�
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
