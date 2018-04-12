/*请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）

给定一个int x，请返回交换后的数int。

测试样例：
10
返回：5*/
/*
class Exchange {
public:
/*
 * 题目意思是数中奇偶位位数相等，而位上对应数字互换
 * (x&0xaaaaaaaa)>>>1就是把奇数位清0，偶数位移到奇数位 a=1010
 * (x&0x55555555)<<1就是把偶数位清0，奇数位移到偶数位 5=0101
 *该题要想对负数依然成立，需将右移操作>>改成无符号右移>>>*
    int exchangeOddEven(int x) {
        return ((x & 0xaaaaaaaa) >>> 1 | (x & 0x55555555) << 1);// | 和 +是一个意思
        //return ((x&0x55555555)<<1) | (((x&0xAAAAAAAA)>>1)&0x7fffffff);//0x7fffffff是将最高位置为0；
    }
};
*/
 
class Exchange {
public:
    int exchangeOddEven(int x) {
        // write code here
        int odd  = ((x&0x55555555)<<1);
        int even = ((x&0xAAAAAAAA)>>1)&0x7fffffff;
        return even|odd;
    }
};