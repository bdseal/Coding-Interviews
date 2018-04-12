//反转链表
//输入一个链表，反转链表后，输出链表的所有元素。
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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        ListNode *node = NULL;
        ListNode *pnode = pHead;
        while(pnode!= NULL){
            ListNode *tmp = pnode->next;
            pnode->next = node;
            node = pnode;
            pnode = tmp;
        }
        return node;
    }
};