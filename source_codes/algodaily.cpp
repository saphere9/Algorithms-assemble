#include<bits/stdc++.h>

using namespace std;

void overpay(int *d,int n,int p)
{
    int c[n],copy=p,sum=0,k;
    bool b=false,check=false;
    for (int i = n-1; i >=0; i--)
    {
        {if(p%d[i]!=0)
        {
            b=true;
            if(d[i]>p)
            {
                check=true;
                c[i]=1;
                for(int j=0;j<i;j++)
                {
                    c[j]=0;
                }
            }
            else
            {
                c[i]=copy/d[i];
                copy=copy%d[i];
            }    
        }
        else
        {    
            c[i]=0;
        }}
        if(check==true)
            break;
    }
    if(b==false)
     cout<<"NO"<<endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            sum+=c[i]*d[i];
        }
        for (int i = 0; i < n; i++)
        {
            if(c[i]!=0)
            {
                k=i;
                break;
            }
        }
        while(sum-p<0)
        {    c[k]+=1;
             sum+=d[k];
        }
        cout<<"YES"<<" ";
        for (int i = 0; i < n; i++)
        {
            cout<<c[i]<<" ";
        }
    }
}

int  main()
{
    int t;
    cin>>t;
    while(t--!=0)
    {
        int n,p;
        cin>>n>>p;
        int *d=new int[n];
        for(int i=0;i<n;i++)
            cin>>d[i];
        overpay(d,n,p);    
    }
}