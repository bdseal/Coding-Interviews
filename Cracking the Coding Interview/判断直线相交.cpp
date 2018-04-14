/*
给定直角坐标系上的两条直线，确定这两条直线会不会相交。
线段以斜率和截距的形式给出，即double s1，double s2，double y1，double y2，
分别代表直线1和2的斜率(即s1,s2)和截距(即y1,y2)，
请返回一个bool，代表给定的两条直线是否相交。这里两直线重合也认为相交。
 
测试样例：3.14,3.14,1,2
返回：false
*/
 
/*只有斜率相同，截距不同才会相交。
另外了解浮点表示法的限制。不要用==检查浮点数是否相等，而是应该检查两者差值是否小于某个极小值，例如1e-6。
*/
class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        return (abs(s1 - s2) <=1e-6 && abs(y1 - y2) > 1e-6)?false:true;
    }
};