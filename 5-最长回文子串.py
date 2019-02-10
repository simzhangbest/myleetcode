# ※超出时间限制
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        longest = ""
        if len(s) < 1000:
            for n, s_ch in enumerate(s):
                res += s_ch
                # print("res: ", res)
                for index in range(len(res)):
                    res_tmp = res[index:]
                    if self.palindrome(res_tmp):
                        # print(res_tmp)
                        if len(res_tmp)> len(longest):
                            longest = res_tmp
                            break
                        else:
                            pass
            # print(longest)
            return longest

        else:
            return None

    def palindrome(self,str):
        return list(str) == list(reversed(list(str)))


res=Solution().longestPalindrome("babada")

res2=Solution().longestPalindrome("azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc")
print(res2)