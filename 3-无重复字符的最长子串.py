class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max = -1
        if len(s)==1:
            max=1
        else:
            for index_1 in range(len(s)):
                str1=s[0:index_1+1]
                if len(str1)==1:
                    max=1
                else:
                    for index_2 in range(len(str1)):
                            str_tmp = str1[index_2+1:(len(str1)+1)]
                            str_test = str1[index_2]
                            if str_tmp.find(str1[index_2]) == -1 and str_tmp != "":
                                max=len(str_tmp)+1 if len(str_tmp)+1 > max else max
                            else:
                                pass


        print(max)
        return  max



Solution().lengthOfLongestSubstring("abcabcbb")

