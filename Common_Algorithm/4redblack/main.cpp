#include "rbtree.h"
int main()
{
    ifstream in("input.txt");
    rb_tree<int>rbt1;
    cout <<"----------create----------"<< endl;
    rbt1.create(in);
    cout <<"----------in_tra----------"<< endl;
    rbt1.in_tra();
    cout <<"----------pre_tra----------"<< endl;
    rbt1.pre_tra();
    cout <<"----------after_erase----------"<< endl;
    rbt1.erase(26);
    cout <<"----------in_tra----------"<< endl;
    rbt1.in_tra();
    cout <<"----------pre_tra----------"<< endl;
    rbt1.pre_tra();
    cout << endl << "----rbtree over!Ã´Ã´ßÕ----" << endl;
    return 0;
}
