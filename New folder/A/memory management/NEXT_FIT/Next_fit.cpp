#include<iostream>
using namespace std;
int main()
{
    cout<<"\n\n-----NEXT FIT-----"<<endl;
    cout<<"Enter total number of processes"<<endl;
    int n;
    cin>>n;
    cout<<"Enter total number of partitions"<<endl;
    int pn;
    cin>>pn;
    string pr[n];
    int size[n];
    int block[n];
    int partion[pn];
    string fit[pn];
    int alloc[pn];
    int addr[pn+1];
    float total=0;
    float used=0;
    addr[0]=0;
    for(int i=0;i<n;i++)
    {
        block[i]=-1;
    }
    for(int i=0;i<pn;i++)
    {
        partion[i]=i+1;
    }
    for(int i=0;i<pn;i++)
    {
        fit[i]="NA";
    }
    cout<<endl;
    cout<<"Enter processes:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter pr["<<i+1<<"]: ";
        cin>>pr[i];
    }
    cout<<endl;
    cout<<"Enter partition sizes:"<<endl;
    for(int i=0;i<pn;i++)
    {
        cout<<"Enter size of partition["<<i+1<<"]: ";
        cin>>alloc[i];
    }
    cout<<endl;
    cout<<"Enter process sizes:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter size of pr["<<i+1<<"]: ";
        cin>>size[i];
    }
    for(int i=1;i<pn+1;i++)
    {
        addr[i]=addr[i-1]+alloc[i-1];
        total=addr[i];
    }
    int p=0;
    int last_allocated = 0;
    while(p<n)
    {
        int i = last_allocated;
        do {
            if(alloc[i]>=size[p] && fit[i]=="NA")
            {
                fit[i]=pr[p];
                used=used+size[p];
                block[p]=i+1;
                last_allocated = i;
                break;
            }
            i = (i+1) % pn;
        } while(i != last_allocated);
        p++;
    }
    cout<<endl;
    cout<<"Processes"<<"\t"<<"Size"<<"\t"<<"Partition no."<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<pr[i]<<"\t\t"<<size[i]<<"k\t\t"<<block[i]<<endl;
    }
    cout<<endl;
    cout<<"Partition"<<"\t\t"<<"Allocation"<<"\t\t\t"<<"Address"<<endl;
    int m=0;
    while(m<pn+1)
    {
        for(int i=m;i<m+1;i++)
        {
            if(i<pn)
            {
                cout<<partion[i]<<"\t\t\t";
            }
            else{
                cout<<"\t\t\t";
            }

        }
        for(int j=m;j<m+1;j++)
        {
            if(m<pn)
            {
                cout<<fit[j]<<"["<<alloc[j]<<"k]\t\t";
            }
            else{
                cout<<"\t\t\t";
            }

        }
        for(int k=m;k<m+1;k++)
        {
            cout<<"\t"<<addr[k]<<"k";
        }
        cout<<endl;
        m++;

    }
    cout<<"\n Memory used="<<used;
    cout<<"\n Total memory="<<total;
    cout<<"\n Memory utlized= "<<used/total;
    return 0;
}
