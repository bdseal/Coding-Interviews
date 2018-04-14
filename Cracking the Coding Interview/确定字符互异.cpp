/*
请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。

给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。

测试样例：
"aeiou"
返回：True
"BarackObama"
返回：False
*/
//基础解
class Different {
public:
    bool checkDifferent(string iniString) {
        if(iniString.empty()) return false;
        sort(iniString.begin(),iniString.end());
        for(int i = 1;i < iniString.size();++i)
        {
            if(iniString[i-1] == iniString[i]) return false;
        }
        return true;
    }
};

/*
//黑科技解法-正则表达式
.：代表任意一个字符
.*：代表任意一个字符后面有0个或多个字符
(.)：选择字符中任意一个字符进行复制 和后面的(.*\\1)结合进行判断是否后面存在一个字符与它相同
(.)(.*\\1)：匹配案例 a*a（即首尾相同的abcsa）
(.)(.*\\1).*：匹配案例 a*a*
.*(.)(.*\\1)：匹配案例 *a*a
.*(.)(.*\\1).*：匹配案例 *a*a*
*/
/*
class Different {
public:
    bool checkDifferent(string iniString) {
        return !iniString.matches(".*(.)(.*\\1).*");
    }
};
*/
/*class Different {
    public:
        bool checkDifferent(string iniString)
        {
            char[] strs=iniString.toCharArray();//
            for(int i=0;i<strs.length;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(strs[i]==strs[j])
                    {
                        return false;
                    }
                }
            }
            return true;
    }
};*/
 
