**OR36** **链表的回文结构**

## 描述

对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针**A**，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

测试样例：

```
1->2->2->1
返回：true
```

```
class PalindromeList {
public:
    struct ListNode* ReverseList(ListNode* head)
    {
        struct ListNode* cur = head;
        struct ListNode* newhead = NULL;
        while(cur)
        {
            struct ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
       
    }
    struct ListNode* MidNode(ListNode* head)
    {   
        struct ListNode* fast = head;
        struct ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool chkPalindrome(ListNode* A) 
    {
        // write code here
        struct ListNode* mid = MidNode(A);
        mid = ReverseList(mid);
        struct ListNode* front = A;
        struct ListNode* back = mid;
        while(front->next != back->next && back->next != NULL)
        {
            if(front->val != back->val)
                return false;
            front = front->next;
            back = back->next;
        }
        return true;
    }
};
```

