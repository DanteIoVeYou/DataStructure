//2089. �ҳ�����������Ŀ���±�
//����һ���±�� 0 ��ʼ���������� nums �Լ�һ��Ŀ��Ԫ�� target ��
//
//Ŀ���±� ��һ������ nums[i] == target ���±� i ��
//
//�� nums �� �ǵݼ� ˳������󣬷����� nums ��Ŀ���±���ɵ��б����������Ŀ���±꣬����һ�� �� �б����ص��б���밴 ���� ˳�����С�
//
//ʾ�� 1��
//
//���룺nums = [1,2,5,2,3], target = 2
//�����[1,2]
//���ͣ������nums ��Ϊ [1,2,2,3,5] ��
//���� nums[i] == 2 ���±��� 1 �� 2 ��
//ʾ�� 2��
//
//���룺nums = [1,2,5,2,3], target = 3
//�����[3]
//���ͣ������nums ��Ϊ [1,2,2,3,5] ��
//���� nums[i] == 3 ���±��� 3 ��
//ʾ�� 3��
//
//���룺nums = [1,2,5,2,3], target = 5
//�����[4]
//���ͣ������nums ��Ϊ [1,2,2,3,5] ��
//���� nums[i] == 5 ���±��� 4 ��
//ʾ�� 4��
//
//���룺nums = [1,2,5,2,3], target = 4
//�����[]
//���ͣ�nums �в���ֵΪ 4 ��Ԫ�ء�
// 
//
//��ʾ��
//
//1 <= nums.length <= 100
//1 <= nums[i], target <= 100

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ret;
        ret.resize(0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
