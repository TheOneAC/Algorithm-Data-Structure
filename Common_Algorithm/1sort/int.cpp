#include <iostream>
#include <cstdlib>
#include <fstream>
#define MAXLINE  10000000
using namespace  std;
int main(){
    ofstream os;
    os.open("input.txt");
    for(int i = 0;i< MAXLINE;i++){
        os << i << ' ';
    }
    os << endl;
    flush(os);
    return 0;
}
