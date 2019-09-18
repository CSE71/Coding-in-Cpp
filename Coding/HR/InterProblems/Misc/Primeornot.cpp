//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

//Prime or not O(sqrt(n))

string primality(int n) {
    
    if(n==0 || n==1)
        return "Not prime";
    
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return "Not prime";
    }
    
    return "Prime";
    
}
