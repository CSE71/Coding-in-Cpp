//
//  2.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Triplet sum

////////////////////////
///2 Solutions
///////////////////////



#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
    int a,n,count;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>n;
        int arr[n],num;
        for(int j=0;j<n;j++)
        {
            cin>>num;
            arr[j]=num;
        }
        sort(arr,arr+n);
        int l,h,sum;
        count =0;
        
        for(int j=n-1;j>=0;j--)
        {
            l=0;
            h=j-1;
            while(l<h)
            {
                
                sum = arr[l]+arr[h];
                if(sum==arr[j])
                {
                    count++;
                    h--;
                    l++;
                }
                else if(sum>arr[j])
                {
                    h--;
                }
                else
                l++;
            }
        }
        
        if(count!=0)
        cout<<count<<"\n";
        
        else
        cout<<-1<<"\n";
    }
    
    return 0;
}



//For efficient but not large values (Frequency method)
/*
#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
    vector<int> v;
    int a,n,sum,count;
    int maxi=0;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>n;
        v.clear();
        count =0 ;
        for(int j=0;j<n;j++)
        {
            cin>>sum;
            v.push_back(sum);
            maxi = max(maxi,sum);
        }
        int arr[maxi+1] = {0};
        for(int j=0;j<n;j++)
        arr[v[j]]++;
        
        //Case 1
        count+= arr[0]*(arr[0]-1)*(arr[0]-2)/6;
        
        //Case 2
        for(int j=1;j<=maxi;j++)
        count+=arr[j]*(arr[j]-1)/2*arr[0];
        
        //Case 3
        for(int j=1;2*j<=maxi;j++)
        count+=arr[j]*(arr[j]-1)/2*arr[2*j];
        
        //Case 4
        for(int j=1;j<=maxi;j++)
        {
            for(int k=j+1;j+k<=maxi;k++)
            {
                count+=arr[j]*arr[k]*arr[j+k];
            }
        }
        
        
        
        if(count!=0)
        cout<<count<<"\n";
        else
        cout<<"-1"<<"\n";
        
    }
    
    return 0;
}
*/
