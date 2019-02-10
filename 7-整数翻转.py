class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x in range(-2**31, 2**31-1):
            flag = True if x > 0 else False
            str_x = str(abs(x))
            list_x = []
            sum = 0
            for n, i in enumerate(str_x):
                list_x.append(str_x[len(str_x)-n-1]) 
                sum = sum + (int(str_x[len(str_x)-n-1]))*10**(len(str_x) - n -1)
            sum = sum if sum in range(-2**31, 2**31-1) else 0
            return sum if flag else -sum
        else:
            return 0
            

Solution().reverse(15342364690)