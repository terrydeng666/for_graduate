#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text,pattern;
    cin >> text >> pattern;
    vector<int> prefix(pattern.length(),0);
    //prefix function
    //拿pattern和pattern比較
    int k=-1;//目前最大前後綴長度-1
    //從第二個字元開始比
    prefix[0]=-1;
    for(int i=1;i<pattern.length();i++)
    {
        while(k>=0 && pattern[k+1]!=pattern[i])
        {
            //比對到i時，最大長度小於k，從k的最大前綴prefix[k]繼續比
            //a b a b a a 假設i=5 在i=4時最大前後綴為aba
            //這時 因為pattern[5]!=pattern[3](pattern[k+1])
            //所以從prefix[3]的長度(1)繼續比 看前面的ab能不能和後面match
            k=prefix[k];
        }
        if(pattern[k+1]==pattern[i]) k++;
        prefix[i]=k;
    }
    //string matching
    k=-1;
    for(int i=0;i<text.length();i++)
    {
        while(k>=0 && pattern[k+1]!=text[i]) k=prefix[k];
        if(pattern[k+1]==text[i])k++;
        if(k==pattern.length()-1) cout << "valid shift " << i-k << "\n";
    }

    for(int i=0;i<prefix.size();i++)//print prefix
    {
        cout << prefix[i]+1 << " ";
    }
    return 0;
}