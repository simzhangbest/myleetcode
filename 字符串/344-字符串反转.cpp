//
// Created by simzhang on 2019/2/11.
//

/*
 * 输入：["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * */

class Solution {
public String reverseString(String s) {
        int i = 0;
        int j = s.length()-1;
        char[] ch = s.toCharArray();
        while(i<j){
            swap(ch,i,j);
            i++;
            j--;
        }
        return new String(ch);
    }
public void swap(char[] ch,int i,int j){
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }
}


class Solution {


public:
    void reverseString (vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            swap(s, i, j);
            i++;
            j--;
        }
    }
    void swap(std::vector<char>& ch, int i, int j) {
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }

};