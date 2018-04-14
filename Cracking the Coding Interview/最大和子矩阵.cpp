/*
有一个正整数和负整数组成的NxN矩阵，请编写代码找出元素总和最大的子矩阵。请尝试使用一个高效算法。
给定一个int矩阵mat和矩阵的阶数n，请返回元素总和最大的子矩阵的元素之和。
保证元素绝对值小于等于100000，且矩阵阶数小于等于200。
 
测试样例：[[1,2,-3],[3,4,-5],[-5,-6,-7]],3
返回：10   
*/
//最大和子序列问题的扩展 - 转成求一维数组最大连续子和的问题
class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        return maxSumMat(mat,n);
    }
    int maxSumMat(vector<vector<int>> mat,int n){
        if(n<=0) return 0;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            vector<int> v(mat[i]);
            res=max(res,maxSumArray(v));//得到第一行的最大和
            for(int j=i+1;j<n;j++)//循环下面的n-1行
            {
                for(int k=0;k<n;k++)//将行的n个元素加到上一行，然后计算最大和
                {
                    v[k]+=mat[j][k];
                }
                res=max(res,maxSumArray(v));//依次0~k行的最大和
            }     
        }
        return res;
    }
    int maxSumArray(vector<int> data){
        int cur= 0;
        int max = cur;
        int length = data.size();
         
        for (int i = 0; i < length; i++)
        {
            if (cur>0) cur+= data[i];
            else cur= data[i];
            if (cur > max) max = cur;
        }
        return max;
    }
};
 
/*
//如果改成M*N矩阵
#include<iostream>
#include<vector>
using namespace std;
class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        //cout << maxSumMat(mat) << endl;
        return maxSumMat(mat);
    }
    int maxSumMat(vector<vector<int>> mat){
        int n = mat.size();
        int m = mat[0].size();
  
        int res = 0;
        vector<int> b = mat[0];
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int k = 0; k < mat[0].size(); ++k)
                b[k] = 0;
            for (int j = i; j < mat.size(); j++) //枚举i - j行
            {
                for (int k = 0; k < mat[0].size(); ++k){
                    b[k] += mat[j][k];
                }
                int maxSubMat = maxSumArray(b);
                if (maxSubMat>res)
                    res = maxSubMat;
            }
        }
        return res;
    }
  
    int maxSumArray( vector<int> data){
        int cur= 0;
        int max = cur;
  
        int length = data.size();
        for (int i = 0; i < length; i++){
            if (cur>0){
                cur+= data[i];
            }
            else{
                cur= data[i];
            }
  
            if (cur > max)
                max = cur;
        }
        return max;
    }
};
*/