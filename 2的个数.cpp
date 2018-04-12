/*请编写一个方法，输出0到n(包括n)中数字2出现了几次。

给定一个正整数n，请返回0到n的数字中2出现了几次。

测试样例：
10
返回：1*/
class Count2 {
public:
    int countNumberOf2s(int n) {
  
        if (n <= 1) return 0;
  
        long res = 0, m;
        for (m = 1;m <= n;m *= 10) {
            int tmp1 = n / m, tmp2 = n%m;
  
            res += (tmp1 + 7) / 10 * m + (tmp1 % 10 == 2)*(tmp2 + 1);
        }
        return res;
    }
};