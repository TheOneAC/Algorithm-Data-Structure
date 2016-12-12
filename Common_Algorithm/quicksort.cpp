#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <random>
#include <algorithm>
#define MAXLINE 10000000
using namespace std;

class buffer{
public:
    buffer(const string filename = "input.txt"){
        buf = new int[MAXLINE];
        ifstream in(filename.c_str());
        for(int tmp,cnt = 0; in >> tmp;cnt++)buf[cnt] = tmp;
    };
    typedef int* int_ptr;
    const int_ptr& getbuffer() const {return buf;};
    ~buffer(){delete[] buf;};
private:
    int *buf;
};
int parti(int buf[],int begin,int end){
    int pivot = buf[begin];
    int i = begin, j= end;
    while( i<j ){
        while(buf[j]>= pivot && i<j)j--;
        buf[i]= buf[j];
        while(buf[i] < pivot && i<j)i++;
        buf[j] = buf[i];
    }
    buf[i]= pivot;
    return i;
}
void quicksort(int buf[], int begin, int end){
    if(begin >= end)return;
    int pivot_index = parti(buf, begin, end);
    quicksort(buf, begin,pivot_index-1);
    quicksort(buf, pivot_index+1,end);
}
int random_parti(int buf[],int begin,int end){
    int r =begin + rand()%(end-begin+1);
    swap(buf[begin],buf[r]);
    return parti(buf, begin, end);
}
void random_quicksort(int buf[], int begin, int end){
    if(begin >= end)return;
    int pivot_index = random_parti(buf, begin, end);
    random_quicksort(buf, begin,pivot_index-1);
    random_quicksort(buf, pivot_index+1,end);
}
int mid_parti(int buf[],int begin,int end){
    int mid =begin + (end-begin);
    mid = buf[begin]>buf[end]?
                            (buf[mid]>buf[end]?mid:end)
                            : (buf[mid]>buf[begin]?mid:begin);
    swap(buf[begin],buf[mid]);
    return parti(buf, begin, end);
}
void mid_quicksort(int buf[], int begin, int end){
    if(begin >= end)return;
    int pivot_index = random_parti(buf, begin, end);
    mid_quicksort(buf, begin,pivot_index-1);
    mid_quicksort(buf, pivot_index+1,end);
}
int main()
{
    buffer buf1,buf2,buf3;
    time_t start, end;
    start = clock();
    quicksort(buf1.getbuffer(), 0, MAXLINE-1);
    end = clock();
    cout << "quicksort Time costs :" << (double)(end - start)/CLOCKS_PER_SEC << endl;

    start = clock();
    random_quicksort(buf2.getbuffer(), 0, MAXLINE-1);
    end = clock();
    cout << "random_quicksort Time costs :" << (double)(end - start)/CLOCKS_PER_SEC << endl;

    start = clock();
    mid_quicksort(buf3.getbuffer(), 0, MAXLINE-1);
    end = clock();
    cout << "mid_quicksort Time costs :" << (double)(end - start)/CLOCKS_PER_SEC << endl;

    return 0;
}
