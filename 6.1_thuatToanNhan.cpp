#include <iostream>
#include <math.h>

using namespace std;

void chuyenSoSangMang(int t,int w,long long int a,int b[])
{
	int k,c[t+1],j=3;
	for(int i=0;i<t;i++)
	{
		k=a/(pow(2,(t-(i+1))*w));
		if(k==0)
		{
			c[i] =0;
			continue;
		}
		else
		{
			c[i]=k;
			a=a-k*(pow(2,(t-(i+1))*w));
		}
	}

	for(int i=0;i<t;i++) //nghich dao lai cac phan tu
	{
		b[i] = c[j];
		j--;
	}
}
void thuatToanNhan(long long int a,long long int b,int t,int w,int arr[])
{
	int c[t+1],d[t+1],e,u,v;
	chuyenSoSangMang(t,w,a,c);
	chuyenSoSangMang(t,w,b,d);
	for(int i=0;i<t;i++)
	{
		arr[i]=0;
	}
	for(int i=0;i<t;i++)
	{
		u=0;
		for(int j=0;j<t;j++)
		{
			e=arr[i+j]+c[i]*d[j]+u;
			v=0;
			for(int k=0;k<8;k++)
			{
				v+=(e%2)*pow(2,k);
				e = e/2;
			}
			u=e;
			arr[i+j]=v;	
		}
		arr[i+t] =u;	
	}
}

int main()
{
	int w,t,m;
	long long int a,b,p;
	cin>>p;
	cin>>w;
	cin>>a;
	cin>>b;
	m = log2(p);
	t= (m/w)+1;
	int arr[t+1];
	thuatToanNhan(a,b,t,w,arr);
	for(int i=7;i>=0;i--)
	{
		cout<<arr[i]<<"  ";
	}
}
