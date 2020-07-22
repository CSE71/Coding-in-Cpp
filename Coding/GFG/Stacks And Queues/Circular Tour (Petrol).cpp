//
//  30.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 09/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Circular Tour (Petrol)

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>

    using namespace std;
    struct petrolPump
    {
        int petrol;
        int distance;
    };
    int tour(petrolPump [],int );
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            petrolPump p[n];
            for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
            cout<<tour(p,n)<<endl;
        }
    }


/*This is a function problem.You only need to complete the function given below*/
/*
 The structure of petrolPump is
 struct petrolPump
 {
 int petrol;
 int distance;
 };*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
    //Your code here
    int petrol =0;
    int flag;
    for(int i=0;i<n;i++)
    {
        flag=1;
        petrol = p[i].petrol;



        if(petrol<p[i].distance)
        {
            flag=0;
        }

        petrol -=p[i].distance;

        if(flag==1)
        {
            for(int j=(i+1)%n;j!=i;j=(j+1)%n)
            {
                petrol+=p[j].petrol;
                if(petrol<p[j].distance)
                {
                    flag=0;

                }

                petrol -=p[j].distance;
            }
        }

        if(flag==1)
        {
            return i;
        }
        /*
         else
         {
         int l = (i+n-1)%n;
         petrol = p[i].petrol;

         if(petrol<p[l].distance)
         continue;

         petrol -=p[l].distance;

         for(int j=(l+n-1)%n;j!=i;j=(j+n-1)%n)
         {
         petrol+=p[j].petrol;
         if(petrol<p[j].distance)
         continue;

         petrol -=p[j].distance;
         }
         return i;
         }
         */
    }
    return -1;

}

// Better solutions : https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
