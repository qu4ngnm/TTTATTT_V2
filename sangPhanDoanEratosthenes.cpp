#include <iostream>
#include <math.h>

using namespace std;

bool check[100000];

void eratosthenes(long int n)
{
	for(int i=2;i<=n;i++)
	{
		check[i]=true;
	}
	int k=2;
	while(k<=n)
	{
		if(check[k]==true)
		{
			cout<<"\np="<<k<<endl;
			for(int j=2*k;j<=n;j+=k)
			{
				check[j] = false;
			}
			for(int i=2;i<=n;i++)
			{
				if(check[i]==true)
				{
					cout<<i<<"  ";
				}
			}
		}
	
		k++;
	}
}
int main()
{
	long long int n,low,hight;
	long int delta,k=1,d,m,dem=1;
	cin>>n;
	cin>>delta;
	cout<<"Chia pham vi tu 2 den "<<n<<" thanh cac doan co kich co "<<delta<<endl;
	for(int i=2;i<=n;i++)
	{
		check[i] = true;
		if(i==n)
		{
			cout<<i;
			break;
		}
		cout<<i<<"  ";
		if(k==delta)
		{
			cout<<"||";
			k=0;
		}
		k++;
	}
	low = delta +2;
	hight = (low+delta)-1;
	d = delta +1;
	cout<<"\nXet doan "<<dem<<":";
	eratosthenes(d);
	while(hight<=n && low <=n)
	{	
	dem++;
		cout<<"\nXet doan "<<dem<<":";
		m = sqrt(hight);
		for(int i=2;i<=hight;i++)
		{
			if(check[i]==true && i<=m)
			{
				cout<<"\np="<<i<<endl;
				for(int j=low;j<=hight;j++)
				{
					if(check[j]==true)
					{
						for(int h=2*i;h<=hight;h+=i)
						{
							if(j == h)
							{
								check[j] = false;
							}
						}
						if(check[j]== true)
						{
							cout<<j<<" ";
						}
					}
				}
			}
		}
		hight += delta;
		low += delta;
		if(hight>n)
		{
			hight = n;
		}
	}
	cout<<"\nTat ca cac so nguyen to <= "<<n<<":"<<endl;
	for(int i=2;i<=n;i++)
	{
		if(check[i]==true)
		{
			cout<<i<<"  ";
		}
	}
	
}
