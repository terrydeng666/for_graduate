#include<bits/stdc++.h>
using namespace std;
typedef struct node node;
//bst
struct node{
    node* left,*right;
    int l_num;
    int data;
};

node* insert(node* tree,int data)
{
    if(!tree)
    {
        node* tmp=new node;
        tmp->left=NULL;
        tmp->right=NULL;
        tmp->data=data;
        tmp->l_num=0;
        return tmp;
    }
    if(data < tree->data)
    {
        tree->left=insert(tree->left,data);
    }
    else
    {
        tree->right=insert(tree->right,data);
    }
    return tree;
}
int cnt_lnum(node*tree)//return tree之子樹node數
{
    if(!tree) return 0;
    int l=cnt_lnum(tree->left),r=cnt_lnum(tree->right);
    tree->l_num=l;
    return l+r+1;
}
int ith_element(node* tree,int i)
{
    if(tree)
    {
        int k=tree->l_num+1;
        
        if(i==k) return tree->data;
        else if(i<k) return ith_element(tree->left,i);
        else return ith_element(tree->right,i-k);//扣掉左邊k個
    }
    return 0;
}
void inorder(node* tree)
{
    if(!tree) return;
    inorder(tree->left);
    //cout << tree->data << " left:" <<tree->l_num << " " ;
    inorder(tree->right);
}
int main()
{
    int n;
    cin >> n;
    node* bst=NULL;
    int tmp=0;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        bst=insert(bst,tmp);
    }
    cnt_lnum(bst);
    inorder(bst);
    cout << "input i:\n";
    int x=0;
    cin >> x;
    cout << ith_element(bst, x);

    return 0;
}