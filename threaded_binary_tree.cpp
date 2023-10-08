#include<bits/stdc++.h>
using namespace std;
typedef struct node node;

struct node{
    //left_thread 是true代表是tread ,false則有child
    bool left_thread,right_thread;
    node* left,*right;
    int data;
};
node* insuc(node* x)
{
    //找inorder順序的下一個點，看右child之最左child
    node* tmp=x->right;
    if(!x->right_thread)//若有右child
    {
        //找右child之最左child
        while(!tmp->left_thread) tmp=tmp->left;
    }
    return tmp;
}
node* inpre(node* x)
{
    //找inorder順序下一個點 看左child之最右child
    node* tmp=x->left;
    if(!x->left_thread)
    {
        while(!tmp->right_thread) tmp=tmp->right;
    }
    return tmp;
}
void inorder_traversal(node* tree)
{
    //找下一個inorder print
    node* tmp=insuc(tree);
    while(tmp!=tree)
    {
        cout << tmp->data << " ";
        tmp=insuc(tmp);
    }
}
node* init_node(int data)
{
    node* tmp=new node;
    tmp->data=data;
    return tmp;
}
void insert_left(node *t,node* s)
{
    //case1 s無左child
    if(s->left_thread)
    {
        t->left_thread=s->left_thread; //t->left_thread=true
        t->left=s->left; //s的left_thread給t_left_thread
        t->right_thread=true; //t之右thread(inorder順序)是s
        t->right=s;
        s->left_thread=false; //s左child為t
        s->left=t;
    }
    else//case2 s有左child
    {
        t->left_thread=s->left_thread;//t->left_thread=false
        t->left=s->left;
        t->right_thread=true; //t之右thread(inorder順序)是s
        t->right=s;
        s->left_thread=false; //s左child為t
        s->left=t;
        inpre(s)->right=t;//s之inpre指的位置要換t
    }
}
void insert_right(node *t,node* s)
{
    //case1 s無右child
    if(s->right_thread)
    {
        t->right_thread=s->right_thread; //t->right_thread=true
        t->right=s->right; //s的right_thread給t_right_thread
        t->left_thread=true; //t之左thread(inpre順序)是s
        t->left=s;
        s->right_thread=false; //s右child為t
        s->right=t;
    }
    else//case2 s有左child
    {
        t->right_thread=s->right_thread; //t->right_thread=true
        t->right=s->right; //s的right_thread給t_right_thread
        t->left_thread=true; //t之左thread(inpre順序)是s
        t->left=s;
        s->right_thread=false; //s右child為t
        s->right=t;
        insuc(s)->left=t;//s之insuc指的位置要換t
    }
}


int main()
{
    //要有一個head不存資料給inorder最左與最右的thread有地方指
    node* root = init_node(-1);
    root->left_thread=true;
    root->left=root;
    root->right_thread=false;
    root->right=root;
    insert_left(init_node(1),root);
    insert_left(init_node(3),root->left);
    insert_right(init_node(2),root->left);
    insert_right(init_node(4),root->left);
    insert_left(init_node(5),root->left->right);
    //   1
    //  /  \
    // 3     4
    //      /  \
    //     5     2
    inorder_traversal(root);
    return 0;
}