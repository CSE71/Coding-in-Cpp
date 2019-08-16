//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Merge sort : Counting Inversions

#include<iostream>
#include<cstdio>

using namespace std;

long long ans=0;
void mergei(int a[],int low,int mid,int high)
{
    int i=low,k=low,j=mid+1,b[1000001]; // Important 10000001
    
    while(i<=mid && j<=high)
    {
        
        
        if(a[i]<=a[j]) // < =
            b[k++] = a[i++];
        else
        {
            b[k++] = a[j++];
            ans+=mid+1-i; //This is the vital part
        }
    }
    while(i<=mid)
    {
        
        b[k++] = a[i++];
        
    }
    while(j<=high)
    {
        
        b[k++] = a[j++];
    }
    
    for(i=low;i<=high;i++)
    {
        a[i] = b[i];
    }
    
}

void m_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        m_sort(a,low,mid);
        m_sort(a,mid+1,high);
        mergei(a,low,mid,high);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ans=0;
        scanf("%d",&n);
        int * a = new int[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        m_sort(a,0,n-1);
        cout<<ans<<endl;
        
    }
    return 0;
}
