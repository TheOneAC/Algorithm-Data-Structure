```
题目描述
A string s is LUCKY if and only if the number of different characters in s is a fibonacci number. Given a string consisting of only lower case letters , output all its lucky non-empty substrings in lexicographical order. Same substrings should be printed once. 
输入描述:
a string consisting no more than 100 lower case letters.


输出描述:
output the lucky substrings in lexicographical order.one per line. Same substrings should be printed once.

输入例子:
aabcd

输出例子:
a 
aa 
aab 
aabc 
ab 
abc 
b 
bc 
bcd 
c 
cd 
d
```

```
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


vector<int>fi;
bool fib(int n){
    if(n < 0 )return false;
    if(n < 2){
        fi.push_back(1);
        fi.push_back(2);
    }
    while(n > fi.back()){
        fi.push_back(fi[fi.size() -1] + fi[fi.size() -2]);
    }
    if(find(fi.begin(),fi.end(),n) == fi.end())
        return false;
    return true;
}
int count(string& str){
    set<char>se;
    for(auto c: str){
        if(se.find(c) == se.end())se.insert(c);
    }
    return se.size();
}
int  main(){
    string str; 
    cin >> str;
    
    set<string>ans;
    for(int l = 1; l < str.size(); l++){
        for(int i = 0; i + l <= str.size(); i++){
            string tmp = str.substr(i,l);
            if(fib(count(tmp)))ans.insert(tmp);
        }
    }
    //sort(ans.begin(),ans.end());
    for(auto s : ans){
        cout << s << endl;
    }
    
}
```