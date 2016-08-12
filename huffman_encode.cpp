/*int computer in c, not consider value<0
 *input terminated by '#'
 *priority be writed  into a array
 */
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<cctype>
#define maxn 100
using namespace std;
map<char, int> mpc;      			//implement the change from char to num
char c;
stack<int>opr;						// stack for oprator and operand
stack<char>op;

bool is_rightop(char ch)            //check whether the operator ia legal
{
	if(ch=='#'||ch=='+'||c!='-') return true;
	else if(ch=='*'||ch=='/') return true;
	else if(ch=='('||ch==')') return true;
	else return false;
}
int is_priority(int priority[][7],char a,char b)    		//use the array priority to judge the priority
{
	return priority[mpc[a]][mpc[b]];
}
int div_zero;												// tag for divide zero
int compute(int a ,char op,int b)
{
	switch(op)
	{
		case '+':{
			return a+b;
			break;
		}
		case '-':{
			return a-b;
			break;
		}
		case '*':{
			return a*b;
			break;
		}
		case '/':{
			div_zero=0;                       // if divide zero happend, div_tag=1
			if(b==0)div_zero=1;
			return b==0?0:a/b;
			break;
		}
	}
}
int main()
{
	int priority[7][7]={{-1,-1,-1,-1,1,1,1},
					{-1,-1,-1,-1,1,1,1},
					{1,1,-1,-1,1,1,1},
					{1,1,-1,-1,1,1,1},
					{1,1,1,1,1,0,1},
					{-1,-1,-1,-1,0,1,1},
					{-1,-1,-1,-1,1,-1,0}
					};
	//int i;
	//for(i=0;i<7;i++)printf("%d ",priority[0][i]);
	mpc['#']=6;
	mpc['+']=0;
	mpc['-']=1;
	mpc['*']=2;
	mpc['/']=3;
	mpc['(']=4;
	mpc[')']=5;
	op.push('#');
	char buf[maxn];
	freopen("input.txt","r",stdin);
	while(scanf("%s",buf)!=EOF)
	{
		//printf("%s\n",buf);
		int i,len=strlen(buf);
		for(i=0;i<len;)
		{
			//printf("%d\n",i);
			if(isdigit(buf[i]))               //read in the entire number 
			{
				int sum=buf[i]-'0';
				while(isdigit(buf[i+1]))
				{
					sum=sum*10+buf[i+1]-'0';
					i++;
				} 
				//printf("%d\n",sum);
				opr.push(sum);
				i++;
			}
			else if(!is_rightop(buf[i]))      //check whether the operator is legal or not
			{
				printf("%d\n",is_rightop(buf[i]));
				printf("Input include wrong operator\n");
				return 0;
			}
			else 
			{
				int p=is_priority(priority,buf[i],op.top());
				//printf("%c %d\n",buf[i],p);
				if(p==1)            // thr cur operation is superior to the top operator of the stack
				{
					op.push(buf[i]);
					i++;
				}
				else if(p==-1)      // thr cur operation is junior to the top operator of the stack
				{					//pop twp number and a op to compute ,and push the re into the opr;
						char oper=op.top();op.pop();	
						int opr2=opr.top();opr.pop();
						int opr1=opr.top();opr.pop();
						int s=compute(opr1,oper,opr2);
						if(div_zero==1)
						{
							printf("除数不可为0！\n");
							return 0;
						}
						//printf("%d\n",s);
						opr.push(s);		
				}
				else			// the cur operation`s priority is the same  to the top operator of the stack
				{
					op.pop(); 
					i++;
				 }
				//printf("%c\n",op.top()); 
			}
						
		}
		printf("%d\n",opr.top());
		opr.pop();
	}
	return 0; 
}
