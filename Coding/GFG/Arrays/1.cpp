//
//  1.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Continous Subarray sum 

#include <iostream>
#include<vector>
using namespace std;

int main() {
    //code
    int a,n,sum,num;
    vector<int> arr;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>n>>sum;
        for(int j=0;j<n;j++)
        {
            cin>>num;
            arr.push_back(num);
        }
        
        int summ,pos,flag=0;
        for(int j=0;j<n;j++)
        {
            summ=arr[j];
            pos =j;
            if(summ==sum)
            {
                cout<<pos+1<<" "<<pos+1<<"\n";
                flag=1;
                break;
            }
            for(int k=j+1;k<n;k++)
            {
                summ+=arr[k];
                if(summ>sum)
                break;
                else if(summ<sum)
                continue;
                else
                {
                    cout<<pos+1<<" "<<k+1<<"\n";
                    flag=1;
                    break;
                }
                
            }
            if(flag==1)
            break;
            
        }
        if(flag!=1)
        cout<<-1<<"\n";
        arr.clear();
    }
    
    return 0;
}
