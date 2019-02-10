class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        str_x = str(x)
        flag = True
        for n , i in enumerate(str_x):
            if i == str_x[len(str_x)-n-1]:
                 pass
            else:
                flag = False

        return flag 