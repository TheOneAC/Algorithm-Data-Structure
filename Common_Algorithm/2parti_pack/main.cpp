#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct{
    double weight;
    double value;
    double price;
}product;
struct {
    bool operator()(const product&tmp_pd1,const product&tmp_pd2)const{
        if(tmp_pd1.price > tmp_pd2.price)return true;
        else return false;
    }
}cmp;
void print(const vector<product> &pd,int m){
    for(int i=0;i<m;i++)cout<<"Product " << i <<": value = "<<pd[i].value  <<
        " weight = "<<pd[i].weight<<" price = "<<pd[i].price <<endl;
}
int main()
{
    ifstream in("input.txt");
    int m,n;
    in >> m >> n;
    vector<product>pd;
    for(int i=0;i<m;i++){
        product tmp;
        in>> tmp.value >>tmp.weight;
        tmp.price = tmp.value/tmp.weight;
        pd.push_back(tmp);
    }
    cout << "------before sort by price---------"<<endl;
    print(pd,m);
    sort(pd.begin(),pd.end(),cmp);
    cout <<endl << "--------after sort by price--------"<<endl;
    print(pd,m);
    int max_v= 0;
    cout <<endl << "--------Get by max_price--------"<<endl;
    for(int i =0;i< m;i++){
        if(n >= pd[i].weight){
            max_v += pd[i].value;
            n -= pd[i].weight;
            cout<<"Get Product " << i <<": value = "<<pd[i].value  <<
                " weight = "<<pd[i].weight<<" price = "<<pd[i].price <<endl;
        }else {
            max_v += n * pd[i].price;
            cout<<"Get Product " << i <<": value = "<<n*pd[i].price  <<
                " weight = "<< n <<" price = "<<pd[i].price <<endl;
            break;
        }
    }
    cout <<endl<< "max_value get : " << max_v << endl;
    return 0;
}
