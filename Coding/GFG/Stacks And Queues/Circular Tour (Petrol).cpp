//
//  30.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 09/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Circular Tour (Petrol)
//
// Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
// 1 . The amount of petrol that every petrol pump has.
// 2 . Distance from that petrol pump to the next petrol pump.
// Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.
//
// For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where the truck can make a circular tour is 2nd petrol pump. Output should be “start = 1” (index of 2nd petrol pump).

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
