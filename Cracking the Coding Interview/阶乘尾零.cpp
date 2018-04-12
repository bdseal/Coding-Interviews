/*
请设计一个算法，计算n的阶乘有多少个尾随零。

给定一个int n，请返回n的阶乘的尾零个数。保证n为正整数。

测试样例：
5
返回：1
*/

class Factor {
public:
    int getFactorSuffixZero(int n)
    {
        int count = 0;
        if (n < 0)
            return -1;
        for (int i = 5; n / i > 0; i *= 5)
            count += n / i;
        return count;
    }
};