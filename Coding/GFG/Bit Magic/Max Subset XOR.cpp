
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


// Max Subset XOR
int maxSubarrayXOR(int A[], int n)
{
     int index =0;
     for(int i=31;i>=0;i--)
     {
        int max =-1,maxind=-1;
        for(int j=index;j<n;j++)
        {
            if((A[j] & (1<<i))!=0 && A[j]>max) // Brackets matter.
            {
                max = A[j];
                maxind = j;
            }
        }
        
        if(max ==-1)
        continue;
        
        swap(A[index],A[maxind]);// Cant check this number again for the lower bits. ex. 7,3 - 111, 011 - > for 2nd bit 7 is still greater but we shouldnt consider 7.
        maxind = index;//After swapping max value at index 'index'
        
        for(int j=0;j<n;j++)
        {
            if(j!=maxind && (A[j] & (1<<i))!=0)
            A[j] ^= A[maxind];
        }
        index++;
    }
    int res =0;
    for(int i=0;i<n;i++)
    res^=A[i];
    
    return res;
    
}



