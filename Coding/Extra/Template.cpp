//
//  1.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Template

//compiler will automatically generate correct code for the type of data used while executing the function.

template<class X>
void swap(X &a, X &b)
{
    X tp = a;
    a = b;
    b = tp;
}

