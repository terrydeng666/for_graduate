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
   if(x==')') return ">";//)在stack外優先權最大
   if(m[x] == m[y] && (m[y]==3 || m[y]==2)) return ">";//原本左結合變右結合
   if(m[x]> m[y]) return ">";
   return "<="; 
}
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    stack<char> st2;//多一個stack逆向輸出
    st.push('!');//emtpy stack
    m['!']=-1;
    m[')']=1;
    m['+']=2;
    m['-']=2;
    m['*']=3;
    m['/']=3;
    m['^']=4;
    for(int i=s.length()-1;i>=0;i--)
    {
        char x=s[i];
        if(is_operend(x)) // 運算元直接印
        {
            st2.push(x);
        }
        else
        {
            if(x=='(')//遇到左括號把stack全部印出來 直到遇到右括號
            {
                char y;
                do
                {
                    y=st.top();
                    st.pop();
                    if(y!=')') st2.push(y);
                } while (y!=')');
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
                        st2.push(y);
                    } while (compare_priority(x,st.top())=="<=");
                    st.push(x);
                }
            }
        }
    }
    while(st.top()!='!')
    {
        st2.push(st.top());
        st.pop();
    }
    while (!st2.empty())
    {
        cout << st2.top();
        st2.pop();
    }
    
    
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}