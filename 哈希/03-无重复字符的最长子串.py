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

    def lengthOfLongestSubstring_better(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = {}
        i, ans = 0, 0
        for j in range(len(s)):
            if s[j] in st:
                i = max(st[s[j]], i)
            ans = max(ans, j - i + 1)
            st[s[j]] = j + 1
        return ans;

solve = Solution()
print(solve.lengthOfLongestSubstring("abcabcdac"))