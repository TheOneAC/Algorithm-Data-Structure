/*@Zero_Arn
 *无符号大整数四则运算 
 *
 *除法修改中..... 
 */
#include<stdio.h>
#include<string.h>
#include<cctype>
#define maxn 64
int s[maxn+10];

void print_result()  //print 
 {
 	int i,put=0;
 	for(i=maxn+10-1;i>=0;i--)
	{
		if(s[i]>0)break;
	}
	for(;i>=0;i--)
	{
		printf("%d",s[i]);
		put=1;
	}
	if(put)printf("\n");
	else printf("0\n");
 }
void add(char s1[],int len1,char s2[],int len2)
{
	
	int i,j,k=0,sum=0,c=0;
	for(i=len1-1,j=len2-1;j>=0&&i>=0;i--,j--) //模拟加法进位 
	{
		sum=s1[i]-'0'+s2[j]-'0'+c;
		s[k++]=sum%10;
		c=sum/10;
	}
	
	while(i>=0)           //处理长串 
	{
		sum=s1[i]-'0'+c;
		s[k++]=sum%10;
		c=sum/10;
		i--;
	}
	while(j>=0){
		sum=s2[j]-'0'+c;
		s[k++]=sum%10;
		c=sum/10;
		j--;
	}
	s[k]=c;
	
}
int sub_tag;
int compare(char str1[],char str2[])
{
	int t1=0,t2=0,l1=strlen(str1),l2=strlen(str2);
	while(str1[t1]=='0')t1++;
	while(str1[t2]=='0')t1++;
	if(l1-t1<l2-t2)return -1;
	else if(l1-t1==l2-t2)
	{
		while(t1<l1)
		{
			if(str1[t1]< str2[t2])return -1;
			t1++;t2++;
		}
	}
	return 1;
}
void sub(char s1[],int len1,char s2[],int len2)
{
	char tmp1[maxn],tmp2[maxn];
	strncpy(tmp1,s1,len1);
	strncpy(tmp2,s2,len2);
	if(compare(tmp1,tmp2)<0)//比较大小，强制大减小 
	{
		sub_tag=1;
		sub(s2,len2,s1,len1);   //小减大，调换 
	}
	else{
		int i,j,k=0;
		for(i=len1-1,j=len2-1;i>=0 && j>=0;i--,j--)
		{
			int sum=s1[i]-s2[j];
			if(sum<0)
			{
				s[k++]=sum+10;
				s1[i-1]--;        //第一次bug出现位置，后修改了 
			}
			else{
				s[k++]=sum;
			}
			//printf("%d\n",s[k-1]);
			//print_result();
			//printf("\n");
		}
		while(i>=0)
		{
			s[k++]=s1[i]-'0';
			i--;
		}
		
	}
}
void mul(char s1[],int len1,char s2[],int len2)
{
	int i,j,cnt=0;
	for(i=len1-1;i>=0;i--)
	{
		int k=0,c=0;
		for(j=len2-1;j>=0;j--)
		{
			int sum=(s1[i]-'0')*(s2[j]-'0')+c+s[cnt+k];
			c=sum/10;
			s[cnt+k]=sum%10;
			k++;
		}
		s[cnt+k]=c;
		cnt++;
	}
	
}
void div(char s1[],int len1,char s2[],int len2)
{
	int i;
	int re[len1];
	for(i=0;i<len2;i++)                        //除数为0 无意义 
	{
		if(s2[i]>'0'&&s2[i]<='9') break;
	} 
	if(i>=len2)	printf("除 0 无意义\n");
	else if(len1<len2||((len1==len2&&(strcmp(s1,s2)<0))))printf("0\n");  //比较大小，小除大为0 
	else
	{	
		memset(re,0,sizeof(re));
		int i,j,end=len2-1;
		sub_tag=0;
		for(;end<len1;end++)
		{
			sub(s1+end+1-len2,len2,s2,len2);
			//printf("%d\n",sub_tag);
			if(sub_tag)
			{
				end++;
				//printf("%d\n",end);
				memset(s,0,sizeof(s));
				sub_tag=0;
				sub(s1+end-len2,len2+1,s2,len2);
				//printf("%d\n",sub_tag);
				while(sub_tag==0)
				{
					//printf("%d\n",sub_tag);
					re[end]++;
					for(j=0;j<len2+1;j++)s1[j]=s[len2-j]+'0';
					sub(s1+end-len2,len2+1,s2,len2);
				}
				//printf("%d %d\n",end,re[end]);
			}
			else 
			{
				while(sub_tag==0)
				{
					re[end]++;
					for(j=0;j<len2;j++)s1[j]=s[len2-1-j]+'0';
					//sub(s1+i,len2,s2,len2);
					sub(s1+end+1-len2,len2,s2,len2);
				}			
			}	
		}
		int k;
		for(k=0;k<len1;k++)
		{
			if(re[k]>0)break;
		}
		for(;k<len1;k++)printf("%d",re[k]);	
	} 
	
}
int main()
{
	char s1[maxn],s2[maxn];
	char op;
	//freopen("input.txt","r",stdin);
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s,0,sizeof(s));
	scanf("%s %c %s",s1,&op,s2);
	int len1=strlen(s1),len2=strlen(s2);
	int i,tag=0;								//非法字符处理； 
	for(i=0;i<len1;i++)
	{
		if(!isdigit(s1[i]))tag=1;
	}
	for(i=0;i<len2;i++)
	{
		if(!isdigit(s2[i]))tag=1;
	}
	if(tag==1)
	{
		printf("input include wrong op int the number !\n");
		return 0;
	}
	
	//printf("%d %d\n",len1,len2);
	switch (op)
	{
		case '+':{
			
			add(s1,len1,s2,len2);
			print_result();
			break;
		}
		case '-':{
			sub_tag=0;
			sub(s1,len1,s2,len2);
			if(sub_tag)printf("-");
			print_result();
			break;
		}
		case '*':{
			mul(s1,len1,s2,len2);
			print_result();
			break;
		}
		case '/':{
			div(s1,len1,s2,len2);
			break;
		}
		default:{
			printf("wrong operator!\n");
			return 0;
		}
	}
	return 0;
	
}
