#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_operend(char c)
{
    return !( c=='(' || c==')' || c=='*' || c=='/' || c=='+' || c=='-' || c=='^');
}
map<char,int> m;
string compare_priority(char x,char y)
{
   if(x=='(') return ">";//(在stack外優先權最大
   if(x=='^' && y=='^') return ">";//^在stack外優先權較大 右結合
   if(m[x]> m[y]) return ">";
   return "<="; 
}
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    st.push('!');//emtpy stack
    m['!']=-1;
    m['(']=1;
    m['+']=2;
    m['-']=2;
    m['*']=3;
    m['/']=3;
    m['^']=4;
    for(int i=0;i<s.length();i++)
    {
        char x=s[i];
        if(is_operend(x)) // 運算元直接印
        {
            cout << x;
        }
        else
        {
            if(x==')')//遇到右括號把stack全部印出來 直到遇到左括號
            {
                char y;
                do
                {
                    y=st.top();
                    st.pop();
                    if(y!='(') cout << y;
                } while (y!='(');
            }
            else
            {
                string tmp=compare_priority(x,st.top());
                if(tmp==">")//優先權大於stack上方直接push
                {
                    st.push(x);
                }
                else
                {
                    char y;//優先權小於等於則因出stack直到找到優先權大於的
                    do
                    {
                        y=st.top();
                        st.pop();
                        cout << y;
                    } while (compare_priority(x,st.top())=="<=");
                    st.push(x);
                }
            }
        }
    }
    while(st.top()!='!')
    {
        cout << st.top();
        st.pop();
    }
    
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}
