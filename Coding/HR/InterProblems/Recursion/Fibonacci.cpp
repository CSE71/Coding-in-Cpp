//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Fibonacci

#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    if(n==0)
    return 0;
    
    if(n==1)
    return 1;
    
    return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}


