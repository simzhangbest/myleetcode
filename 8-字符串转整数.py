import  re
class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        res =''
        tmp = re.findall('^[-+]?\d+',str.strip())#正则判断，非法字符串会返回空，返回的必是带有一个+/-或无符号的数字串
        if tmp:
            ms = tmp[0]
            if ms[0] == "-" or ms[0] == "+":
                res = ms[1:]
            else:
                res = ms
            res = int(res)
            if ms[0]== "-":
                return max(-res,-0x80000000)
            return min(res,0x7FFFFFFF)
        else:
            return 0