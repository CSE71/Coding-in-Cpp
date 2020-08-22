#include<bits/stdc++.h>
using namespace std;

int maxWater(int height[], int n)
{
    int maximum = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {

        if (height[i] < height[j])
        {
            maximum = max(maximum, (j - i - 1) * height[i]);
            i++;
        }

        else if (height[j] < height[i])
        {
            maximum = max(maximum, (j - i - 1) * height[j]);
            j--;
        }

        else
        {
            maximum = max(maximum, (j - i - 1) * height[i]);
            i++;
            j--;
        }
    }

    return maximum;
}


// Driver code
int main()
{

    int height[] = { 2, 1, 3, 4, 6, 5 };
    int n = sizeof(height)/sizeof(height[0]);
    cout<<(maxWater(height, n));
}
