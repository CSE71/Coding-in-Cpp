#include <bits/stdc++.h>

using namespace std;


#define SIZE(x) (int)x.size()

#define LEN(x) (int)x.length()


vector<string> checkDivisibility(vector<string> arr) {

    string a;

    vector<string> ans;

    for(int i=0;i<SIZE(arr);i++)
    {

        a = arr[i];

        if(LEN(a)<3)
        {

            if(stoi(a)%8==0)
            ans.push_back("YES");

            else{

            reverse(a.begin(),a.end());

            if(stoi(a)%8==0)
                ans.push_back("YES");

            else
                ans.push_back("NO");
            }

            continue;

        }

        else
        {

            vector<int> mp(10,0);
            for(int j=0;j<LEN(a);j++)
            mp[a[j]-'0']++;


            // for(int j=0;j<10;j++)

            // cout<<mp[j]<<" ";

            // cout<<endl;

            int found=0;

            for(int j=104;j<1000;j+=8)
            {

                int temp =j;

                vector<int> cur_j(10,0);
                cur_j[temp%10]++;
                temp/=10;
                cur_j[temp%10]++;
                temp/=10;
                cur_j[temp%10]++;

                temp=j;

                if(cur_j[temp%10]>mp[temp%10])
                continue;

                temp/=10;

                if(cur_j[temp%10]>mp[temp%10])
                continue;

                temp/=10;

                if(cur_j[temp%10]>mp[temp%10])
                continue;

                ans.push_back("YES");
                found=1;
                break;

            }

            if(found==0)
            ans.push_back("NO");

        }

    }

    return ans;

}
