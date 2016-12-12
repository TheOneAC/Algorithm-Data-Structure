
template <typename T> rbnode<T> *rb_tree<T>::nil = new rbnode<T>;
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
    rbnode<T> *pkey = new rbnode<T>(k),*p =nil,*cur = root;
    while(cur != nil){
        p =cur;
        if(k < cur->key){
            //++node_cnt; cout << k << '  '<<node_cnt <<endl;
            cur = cur->left;
        }else cur = cur->left;
    }
    pkey->parent = p;
    if(p == nil)root =pkey;
    else if(k <p->key)p->left = pkey;
    else p->right = pkey;
    pkey->left = pkey->right =nil;
}
template <class T>
void rb_tree<T>::insert_fix(rbnode<T> *cur)
{
    while(cur->parent->color == red){
        if(cur->parent = cur->parent->parent->left){
            rbnode<T>*uncle =cur->parent->parent->right;
            if(uncle != nil && uncle.color == red){
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
            if(uncle != nil && uncle.color == red){
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
void rb_tree<T>::create()
{
    T k;
    cout << "input elements" << endl;
    while(cin >>k)insert(k);
    cin.clear();
}
template<class T>
void rb_tree<T>::pre_tra()const{
    rbnode<T> *cur = root;
    if(cur != nil){
        cout << cur->value <<':';
        if(cur->color == red )cout << setw(12) << "red";
        else cout << setw(12) << "black";
        cout <<"black height:" << cur->bh<< endl;
        rb_tree left(cur->left);
        left.pre_tra();
        rb_tree right(cur->left);
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
        cout <<"black height:" << cur->bh<< endl;
        rb_tree right(cur->left);
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
    rbnode<T>* cur = lacate(v),*pdel,*child;
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
rbnode<T>* rb_tree<T>::locate(const T& v)const
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
