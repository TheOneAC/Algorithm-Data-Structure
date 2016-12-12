#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

enum colortype{red,black};
size_t size =0;
template <class T> class rb_tree;
template <class T>
class rbnode{
    friend class rb_tree<T>;
    struct rbnode *parent;
    struct rbnode *left;
    struct rbnode *right;
    T value;
    colortype color;
    int bh;
    rbnode(){}
public:
    rbnode(const T &k,colortype c = red):value(k),color(c),bh(1),parent(NULL),left(NULL),right(NULL){};
    T& get_value(){return value;}
    const T& get_value()const {return value;}
};
template<class T>
class rb_tree{
    static rbnode<T>* nil;
    rbnode<T> *root;
    rb_tree(const rb_tree&);
    rb_tree& operator=(const rb_tree&);
    void left_rotate(rbnode<T>*);
    void right_rotate(rbnode<T>*);
    void insert_fix(rbnode<T>*);
    void delete_fix(rbnode<T>*);
public:
    rb_tree():root(nil){
        root->parent = nil;
        root->left = nil;
        root->right = nil;
        root->color = black;
        root->bh = -1;
    }
    rb_tree(rbnode< T> *rbt):root(rbt){}
    void insert(const T&);
    void create(istream&);
    void erase(const T&);
    void joinright(const T&k,rb_tree *rbt);
    void joinleft(const T&k,rb_tree *rbt);
    void pre_tra()const;
    void in_tra()const;
    void destroy();
    rbnode <T>* locate_max(int bh)const;
    rbnode <T>* locate_min(int bh)const;
    rbnode <T>* locate(const T&)const;
    rbnode <T>* min()const;
    rbnode <T>* max()const;
    rbnode <T>* successor(const T&)const;
    rbnode <T>* predecessor(const T&)const;
    bool empty()const {return root == nil;};
};

