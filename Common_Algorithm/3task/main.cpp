#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstring>
using namespace std;
#define MAX 7
typedef struct {
    int id;
    int d;
    int p;
    int tag;
}task;
void random_init(task ta[]){
    srand((unsigned)time(NULL));
    for(int i=0;i< MAX;i++){
        ta[i].id = i+1;
        ta[i].d = rand()%MAX + 1;
        ta[i].p = rand()%(3*MAX) +1;
        ta[i].tag =0;
    }
}
void print_a(const task ta[],int &max_v,int &sum_p)
{
    sum_p = 0;
    for(int i = 0; i<MAX;i++){
        sum_p += ta[i].p;
        cout << "ID : " <<ta[i].id << " Date : " << ta[i].d <<" Punishment : " << ta[i].p << endl;
        if(ta[i].p > max_v)max_v = ta[i].p;
    }
}
struct {
    bool operator()(const task t1,const task t2){
        return t1.p > t2.p;
    }
}cmpP;
void greedy(task ta[],int &sum_p)
{
    sort(ta,ta+MAX,cmpP);
    int flag[MAX+1];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<MAX; i++){
        int j;
        for(j=ta[i].d;j>0;j--){
            if(flag[j+1]==0){
                flag[j+1]=1;
                break;
            }
        }
        if(j>0){
            ta[i].tag =1;
            sum_p -=ta[i].p;
        }
    }
}
struct {
    bool operator()(const task t1,const task t2){
        return t1.d <t2.d;
    }
}cmpD;
void print_ans(task ans[])
{
    sort(ans,ans+MAX,cmpD);
    for(int i = 0; i<MAX;i++){
        cout << "ID : " <<ans[i].id << " Date : " << ans[i].d <<" Punishment : " << ans[i].p << ' ';
        if (ans[i].tag == 1 )cout <<'*';
        cout  << endl;
    }
}
void cope(task ta[],int max_v)
{
    for(int i=0;i< MAX;i++)
    {
        ta[i].p = max_v - ta[i].p;
        ta[i].tag = 0;
    }
}
int main(){
    task ta[MAX];
    random_init(ta);
    cout << "------init data-----" << endl;
    int max_v=-1, sum_p;
    print_a(ta,max_v,sum_p);
    sort(ta,ta+MAX,cmpP);
    cout << "------sort by punishment-----" << endl;
    print_a(ta,max_v,sum_p);
    greedy(ta,sum_p);
    cout << endl << "min punishment : "<<sum_p <<endl;
    cout << "------Select subtask print in date asc -----" << endl;
    print_ans(ta);

    cope(ta,max_v);
    cout <<endl <<"------After change -------"<< endl;
    print_a(ta,max_v,sum_p);
    sort(ta,ta+MAX,cmpP);
    cout << "------sort by punishment-----" << endl;
    print_a(ta,max_v,sum_p);
    greedy(ta,sum_p);
    cout << endl << "min punishment : "<<sum_p <<endl;
    cout << "------Select subtask print in date asc -----" << endl;
    print_ans(ta);

}
