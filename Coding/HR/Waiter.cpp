
//
//  Waiter.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 07/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}
vector<int> waiter(vector<int> number, int q) {
    /*
     * Write your code here.
     */
    vector<int> prime;
    vector<int> output;
    int i=0,cnt=2;
    while(i<1205)
    {
        if(isPrime(cnt))
        {
            prime.push_back(cnt);
            i++;
        }
        cnt++;
    }
    stack<int> a[1205];
    stack<int> b[1205];
    for(int i=0;i<number.size();i++)
        a[0].push(number[i]);
    
    for(int i=0;i<q;i++)
    {
        while(!a[i].empty())
        {
            int num = a[i].top();
            a[i].pop();
            
            if(num%prime[i]==0)
            {
                b[i+1].push(num);
            }
            else
            {
                a[i+1].push(num);
            }
            
        }
    }
    
    for(int i=1;i<=q;i++)
    {
        while(!b[i].empty())
        {
            output.push_back(b[i].top());
            b[i].pop();
        }
    }
    while(!a[q].empty())
    {
        output.push_back(a[q].top());
        a[q].pop();
    }
    return output;
}
