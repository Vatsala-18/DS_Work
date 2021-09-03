#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    struct TrieNode *child[26];
    bool isEnd;
};
TrieNode *newnode()
{
    TrieNode *temp = new TrieNode();
    for(int i = 0; i < 26; i++)
    {
        temp->child[i] = NULL;
    }
    temp->isEnd = false;
    return temp;
}
void insert(TrieNode *root,string key){
     for(int i=0;i<key.length();i++){
         if(!root->child[key[i]-'a'])
            root->child[key[i]-'a'] = newnode();
        root = root->child[key[i]-'a'];
     }
     root->isEnd = true;
}
bool search(TrieNode *root,string key){
    for(int i=0;i<key.length();i++){
        if(!root->child[key[i]-'a'])
           return false;
        root = root->child[key[i]-'a'];
    }
    return (root != NULL && root->isEnd);
}
void deletion(TrieNode *root, string key){

     
    for(int i = 0; i < key.length(); i++)
    {
        if(!root->child[key[i] - 'a'])
            return;
        root = root->child[key[i] - 'a'];
    }
    root->isEnd = false;

}
int main(){
    int ch;
    TrieNode *root = new TrieNode();
    string key;
    do{
        cout<<"\nMenu : \n1. Insert\n2. Search\n3. Delete\n0. Exit";
        cin>>ch;
        switch(ch){
            case 1 : cin>>key;
                     insert(root,key);
                     break;
            case 2 : cin>>key;
                     if(search(root,key))
                        cout<<key<<" is present.\n";
                     else
                        cout<<key<<" is not present.\n";
                     break;
            case 3 : cin>>key;
                     deletion(root,key);
                     cout<<key<<" is deleted.\n";
                     break;
            case 0 : exit(0);
        }
    }while(ch!=0);
}