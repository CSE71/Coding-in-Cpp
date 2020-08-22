// To get all combinations of a string/array. (Do this when no other option)

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;


int x=0;
void diff_combi(string s, int n, int i, string cur)
{
    if(i==n)
    {
        cout<<x+1<<" "<<cur<<endl;
        x++;
        return;
    }

    cur+=s[i];
    print_perm(s, n, i+1, cur);
    cur.pop_back();
    print_perm(s, n, i+1, cur);



}
int main()
{
    string s;
    cin>>s;
    int n=(int)s.length();
    string cur="";
    print_perm(s,n,0,cur);
    cout<<endl<<x;
}
