#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct QueryInfo{
    string s;
    int times;
    QueryInfo(string s1, int t): s(s1), times(t){}
};

int QueryCompare(const QueryInfo &q1, const QueryInfo &q2)
{
    return q1.times > q2.times;
}
void FindHottest(vector<string> &s, vector<QueryInfo> &heap)
{
    unordered_map< string, int>table;
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
        if (table.find(s[i]) == table.end())
        {
            table[s[i]] = 1;
        }else
            ++table[s[i]];
    }

    auto it = table.begin();
    for (int i = 0; it != table.end() && i < 10; ++it, ++i)
    {
        QueryInfo temp(it->first, it->second);
        heap.push_back(temp);
    }
    make_heap(heap.begin(), heap.end(), QueryCompare);
    if (it == table.end())
        return;
    for ( ; it != table.end(); ++it)
    {
        if (it->second > heap[0].times){
            pop_heap(heap.begin(), heap.end(), QueryCompare);
            heap.pop_back();
            heap.push_back(QueryInfo(it->first, it->second));
            push_heap(heap.begin(), heap.end(), QueryCompare);
        }
    }
}

void TestHeap()
{
    string  t[] = {"hello", "helloo", "kadhf", "sakdf","weenr","sdicjsdnf","sdkjjfks","sdkfj" ,"hello", "sdkfj", "sdfiwemcn", "wiersnfk", "weiosdkfn" ," sdkfj"," sldfwe", "a", "v", "d", "we", "c", "sdewr", "sdf"};

    vector<string> s(t, t+sizeof(t)/sizeof(string));
    vector<QueryInfo> heap;
    FindHottest(s, heap);
    for (auto it2 = heap.begin(); it2 != heap.end(); ++it2)
    {
        cout << it2->s <<" "<<it2->times<<endl;
    }
}
int  main(){
    TestHeap();
}