template <class T>
rbnode<T> * rb_tree<T>::nil = new rbnode<T>;
template <class T>
void rb_tree<T>::left_rotate(rbnode<T>*cur){
    if(cur->right != nil){
        rbnode<T>* rchild = cur->right;
        cur->right = rchild->left;
        if(rchild->left != nil)
            rchild->left->parent = cur;
        rchild->parent = cur->parent;
        if(cur->parent == nil)root = rchild;
        else if(cur = cur->parent->left)
            cur->parent->left = rchild;
        else cur->parent->right = rchild;
        cur->parent =rchild;
        rchild->left = cur;
    }
}
template <class T>
void rb_tree<T>::right_rotate(rbnode<T>* cur)
{
    if(cur->left != nil){
        rbnode<T> *lchild =cur ->left;
        cur->left = lchild->right;
        if(lchild->right != nil)
            lchild->right->parent = cur;
        lchild->parent = cur->parent;
        if(cur->parent == nil)root = lchild;
        else if(cur == cur->parent->left)cur->parent->left = lchild;
        else cur->parent->right =lchild;
        lchild->right =cur;
        cur->parent = lchild;
    }
}
template <class T>
void rb_tree<T>::insert(const T &k)
{
    cout << k <<' ';
    rbnode<T> *pkey = new rbnode<T>(k),*p =nil,*cur = root;
    while(cur != nil){
        p =cur;
        if(k < cur->value){
            cur = cur->left;
        }else cur = cur->right;
    }
    pkey->parent = p;
    if(p == nil)root =pkey;
    else if(k <p->value)p->left = pkey;
    else p->right = pkey;
    pkey->left = pkey->right =nil;
    insert_fix(pkey);
}
template <class T>
void rb_tree<T>::insert_fix(rbnode<T> *cur)
{
    while(cur->parent->color == red){
        if(cur->parent = cur->parent->parent->left){
            rbnode<T>*uncle =cur->parent->parent->right;
            if(uncle != nil && uncle->color == red){
                cur->parent->color = black;
                uncle->color = black;
                cur->parent->parent->color =red;
                cur = cur->parent->parent;
                ++cur->bh;
            }else if(cur == cur->parent->right){
                cur= cur->parent;
                left_rotate(cur);
            }
            else{
                cur->parent->color = black;
                cur->parent->parent->color =red;
                right_rotate(cur->parent->parent);
            }
        }
        else{
            rbnode<T>*uncle = cur->parent->parent->left;
            if(uncle != nil && uncle->color == red){
                cur->parent->color = black;
                uncle->color = black;
                cur->parent->parent->color =red;
                cur = cur->parent->parent;
                ++cur->bh;
            }else if(cur == cur->parent->left){
                cur= cur->parent;
                right_rotate(cur);
            }
            else{
                cur->parent->color = black;
                cur->parent->parent->color =red;
                left_rotate(cur->parent->parent);
            }
        }
    }
    root->color = black;
}
template<class T>
void rb_tree<T>::create(istream &in = cin)
{
    T k;
    while(in >>k)insert(k);
    cin.clear();
    cout << endl << "Get elements over" << endl;
}
template<class T>
void rb_tree<T>::pre_tra()const{
    rbnode<T> *cur = root;
    if(cur != nil){
        cout << cur->value <<':';
        if(cur->color == red )cout << setw(12) << "red";
        else cout << setw(12) << "black";
        cout <<"      black height:" << cur->bh<< endl;
        rb_tree left(cur->left);
        left.pre_tra();
        rb_tree right(cur->right);
        right.pre_tra();
    }
}
template<class T>
void rb_tree<T>::in_tra()const{
    rbnode<T> *cur = root;
    if(cur != nil){
        rb_tree left(cur->left);
        left.in_tra();
        cout << cur->value <<':';
        if(cur->color == red )cout << setw(12) << "red";
        else cout << setw(12) << "black";
        cout <<"              black height:" << cur->bh<< endl;
        rb_tree right(cur->right);
        right.in_tra();
    }
}
template<class T>
rbnode<T>* rb_tree<T>::successor(const T&v)const
{
    rbnode<T> *cur = locate(v);
    if(cur->right != nil){
        rb_tree right(cur->right);
        return right.min();
    }
    rbnode<T>* p =cur->parent;
    while(p != nil && cur == p->right){
        cur = p;
        p = p->parent;
    }
    return p;
}
template<class T>
rbnode<T>* rb_tree<T>::min()const{
    rbnode<T>* cur = root;
    while(cur->left != nil)
        cur = cur->left;
    return cur;
}
template <class T>
rbnode<T>* rb_tree<T>::max()const{
    rbnode<T>* cur = root;
    while(cur->right != nil)
        cur = cur->right;
    return cur;
}
template <class T>
rbnode<T>* rb_tree<T>::predecessor(const T&v)const
{
    rbnode<T> *cur = locate(v);
    if(cur->left != nil){
        rb_tree left(cur->left);
        return left.max();
    }
    rbnode<T>* p =cur->parent;
    while(p != nil && cur == p->left){
        cur = p;
        p = p->parent;
    }
    return p;
}
template<class T>
void rb_tree<T>::erase(const T&v)
{
    rbnode<T>* cur = locate(v),*pdel,*child;
    if(cur == nil)return ;
    if(cur->left == nil || cur->right == nil)pdel =cur;
    else pdel = successor(v);
    if(pdel->left != nil)child = pdel->left;
    else child = pdel->right;
    child->parent = pdel->parent;
    if(pdel->parent == nil)root = child;
    else if(pdel == pdel->parent->parent)
        pdel->parent->left = child;
    else pdel->parent->right = child;
    if(cur != pdel)
        cur->value = pdel->value;
    if(pdel->color == black)
        delete_fix(child);
    delete pdel;
}
template<class T>
void rb_tree<T>::delete_fix(rbnode<T>* cur)
{
    while(cur != root && cur->color == black)
    {
        if(cur == cur->parent->left)
        {
            rbnode<T>* brother = cur->parent->right;
            if(brother->color == red)
            {
                brother->color = black;
                cur->parent->color = red;
                left_rotate(cur->parent);
                brother= cur->parent->right;
            }
            if(brother->left->color == black && brother->right->color == black)
            {
                brother->color = red;
                cur = cur->parent;
                --cur->bh;
            }else if(brother->right->color == black)
            {
                brother->color = red;
                brother->left->color = black;
                right_rotate(brother);
                brother = cur->parent->right;
            }
            else{
                brother->color = cur->parent->color;
                cur->parent->color = black;
                brother->right->color = black;
                left_rotate(cur->parent);
                ++brother->left->bh;
                cur = root;
            }
        }else
        {
            rbnode<T>* brother = cur->parent->left;
            if(brother->color == red){
                brother->color = black;
                cur->parent->color = red;
                right_rotate(cur->parent);
                brother = cur->parent->left;
            }
            if(brother->right->color == black && brother->left->color == black)
            {
                brother->color = red;
                cur=cur->parent;
                -- cur->bh;
            }else if(brother->left->color == black)
            {
                brother->color = red;
                brother->right->color = black;
                left_rotate(brother);
                brother= cur->parent->left;
            }else
            {
                brother->color = cur->parent->color;
                cur->parent->color = black;
                brother->left->color = black;
                right_rotate(cur->parent);
                ++brother->bh;
                --brother->left->bh;
                cur = root;
            }
        }
    }
    cur->color = black;
}
template<class T>
rbnode<T>* rb_tree<T>::locate(const  T& v)const
{
    rbnode<T>* cur = root;
    while(cur != nil && cur->value != v)
    {
        if(v < cur->value)cur = cur->left;
        else cur = cur->right;
    }
    return cur;
}
template<class T>
rbnode<T>* rb_tree<T>::locate_max(int bh)const
{
    rbnode<T>* cur =  root;
    if(cur == nil || cur->bh < bh)return nil;
    while(cur->bh != bh)cur = cur->right;
    return cur;
}
template<class T>
rbnode<T>* rb_tree<T>::locate_min(int bh)const
{
    rbnode<T>* cur =  root;
    if(cur == nil || cur->bh < bh)return nil;
    while(cur->bh != bh)cur = cur->left;
    return cur;
}
template<class T>
void rb_tree<T>::joinright(const T&v,rb_tree *rbt)
{
    rbnode<T>* r =locate_max(rbt->root->bh);
    rbnode<T>* cur = new rbnode<T>(v);
    rbnode<T>* pr = r->parent;
    cur->left = r;
    r->parent = cur;
    cur->right = rbt->root;
    rbt->root->parent = cur;
    cur->parent = pr;
    cur->bh = rbt->root->bh+1;
    if(pr  != nil)pr->right = cur;
    else root = cur;
    insert_fix(cur);
}
template<class T>
void rb_tree<T>::joinleft(const T&v,rb_tree *rbt)
{
    rbnode<T>* r =locate_min(rbt->root->bh);
    rbnode<T>* cur = new rbnode<T>(v);
    rbnode<T>* pr = r->parent;
    cur->right = r;
    r->parent = cur;
    cur->left = rbt->root;
    rbt->root->parent = cur;
    cur->parent = pr;
    cur->bh = rbt->root->bh+1;
    if(pr  != nil)pr->left = cur;
    else root = cur;
    insert_fix(cur);
}
template<class T>
void rb_tree<T>::destroy()
{
    while(root != nil)
    {
        cout << "erase: " << root->value << endl;
        erase(root->key);
    }
    delete nil;
}
