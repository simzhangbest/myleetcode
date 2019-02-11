class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join(x[::-1] for x in s.split())

solve = Solution()
res = solve.reverseWords("ni hao da'j jia hao")
print(res)