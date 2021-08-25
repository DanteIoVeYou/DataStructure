/*
����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

?

˵��:

Ϊʲô������ֵ��������������Ĵ���������?

��ע�⣬�����������ԡ����á���ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�

����������ڲ���������:

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 


int removeDuplicates(int* nums, int numsSize)
{
    if(!numsSize)
    {
        return 0;
    }
    int src=0;
    int dest=0;
    while(src<numsSize)
    {
        if(nums[dest]==nums[src])
        {
            src++;
        }
        else
        {
            nums[dest+1]=nums[src];
            dest++;
            src++;
        }
    }
    return dest+1;

}


/*
����һ������ nums?��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����?val?��Ԫ�أ��������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

*/

int removeElement(int* nums, int numsSize, int val)
{
    if(!numsSize)
        return 0;
    int src = 0;
    int dest = 0;
    while(src<numsSize)
    {
        if(nums[src]==val)
        {
            src++;
        }
        else
        {
            nums[dest++]=nums[src++];
        }
    }
    return dest;;
}
