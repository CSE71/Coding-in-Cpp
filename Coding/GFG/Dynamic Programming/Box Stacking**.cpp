//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Box Stacking
/*
 You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.
 */
bool compare(tuple<int,int,int> a,tuple<int,int,int> b)
{
    return get<0>(a)*get<1>(a) > get<0>(b)*get<1>(b);
}
int maxHeight(int h[],int w[],int l[],int n)
{
    //Your code here
    
    vector<tuple<int,int,int>> box;
    for(int i=0;i<n;i++)
    {
        if(l[i]>w[i])
        box.push_back(make_tuple(l[i],w[i],h[i]));
        
        else
        box.push_back(make_tuple(w[i],l[i],h[i]));
        
        if(l[i]>h[i])
        box.push_back(make_tuple(l[i],h[i],w[i]));
        
        else
        box.push_back(make_tuple(h[i],l[i],w[i]));
        
        if(h[i]>w[i])
        box.push_back(make_tuple(h[i],w[i],l[i]));
        
        else
        box.push_back(make_tuple(w[i],h[i],l[i]));
        
        
    }
    sort(box.begin(),box.end(),compare);
    vector<int> ht;
    for(int i=0;i<3*n;i++)
    ht.push_back(get<2>(box[i]));
    int maxh =0;
    for(int i=1;i<3*n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(get<0>(box[j])>get<0>(box[i]) && get<1>(box[j])>get<1>(box[i]) &&
            ht[i]<ht[j]+get<2>(box[i]))
            ht[i]=ht[j]+get<2>(box[i]);
            
            maxh = max(maxh,ht[i]);
        }
    }
    return maxh;
    
}
