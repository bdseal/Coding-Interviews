/*
请编写一个函数，函数内不使用任何临时变量，直接交换两个数的值。
给定一个int数组AB，其第零个元素和第一个元素为待交换的值，请返回交换后的数组。
测试样例：[1,2]
返回：[2,1]
*/
class Exchange {
public:
//a^b^b=a.
    vector<int> exchangeAB(vector<int> AB) {
        AB[0] = AB[0]^AB[1];//相加有可能溢出
        AB[1] = AB[0]^AB[1];//a^b^b=a.
        AB[0] = AB[0]^AB[1];//(a^b)^(a^b^b)=b.
        return AB;
    }
};