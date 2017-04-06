class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.size() < b.size())swap(a,b);
        int cur = 0;
        auto it1 = a.begin(), it2 = b.begin();
        for(; it1 != a.end() && it2 != b.end(); it1++, it2++){
            cur += *it1 - '0' + *it2 - '0';
            *it1 = (cur& 0x1) ?'1':'0';
            cur >>= 1;
        }
        while(it1 != a.end()){
            cur += *it1 - '0';
            *it1 = (cur& 0x1) ?'1':'0';
            cur >>= 1;
            it1++;
        }
        if(cur != 0)a.push_back('1');
        reverse(a.begin(), a.end());
        return a;
        
    }
};