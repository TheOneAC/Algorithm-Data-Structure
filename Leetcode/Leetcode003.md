### Letcode 003: Longest Substring Without Repeating Characters
```
/* basic traverse the string 
 * set to predict there is no repeat char in the substring
 *
 * Time Limit Out
 * O(n*n)
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        set<char>diffchar;
        for(auto it=s.begin();it != s.end();it++)
        {
            diffchar.clear();
            for(auto it1=it;it1!=s.end();it1++)
            {
                if(diffchar.find(*it1) == diffchar.end())diffchar.insert(*it1);
                else break;
            }
            if(diffchar.size() > max) max = diffchar.size();
        }
        return max;
    }
};
```
----------------------------------
**learn from ![ACM home](http://www.acmerblog.com/leetcode-solution-longest-substring-without-repeating-characters-6307.html)
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)return s.length();
        int start=0,maxsub=0;
        int ASCIINUM=256;
        int lastlocation[ASCIINUM];
        fill(lastlocation,lastlocation+ASCIINUM,-1);
        for(int i=0;i<s.size();i++)
        {
            if(lastlocation[s[i]-' ']>=start)
            {
                maxsub=max(i-start,maxsub);
                start=lastlocation[s[i]-' ']+1;
            }
            lastlocation[s[i]-' ']=i;
        }
        return max((int)s.size() - start, maxsub);
    }
};
```