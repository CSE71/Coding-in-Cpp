//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Number of deletions to get alternating string
int alternatingCharacters(string s) {
    
    int count =0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1])
        count++;
    }
    return count;
}
