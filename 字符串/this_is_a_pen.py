#this is a pen ==> pen is this

class Solution(object):
    def reverse_line(self, s):
        res = ""
        list_tmp = []
        for x in s.split(" "):
            list_tmp.append(x)
        list_tmp.reverse()
        for y in list_tmp:
            res = res + y + " "
        return res

solve = Solution()
res = solve.reverse_line("this is a pen")
print(res)



