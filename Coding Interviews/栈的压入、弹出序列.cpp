/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

/*借用一个辅助的栈.
遍历压栈顺序，先将第一个放入栈中，
然后判断栈顶元素是不是出栈顺序的第一个元素，不相等则继续压栈，
直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，直到不相等，
这样循环等压栈顺序遍历完成，
如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        stack<int> st;
        int id=0;
        st.push(pushV[id]);
        for(int i=0;i<popV.size();++i)
        {
            while(st.top()!=popV[i])
            {
                st.push(pushV[++id]);//这里涉及i++和++i的区别: i++包含i, ++i不包含i.
                if(id>pushV.size())
                {
                    return false;
                }
            }
            st.pop();
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};



/*：
补充：i++ 与 ++i 的主要区别：
1、 i++ 返回原来的值，++i 返回加1后的值。
2、 i++ 不能作为左值，而++i 可以。
*/

/*
左值:左值是对应"内存中有确定存储地址"的对象的表达式的"值"。
一般来说，左值是可以放到赋值符号左边的变量。但能否被赋值不是区分左值与右值的依据。
比如，C++的const左值是不可赋值的；而作为临时对象的右值可能允许被赋值。左值与右值的根本区别在于是否允许取地址&运算符获得对应的内存地址。比如，int i = 0;
int *p1 = &(++i); //正确
int *p2 = &(i++); //错误

++i = 1; //正确
i++ = 5; //错误
*/