
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;


int minimum_time_wine(int B, int N, vector<int> samples)
{
    int count =0;
    if(B==1)
    {
        return N*samples[0];
    }

    vector<int> wait(B,0);

    while(1)
    {
        bool done =true;

        for(int i=0;i<B;i++)
        {
            ///
            cout<<"Samples : ";
            for(int c=0;c<B;c++)
                cout<<samples[c]<<" ";
            cout<<endl;

            cout<<"Wait : ";
            for(int c=0;c<B;c++)
                cout<<wait[c]<<" ";
            cout<<endl;

            cout<<"Count : "<<count<<endl<<endl;
            ///



            if(samples[i]>0)
            {
                done = false;

                if(wait[i]==0)
                {
                    samples[i]--;
                    wait[i] = N;
                }

                else{
                    wait[i]--;
                }
                count++;
            }

            for(int j=0;j<B;j++)
            {
                if(j!=i && wait[j]>0)
                    wait[j]--;
            }


        }

        if(done)
            break;
    }

    return count;
}

int main()
{
    int B,N;
    cin>>B>>N;

    vector<int> samples(B,0);
    for(int i=0;i<B;i++)
    cin>>samples[i];


    cout<<minimum_time_wine(B,N,samples);

    return 0;

}
