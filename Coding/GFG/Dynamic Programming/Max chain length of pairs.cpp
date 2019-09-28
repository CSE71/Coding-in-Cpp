//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Max chain length of pairs

//DP
bool compare(val a,val b)
{
    if(a.first==b.first)
    return a.second<b.second;
    
    return a.first<b.first;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,p+n,compare);
    vector<int> count(n,1);
    int max = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[i].first>p[j].second && count[i]<count[j]+1)
            count[i]=count[j]+1;
            if(max<count[i])
            max = count[i];
        }
    }
    
    return max;
}

//Greedy
bool customSort (val a, val b) // Different sort. (The least p[].second will definetly be included)
{
if(a.second != b.second) return a.second < b.second;
else return a.first < b.first;
}
int maxChainLen(struct val p[],int n)
{
if(n == 1 || n==0) return n;
sort(&p[0],&p[n], customSort);

int end = p[0].second;
int count = 1;
for(int i=0; i<n; i++)
{
    if(p[i].first> end)
    {
count++;
end = p[i].second;
}
}
return count;
}
