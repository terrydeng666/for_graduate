#include<bits/stdc++.h>
using namespace std;
typedef struct node node;

struct node{
    int data;
    int height;
    int parent_num;
    node* parent;
};
void simple_union(vector<node*> &set,int i,int j)
{
    set[j]->parent=set[i];
}
node* simple_find(vector<node*> &set,int x)
{
    node* tmp=set[x];
    while(tmp->parent!=tmp)
    {
        tmp=tmp->parent;
    }
    return tmp;
}
void union_by_weight(vector<node*> &set,int i,int j)
{
    if(set[i]->height > set[j]->height)
    {
        set[j]->parent=set[i];
    }
    else if(set[i]->height < set[j]->height)
    {
        set[i]->parent=set[j];
    }
    else//一樣高就j當parent 
    {
        set[i]->parent=set[j];
        set[j]->height++;
    }
}
node* find_with_path_compression(node* x)
{
    if(x!=x->parent) x->parent=find_with_path_compression(x);
    return x->parent;
}
int main()
{
    //寫爽的 跑出來也沒啥好看
    return 0;
}