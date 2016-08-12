/* partition and quicksort  inplemented in c99
 * binary_search implemented  recursively  : change the mid
 * input the cnt of numbers and the value to be searched
 * Think in c++ using lower_bound()
 * question :sort overloaded  operation??
 */
#include<stdio.h>
#include<string.h>
#define maxn 1000
void quick_sort(int buf[],int b,int e)
{
	if(b>e)return ;
	int pivot=buf[b];                     //not the best partition when the array is ordered. 
	int low=b,high=e;
	int i;
	while(low<high)    					//
	{
		while(high>low&&buf[high]>=pivot)high--;   // less value pop to the front.
		if(low<high)buf[low]=buf[high];
		while(low<high&&buf[low]<=pivot)low++;     // big value pop to the end
		if(low<high)buf[high]=buf[low];
	}                                             // traverse all the array once
	buf[low]=pivot;   
	quick_sort(buf,b,low-1);                      // recursive search before and after the pivot
	quick_sort(buf,low+1,e);
}
int binary_search(int buf[],int begin,int end,int v) // recursive binary_search
{
	if(begin>end)
	{
		
		return -1;
	}
	int mid=begin+(end-begin)/2;
	if(buf[mid]==v)return mid;
	else if(buf[mid]<v) begin=mid+1;                // change the value of border  to recuesive. 
	else end=mid-1;
	binary_search(buf,begin,end,v);
}
int main()
{
	freopen("input.txt","r",stdin);
	int i,n,v;
	int buf[maxn];
	while(scanf("%d %d",&n,&v)!=EOF)
	{
		//printf("%d %d",n,v);
		for(i=0;i<n;i++)scanf(" %d",&buf[i]);
		//for(i=0;i<n;i++)printf(" %d",buf[i]); 		//input
		quick_sort(buf,0,n-1);
		for(i=0;i<n;i++)printf(" %d",buf[i]);  		//print to check the quicksort
		int re=binary_search(buf,0,n-1,v);			//re is the location in array subscript
		if(re==-1) printf("\nno existence\n");      // value searching not in the inut 
		else printf("\nlocation:  %d\n",re+1);
	}
	return 0;
}
