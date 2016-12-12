#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("input.txt");
    int m,n;
    in >> m >> n;
    int dp[m+1][n+1];
    int w[m+1],v[m+1],t[m+1];
    for(int i=1;i<=m;i++)
        in>> w[i] >> v[i];
    memset(dp,0,sizeof(dp));
    memset(t,0,sizeof(t));
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j>=w[i]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<"---Matrix dp :---" << endl;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout<<endl << "Max value can get :"<<dp[m][n]<<endl;
    return 0;
}
