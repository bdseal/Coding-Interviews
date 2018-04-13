//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> a,int sum)
    {
        vector<int> out;
        int i=0, j=a.size()-1;
        while(i<j)
        {
            if(a[i]+a[j]==sum)
            {
                out.push_back(a[i]);
                out.push_back(a[j]);
                break;
            }
            if(a[i]+a[j]<sum) i++;
            if(a[i]+a[j]>sum) j--;
        }
        return out;
    }
};