/* a good way to predict overflow
 * each time *10 must predict int overflow
 * not only the last time to predict which will be wrong.
 */
class Solution {
public:
    int reverse(int x) {
        if(x==0)return x;
        int tag=0;
        long int re=0;
        if(x<0)
        {
            tag=1;
            x=-x;
        }
        while(x)
        {
            int tmp=re*10+x%10;
            if((tmp-x%10)/10!=re)return 0;
            re=tmp;
            x=x/10;
        }
        if(tag)re=-re;
        return re;
    }
};
