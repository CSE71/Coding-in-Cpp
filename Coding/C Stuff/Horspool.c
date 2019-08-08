//
//  Horspool.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include<stdio.h>
#include<string.h>

void tablecreate(int T[],int m,char pat[])
{
    int i;
    for(i=0;i<256;i++)
        T[i]=m;
    
    for(i=0;i<m-1;i++)
        T[pat[i]] = m-i-1;
    
}

void horspool(char text[],char pat[])
{
    int n,m,T[256];
    n = strlen(text);
    m = strlen(pat);
    
    
    tablecreate(T,m,pat);
    
    int i = m-1,k,flag =0;
    
    while(i<n)
    {
        k=0;
        while(text[i-k] == pat[m-k-1] && k<m)
            k++;
        
        if(k==m)
        {
            flag=1;
            printf("Pattern found at position %d\n",i-m+2);
            
        }
        
        i = i+T[text[i]];
        
    }
    if(flag==0)
    {
        printf("Pattern not found \n");
    }
    
    
    
}

int main()
{
    char text[500],pat[500];
    printf("Enter Text : ");
    gets(text);
    fflush(stdin);
    printf("Enter Pattern : ");
    scanf("%s",pat);
    
    horspool(text,pat);
    
    
    
}

