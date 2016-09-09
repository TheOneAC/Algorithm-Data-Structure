/* pivot varies when the size of substrig is even or odd
 * member function parameter varies according to the size of substring
 * complexity O(n*n)
 */

class Solution {
public:
    string Palindrome(string s, int a,int b)
    {
        string  tmp;
        if(a<0||b>=s.size())return tmp;
        while(a>=0&&b<s.size())
        {
            if(s[a]!=s[b])break;
            a--;
            b++;
        }
        tmp=s.substr(a+1,b-a-1);
        return tmp;
    }
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        int start,end;
        string maxp,tmp1,tmp2;
        for (int i=0;i<s.size();i++)
        {
            
            tmp1=Palindrome(s,i,i+1);
            tmp2=Palindrome(s,i-1,i+1);
            if(tmp1.size()<tmp2.size())tmp1=tmp2;
            if(maxp.size()<tmp1.size())maxp=tmp1;
        }
       
        return maxp;
    }
};
