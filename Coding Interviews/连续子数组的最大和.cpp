/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)
*/
//运行时间： 3 ms 占用内存：512K
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> a) {
        //遍历，遇到负和抛弃之前的结果，重新积累，期间保留最大值
        if(a.empty()) return 0;
        int n=a.size(),result = a[0];
        for(int i=0,cSum=0;i<n;++i)
        {
            cSum=max(cSum+a[i],a[i]);
            result=max(cSum,result);
            //等价于
            /*if(cSum < 0) // 当前和<0，抛弃不要
                cSum = a[i];
            else
                cSum += a[i];
              
            if(cSum > result) // 存储最大结果
                result = cSum;*/
        }
    return result;
    }
};
 
/*
 
 int FindGreatestSumOfSubArray(vector<int> a) {
        if(array.empty()) return 0;
        int cSum = 0;
        int result = a[0]; // result存储最大和，不能初始为0，存在负数
        for(int i = 0;i<a.size();++i)
        {
            if(cSum < 0) cSum = a[i];// 当前和<0，抛弃不要
            else cSum += a[i];
             
            if(cSum > result) result = cSum;// 存储最大结果
        }
        return result;
    }
*/
