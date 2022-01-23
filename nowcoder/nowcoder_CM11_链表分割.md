**CM11** **链表分割**、

## 描述

现有一链表的头指针 ListNode* **pHead**，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。





```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
   
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        
        if(pHead == NULL)
            return pHead;
        if(pHead->next == NULL)
            return pHead;
        
        
        ListNode* emptyHead = (ListNode*)malloc(sizeof(ListNode));
        emptyHead->next = pHead;
        
        ListNode* cur = emptyHead->next;
        ListNode* prev = emptyHead;
        ListNode* next = emptyHead->next->next;
        ListNode* newhead1 = (ListNode*)malloc(sizeof(ListNode));
        ListNode* newhead = newhead1;
        
            
        while(cur)
        {
            if(cur->val < x)
            {
                
                
                newhead->next = cur;
                cur->next = emptyHead;
                newhead = cur;
                
                prev->next = next;
                cur = next;
                
                if(next)
                    next = next->next;
            }
            else
            {
                    
                prev = cur;
                cur = next;
                if(next)
                    next = next->next;
            } 
        }
        
        newhead->next = emptyHead->next;
        
        free(emptyHead);
        emptyHead = NULL;
        
        ListNode* ret = newhead1->next;
        
        free(newhead1);
        newhead1 = NULL;
        
        
        return ret;
       
    }
};
```

