//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
/*class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         unsigned int flag=1;
         while(flag)
         {
            if(n & flag)
                 count++;
             flag=flag<<1;
         }
          return count;  
     }
};*/
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         if (n<0)
         {
             n=n&0x7fffffff;//负数则考虑负数向左移位的话最高位补1， 因此将最高位的符号位1变成0，也就是n & 0x7FFFFFFF，
 
             count++;//唯一差别就是最高位由1变成0，因为少了个1，所以count加1。
         }
         while(n)
         {
             if(n&1) count++;//更优雅的写法为count+=n&1
             n=n>>1;
         }
          return count;  
     }
};


//程序员面试金典有类似的题目
/*编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。

给定两个整数int A，int B。请返回需要改变的数位个数。

测试样例：
10,5
返回：4*/
//首先A转化B要改变多少位，即A和B有多少位不同，异或相同则为0，不同为1;
//接下来就是求一个数的二进制中的1的个数，剑指offer原题
/*class Transform {
public:
    int calcCost(int A, int B)
    {
        int num=A^B;
        int count=0;
        while(num)
        {
            count++;
            num=num&(num-1);
        }
        return count++;
    }
};*/