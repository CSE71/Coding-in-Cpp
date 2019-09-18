//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
// Tower of Hanoi

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod,
                  char to_rod, char aux_rod)  //SDT
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
        " to rod " << to_rod<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);//STD
    cout << "Move disk " << n << " from rod " << from_rod <<
    " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);//TDS
}

// Driver code
int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
