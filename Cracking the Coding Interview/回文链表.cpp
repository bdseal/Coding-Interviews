/*
请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
 
测试样例：{1,2,3,2,1} 返回：true {1,2,3,2,3} 返回：false
*/
 
/*
利用一个快指针，慢指针。慢指针每次走一步，快指针每次走两步。把慢指针走过的结点入栈
比较栈中结点跟慢指针剩余为走过的结点
（特别注意链表长度是奇数还是偶数，如果是奇数，慢指针应该跳过中间结点再进行比较）
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
 
/*
 
链接：https://www.nowcoder.com/questionTerminal/baefd05def524a92bcfa6e1f113ed4f0
来源：牛客网
 
//利用字符串的回文特性
public boolean isPalindrome(ListNode pHead) {
        if(pHead == null){
            return false;
        }
        int len = 0;
        StringBuilder sb = new StringBuilder();
        while(pHead != null){
            ++len;
            sb.append(pHead.val);
            pHead = pHead.next;
        }
        int left = 0;
        int right = len - 1;
        while(left < right){
            if(sb.toString().charAt(left) != sb.toString().charAt(right)){
                return false;
            }
            left ++;
            right --;
            if(left >= right){
                return true;
            }
        }
        return false;
    }*/
class Palindrome {
public:
    //利用快慢指针，找到中间节点；将慢指针节点的值压入栈，到达中间节点后，依次出栈与后续节点的值比较。特别注意长度奇偶数。
    bool isPalindrome(ListNode* pHead) {
        if(pHead == NULL) return true;
        stack<int> stk;
        ListNode* p = pHead;
        ListNode* q = pHead;
        stk.push(p->val);
        while(q->next != NULL && q->next->next != NULL)
            {
            p = p->next;
            stk.push(p->val);
            q = q->next->next;
        }
        if(q->next == NULL)//长度为奇数
            stk.pop();
        p = p->next;
        while(!stk.empty())
            {
            if(stk.top() != p->val)
                break;
            p = p->next;
            stk.pop();
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};