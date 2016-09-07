/*innner order traverse for BST will be ordered
 *1.sort the value in buffer
 *2.inner traverse the BST and insert the value
 *3.be careful for the formatted output
 *4.level traverse output using queue
 */

/*c-style code
 * abusing in global variable
 *not good encapsulation
 *may be possible to use reference for 'start'
 */
#include <cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100
using  namespace std;
typedef struct {
    int left,right;
    int value;
    int inserted;
}binode;
binode bitree[maxn];
int buf[maxn];
int start=0;
queue<int> q;
void middle_insert(int root)
{
    if(root==-1)return;
    middle_insert(bitree[root].left);
    if(bitree[root].left==-1 || bitree[bitree[root].left].inserted==1)
    {
        bitree[root].value=buf[start];
        bitree[root].inserted=1;
        start++;
        //return ;
    }
    middle_insert(bitree[root].right);
}
void level_traverse()
{
    int i=0;
    q.push(0);
    while(!q.empty())
    {
        int tmp=q.front();
        buf[i++]=bitree[tmp].value;
        q.pop();
        if(bitree[tmp].left!=-1)q.push(bitree[tmp].left);
        if(bitree[tmp].right!=-1)q.push(bitree[tmp].right);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int i,n;
    while(cin>>n)
    {
        memset(buf,0,sizeof(buf));
        memset(bitree,0,sizeof(bitree));
        //fill(bitree,bitree+n,0); parameter must be iterator
        for(i=0;i<n;i++)scanf(" %d %d",&bitree[i].left,&bitree[i].right);
        for(i=0;i<n;i++)scanf(" %d",&buf[i]);
        sort(buf,buf+n);
        //for(i=0;i<n;i++)printf("%d ",buf[i]);
        middle_insert(0);
        //for(i=0;i<n;i++)printf("%d %d %d %d\n",i,bitree[i].left,bitree[i].right,bitree[i].value);
        level_traverse();
        for(i=0;i<n;i++){
            if(i<n-1)printf("%d ",buf[i]);
            else printf("%d\n",buf[i]);
        }
    }
    return 0;
}

