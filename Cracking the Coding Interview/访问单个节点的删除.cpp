
/*
实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true
*/
 
/*
D->A->B->C，
要删除A,又不能删除D-->A,D无法访问。
可以变相删除：D->'A'(B的值)->C 实际上是删除B，把B的值给A的值域，A->next=B->next。
 
首先，不能访问之前的节点，但是可以访问后续节点。
然后，对于尾节点，直接delete掉，返回false即可。
最后，对于中间节点简记为A = pNode，利用其后续节点B = pNode->next和C = pNode->next->next变相删除。
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        // 尾节点
        if (pNode->next == NULL)
            {
            delete pNode;
            return false;
        }
        else
            {
            ListNode* nextNode;
            nextNode = pNode->next;
            pNode->val = nextNode->val;
            pNode->next = nextNode->next;
            delete nextNode;
            return true;
        }
    }
};
