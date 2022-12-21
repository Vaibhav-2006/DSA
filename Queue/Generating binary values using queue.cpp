#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 12;
    queue<string> q1;
    q1.push("1");
    while(num--)
    {
        string sd, st = q1.front();
        cout << st << ", ";
        sd = st;
        q1.pop();
        st.append("0");
        sd.append("1");
        q1.push(st);
        q1.push(sd);
    }    
    return 0;
}
