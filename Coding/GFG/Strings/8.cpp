
//
//  8.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

// Reverse words in a sentence

#include<bits/stdc++.h>
using namespace std;

void reverse(char *begin, char *end);

/*Function to reverse words*/
void reverseWords(char *s)
{
    char *word_begin = s;
    char *temp = s; /* temp is for word boundry */
    
    /*STEP 1 of the above algorithm */
    while( *temp )
    {
        temp++;
        if (*temp == '\0')
        {
            reverse(word_begin, temp-1);
        }
        else if(*temp == '.')
        {
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    } /* End of while */
    
    /*STEP 2 of the above algorithm */
    reverse(s, temp-1);
}

/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
 begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/* Driver function to test above functions */
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[100];
        cin>>s;
        reverseWords(s);
        cout<<s<<endl;
    }
    
}


/*
 
 #include <iostream>
 #include<string.h>
 using namespace std;
 
 void reverse(char *s)
 {
 int n = strlen(s);
 char rev[n];
 for(int i=0;i<n;i++)
 {
 rev[i] = s[n-i-1];
 }
 for(int i=0;i<n;i++)
 {
 s[i] = rev[i];
 }
 }
 void reversewordbyword(char arr[])
 {
 char s[2001],rev[2001];
 int n = strlen(arr);
 reverse(arr);
 arr[n]='\0';
 //cout<<1<<arr[0];
 //cout<<arr<<endl;
 int k=0,l=0;
 for(int i=0;arr[i]!=NULL;i++)
 {
 if(arr[i]!='.'||arr[i]!=NULL)
 s[k++] =arr[i];
 
 
 else
 {
 //cout<<s<<endl;
 reverse(s);
 //cout<<s<<endl;
 n = strlen(s);
 for(int j=0;j<n;j++)
 {
 rev[l++]=s[n-j-1];
 }
 if(arr[i]=='.')
 rev[l++] ='.';
 
 else if(arr[i]=='\0')
 {
 //rev[l++]='\0';
 break;
 }
 fill_n(s, n, 0);
 k=0;
 }
 
 }
 
 cout<<rev<<endl;
 }
 int main() {
 //code
 int a,n=0;
 cin>>a;
 for(int i=0;i<a;i++)
 {
 char arr[2001];
 cin>>arr;
 reversewordbyword(arr);
 }
 return 0;
 }
 */
