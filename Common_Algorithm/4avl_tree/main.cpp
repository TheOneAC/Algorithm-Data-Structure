#include <iostream>
#include <fstream>
#include "AVLTree.h"
using namespace std;
int main()
{
    AVLTree<int>* tree=new AVLTree<int>();
    ifstream in("input.txt");
    cout << "-----insert and build tree: ------"<< endl;
    for(int tmp;in>> tmp;)
    {
        cout << tmp << ' ';
        tree->insert(tmp);
    }
    cout << endl <<"-----preorder------"<< endl;
    tree->preOrder();

    cout <<endl << "-----inorder------"<< endl;
    tree->inOrder();

    cout <<endl << "-----postorder------"<< endl;
    tree->postOrder();
    cout <<endl << "height: " << tree->height() << endl;
    cout << "min_value:  " << tree->minimum() << endl;
    cout << "max_value:  " << tree->maximum() << endl;
    cout << "------info of tree-----" << endl;
    tree->print();

    int i = 7;
    cout << endl << "delete node: " << i << endl;
    tree->remove(i);

    cout << "geight: " << tree->height() << endl;
    cout << endl <<"-----preorder------"<< endl;
    tree->preOrder();
    cout << endl << "inorder: " << endl;
    tree->inOrder();
    cout << endl << "-----info of tree------" << endl;
    tree->print();
    tree->destroy();

    return 0;
}
