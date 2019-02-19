class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = ''
        maxlen = 0
        for ch in s:
            if ch not in res:
                res += ch
            else:
                maxlen = max(maxlen, len(res))
                index = res.index(ch)
                res = res[index + 1:] + ch
        return max(maxlen, len(res))

solve = Solution()
print(solve.lengthOfLongestSubstring("abcabcdac"))