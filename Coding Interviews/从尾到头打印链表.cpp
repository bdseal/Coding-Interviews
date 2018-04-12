//输入一个链表，从尾到头打印链表每个节点的值。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> newVector;
        if(head == nullptr)
            return newVector;
        while(head != nullptr)
            {
            newVector.push_back(head->val);
            head = head->next;
        }
        reverse(newVector.begin(), newVector.end());
        return newVector;
    }
};