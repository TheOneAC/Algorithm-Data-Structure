## leetcode 022. Generate Parentheses
- [Concise recursive C++ solution](https://discuss.leetcode.com/topic/4485/concise-recursive-c-solution)
```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
private:
 	void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};
```
- [The most concise solution I know ever](https://discuss.leetcode.com/topic/7250/the-most-concise-solution-i-know-ever)
```
class Solution {
public:
     vector<string> generateParenthesis(int n) {
        if(n==0) return vector<string>(1,"") ;
        if(n==1) return vector<string>(1,"()") ;
        vector<string> result;
        for(int i=0;i!=n;i++)
            for(auto inner: generateParenthesis(i))
                for(auto outter:  generateParenthesis(n-i-1))
                    result.push_back("("+inner+")"+outter);
        return result;
    }
};
```
- [My 4ms C++ solution without using recursion](https://discuss.leetcode.com/topic/35617/my-4ms-c-solution-without-using-recursion)
```
M Mein-Fuhrer 
Reputation:  3
 class Solution {
 public:
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string str("(");
    result.push_back(str);
    vector<int> left({1});
    for(int pos = 1;pos < 2*n;++pos) {
        int tmp = left.size();
        for(int i = 0;i < tmp;++i) {
            if(left[i] < n) {
                if(pos - left[i] < left[i]) {
                    result.push_back(result[i] + ')');
                    left.push_back(left[i]);
                }
                result[i] += '(';
                left[i]++;
            }
            else {
                result[i] += ')';
                continue;
            }
        }
    }
    return result;
}
};
```
