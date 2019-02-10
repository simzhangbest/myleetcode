class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        n = 0
        if len(strs)==0:
            return ""
        if len(strs)==1:
            return strs[0]
        for str_elem in strs:
            for n, str_chr in enumerate(str_elem):
                if n < len(strs[0]):
                    if strs[0][n] != str_chr:
                        break
                else:
                    break       
        if n==0:
            return strs[0]
        else:
            return strs[0][0:n]


Solution().longestCommonPrefix(["abc", "abcee", "abcee"])
Solution().longestCommonPrefix(["c", "c"])
Solution().longestCommonPrefix(["", ""])
Solution().longestCommonPrefix(["flo", "fli", "flc"])