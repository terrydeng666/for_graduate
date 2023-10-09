#include<bits/stdc++.h>
using namespace std;
//max heap 且 1為 root
void heapify(vector<int> &tree,int i,int n)
{
    //i 為root
    int x=tree[i];
    int j=2*i;
    //j<=n代表有左child
    while(j<=n)
    {
        //有右child 且 左child < 右child
        if(j+1<=n && tree[j] < tree[j+1]) j++;
        if(x>=tree[j]) break;//不需swap 
        else
        {
            //最大的child取代i之位置 
            //再去跟最大child之左child 比較
            tree[j/2]=tree[j];
            j*=2;
        }
    }
    tree[j/2]=x;
}
void buildheap(vector<int> &tree,int n)
{
    //complete BT中 last parent 為n/2取floor
    //從最後一個parent開始調整
    for(int i=n/2;i>=1;i--)
    {
        heapify(tree,i,n);
    }
}
int main()
{
    int n=0;
    cin >> n;
    vector<int> tree(n+1,0);
    int ex[] ={2,4,8,16,32,64,128,256,512,1024};

    for(int i=1;i<=n;i++)
    {
        cin >> tree[i];
    }
    buildheap(tree,n);
    int k=0;
    for(int i=1;i<=n;i++)
    {
        cout << tree[i] << " ";
        if(i==ex[k]-1)
        {
            cout << "\n";
            k++;
        }
    }
    return 0;
}
