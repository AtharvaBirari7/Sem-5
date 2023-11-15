#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	cout<<"\n\n-----OPTIMAL page replacement -----"<<endl;
	int n,f,front;
	float hit=0.0;
	cout<<"Enter size of reference string"<<endl;
	cin>>n;
	char stream[n];
    char queue[n];
    vector<int> hi(n);
	cout<<"Enter reference string"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>stream[i];
	}
	cout<<"Enter frame size"<<endl;
	cin>>f;

    for(int i=0;i<n;i++)
	{
		queue[i]=stream[i];
	}
    front=0;
	char table[f][n];
	char frame[f];
	for(int i=0;i<f;i++)
	{
		frame[i]='e';
	}
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<n;j++)
		{
			table[i][j]='e';
		}
	}
	for(int i=0;i<n;i++)
	{
		int re=0;
		for(int j=0;j<f;j++)
		{
			if(frame[j]=='e')
			{
				frame[j]=stream[i];
				re=1;

				for (int k = 0; k < f; k++)
				{
					table[k][i]=frame[k];
				}

				break;
			}
			else if (stream[i]==frame[j])
			{
				hit=hit+1;
                hi[i]=1;
				re=1;
				for (int k = 0; k < f; k++)
				{
					table[k][i]=frame[k];
				}
				break;
			}

		}
		if(re==0)
		{
            int count=0;
            int change=-1;
			if(i==n-1)
			{
				frame[0]=stream[i];
				for (int k = 0; k < f; k++)
				{
					table[k][i]=frame[k];
				}
				break;
			}
			for(int m=0;m<f;m++)
			{
                for(int p=i;p<n;p++)
                {
                    if(frame[m]==stream[p])
                    {
                        if(p>count)
                        {
                            count=p;
                            change=m;
                            break;
                        }
                        else
                        {
                            break;
                        }

                    }
                    else if (p==n-1)
                    {
                        count=99;
                        change=m;
                        break;
                    }
                }

			}
            if(change>=0)
            {
                frame[change]=stream[i];
				for (int k = 0; k < f; k++)
				{
					table[k][i]=frame[k];
				}

            }



		}
	}
	cout<<"\nStream | ";
	for(int i=0;i<n;i++)
	{
		cout<<stream[i]<<"  ";
	}
    cout<<endl;
    cout<<"------ | ";
    for(int i=0;i<n;i++)
	{
		cout<<"---";
	}
    cout<<endl;
	for(int i=0;i<f;i++)
	{
		cout<<"Frame"<<i<<" | ";
		for(int j=0;j<n;j++)
		{
			cout<<table[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<"------ | ";
    for(int i=0;i<n;i++)
	{
		cout<<"---";
	}
	cout<<endl;
	cout<<"       | ";
	for(int i=0;i<n;i++){
        if(hi[i]==0)
        cout<<"M  ";
        else
        cout<<"H  ";
    }
    cout<<endl;
	cout<<"\nNumber frames= "<<f<<endl;
	cout<<"Number of page hit= "<<hit<<endl;
	cout<<"Number of page fault= "<<n-hit<<endl;
	float hit_ratio=hit/n;
	cout<<"Hit Ratio= "<<hit_ratio<<endl<<endl;
	return 0;
}
