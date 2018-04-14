//输入一个链表，输出该链表中倒数第k个结点。
/*
p作为计步器。先让p走到距离phead为k的位置；
然后他俩一起走，p和phead始终距离为k；
这样p走到末尾（即为p->next=null）,phead即为该链表中倒数第k个结点
*/
 
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
 
 
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p=pListHead;
        while(k--!=0)
        {
            if(p==NULL) return NULL;
            p=p->next;
        }
         
        while(p!=NULL)
        {
            p=p->next;
            pListHead=pListHead->next;
        }
    return pListHead;
    }
};
 
/*public ListNode FindKthToTail(ListNode head,int k) {
        ListNode p = head;
        while(k-- != 0){
            if(p == null)
                return null;
            p = p.next;
        }
        while(p != null){
            p = p.next;
            head = head.next;
        }
        return head;
    }
    */