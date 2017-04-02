/*
 2017.4.2
 zero_Arn
 trie implements insert, find, get_longthest_prefix, delete, show_word in trie
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct node{
    char c;
    bool isleaf;
    map<char, struct node*>child;
    node(char a = ' '):c(a),isleaf(false){};
};

class trie{
private:
    node* root = new node();
    trie(const trie&);
    void insert_r(const string &word,size_t index, node* &root){
        if(root == NULL)root = new node(word[index]);
        if(index >= word.size()){
            root->isleaf = true;
            return;
        }
        if(root->child.find(word[index]) == root->child.end())root->child.insert(pair<char, struct node*>(word[index], NULL));
        insert_r(word, index+1, root->child[word[index]]);
    }
    void dfs(node* cur, string word){
        if(cur == NULL)return ;
        if(cur->isleaf)cout << word << endl;
        map<char, struct node*>::iterator it = cur->child.begin();
        for(; it != cur->child.end(); it++){
            word.push_back(it->first);
            dfs(it->second,word);
            word.pop_back();
        }
    }
    void free_word(const string &word, int index, node* &root){
        map<char, struct node*>::iterator it;
        if(index < word.size()){
            it = root->child.find(word[index]);
            index++;
            free_word(word, index, it->second);
        }
        for(it = root->child.begin(); it != root->child.end(); it++){
            if(it->second == NULL){
                root->child.erase(it);
                break;
            }
        }
        if(root->child.size() == 0){
            delete root;
            root = NULL;
            return;
        }
    }
public:
    trie(){};
    trie(vector<string>&li){
        for(auto s : li)
            insert_word(s);
    }
    ~trie(){
        root = NULL;
    }
    void insert_word(const string &word){
        insert_r(word, 0, this->root);
    }
    bool find(const string &word){

        node* cur = this->root;
        for(size_t i = 0; i< word.size(); i++){
            if(cur->child.find(word[i]) == cur->child.end())return false;
            else cur = cur->child[word[i]];
        }
        if(cur->isleaf)return true;
        else return false;
    };
    void delete_word(const string &word){
        if(!find(word))return;
        free_word(word, 0,this->root);
    }
    string get_longthest_prefix(const string &word){
        string prefix = "";
        node* cur = this->root;
        for(size_t i = 0; i< word.size(); i++){
            if(cur->child.find(word[i]) == cur->child.end())break;
            else{
                prefix.push_back(word[i]);
                cur = cur->child[word[i]];
            }
        }
        return prefix;
    }
    void show_dict(){

        string word ;
        dfs(this->root,word);
    }
};
void test(){
    trie* mytrie = new trie();
    //cout << "insert word:" << endl;
    mytrie->insert_word("hello");
    mytrie->insert_word("helt");
    mytrie->insert_word("him");
    mytrie->insert_word("zero");
    cout << "words in trie is:" << endl;
    mytrie->show_dict();
    string  s = "helt";
    mytrie->delete_word(s);
    cout << endl << "after delete word:\" " << s <<" \" "<< endl;
    mytrie->show_dict();
    s = "hello";
    cout <<"find [" <<s << "] in trie:  "<<endl<< (mytrie->find(s)?"YES": "NO") << endl;
    s = "hemnb";
    cout << "the longet prefix in trie of \"" << s << "\" is : ";
    cout << mytrie->get_longthest_prefix(s) << endl;

}
int main()
{
    test();
    return 0;
}
