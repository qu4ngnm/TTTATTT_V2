//RHO
#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b==0){ return a;}
    return gcd(b,a%b);
}
int main()
{
    int n;
    cout<<"Nhap vao so nguyen n de ktra: ";cin>>n;
    int a = 2;
    int b = 2;
    int d=0;
    while(true){
        a = (a*a +1)%n;
        b = (b*b +1)%n;
        b = (b*b +1)%n;
        d = gcd(abs(a-b), n);
        if(1<d&&d<n){
            cout<<d;
            break;
        }
        if(d==n){
            cout<<"Day la so nguyen to";
            break;
        }
    }

}
