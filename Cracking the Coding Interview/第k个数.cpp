/*
有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
给定一个数int k，请返回第k个数。保证k小于等于100。
 
测试样例：3
返回：7
*/
//跟丑数的题目做法一致，但有个坑是要问清楚序列里是否包含1.
class KthNumber {
public:
    int findKth(int index) {
        vector<int>k(index+1);//vector<int>k(index);
        int t3=0,t5=0,t7=0;k[0]=1;
        for(int i=1;i<=index;i++)//for(int i=1;i<index;i++)
        {
            k[i]=min(k[t3]*3,min(k[t5]*5,k[t7]*7));
            if(k[i]==3*k[t3]) t3++;
            if(k[i]==5*k[t5]) t5++;
            if(k[i]==7*k[t7]) t7++;
        }
        return k[index];//k[index-1];
    }
};