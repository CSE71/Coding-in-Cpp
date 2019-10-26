//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Number of decodings. A=1, B=2,C=3,....Z=26
//121 --> 3 {"ABA", "AU", "LA"}

#include <iostream>
#include <cstring>
using namespace std;
  
// A Dynamic Programming based function
// to count decodings
int countDecodingDP(char *digits, int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    
    int count[n+1];
    count[0] = 1;
    count[1] = 1;

    if(digits[0]=='0')
         return 0;
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
  
        
        if (digits[i-1] > '0')
            count[i] = count[i-1];
  
        if (digits[i-2]=='0' ||digits[i-2] == '1' ||
              (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }
    return count[n];
}
  
// Driver program to test above function
int main()
{
    char digits[] = "01";
    int n = strlen(digits);
    cout << "Count is " << countDecodingDP(digits, n);
    return 0;
}
