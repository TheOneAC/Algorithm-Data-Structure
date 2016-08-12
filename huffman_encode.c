/* ����洢�������ڵ�
 * �ϲ��Ľڵ�����ں�� 
 * ÿ��ѡ����Сֵ�ʹ�Сֵ�ϲ������������ 
 * ����洢��� 
 */
#include<stdio.h>
#include<string.h>
#define maxn 200
#define maxv 1000
typedef struct         //���� �ṹ�� 
{					   // Ȩֵ�����ӣ����ӣ����ڵ� 
	int w;
	int l,r,p;
}huffNode;
huffNode ls[maxn];
void print_huff(huffNode ls[],int i)
{
	int par=ls[i].p;
	if(par==-1)return ;
	else print_huff(ls,par);
	if(ls[par].l==i)printf("0");
	else printf("1");
}
int main()
{
	freopen("input.txt","r",stdin);
	int i,n;
	while(scanf("%d",&n)!=EOF)    //����n��ȷ��ԭʼ�ڵ���Ŀ 
	{
		memset(ls,-1,sizeof(ls));
		for(i=0;i<n;i++)scanf(" %d",&ls[i].w);  //����Ȩֵ 
		int cnt=0;                              //�����ϲ����� 
		while(cnt<n-1)
		{
			int min1=maxv,min2=maxv;
		    int tag1=0,tag2=0;
		    for(i=0;i<n+cnt;i++)               //����Ѱ����С�ʹ�С 
		    {
		    	if(ls[i].w<min1&&ls[i].p==-1)
		    	{
		    		tag2=tag1;
		    		min2=min1;
		    		min1=ls[i].w;
		    		tag1=i;
				}
				else if(ls[i].w<min2&&ls[i].p==-1)
				{
					tag2=i;
					min2=ls[i].w;
				}
			}
			ls[n+cnt].w=ls[tag1].w+ls[tag2].w;    //�ϲ��ڵ㣬�޸ĸ��ӹ�ϵ 
			ls[n+cnt].l=tag1;
			ls[cnt+n].r=tag2;
			ls[tag1].p=n+cnt;
			ls[tag2].p=n+cnt;
			cnt++;
		}
		printf("�洢�������£�\n");
		for(i=0;i<n+cnt;i++) printf("%d %d %d\n",i,ls[i].w,ls[i].p);
		for(i=0;i<n;i++)
		{
			printf("huffnode of ");
			printf("%d:	",ls[i].w);
			print_huff(ls,i);
			printf("\n");
		} 
	}
	
	return 0;
}
