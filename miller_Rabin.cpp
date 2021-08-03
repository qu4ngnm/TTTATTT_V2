#include<iostream>
#include <stdlib.h>
using namespace std;

int nhanBP(int a, int m, int n){
    int arr[100];
    int i = 0;
    while(m!=0){
        arr[i] = m % 2;     // convert to bin
        m /= 2;
        ++i;
    }
    m = 1;
    for(int j = 0; j < i; ++j){
        a = a*a % n;
        if(arr[j]==1){
            m = a*m % n;
        }
    }
    return m;
}
int Miller_Rabin(int n)
{
    int r=n-1;
    int s=0;
    while(r%2 == 0){
        r= r/2;
        s++;
    }
    int a = 2 + rand() % (n - 3);
    int t,y;
    for(int i=1 ; i<=t ;i++){
        y = nhanBP(a, r, n);
        if(y != 1 && y != n-1){
            int j = 1;
            while((j<= s -1) && (y!= n-1)){
                y = (y*y) % n;
                if(y ==1 ){
                    return 0;
                }
                j++;
            }
            if(y != n-1){
                return 0;
            }
        }
        else{
            return 1;
        }
    }
}
int main()
{
    int n;
    cout<<"Nhap n le: ";cin>>n;
    if( Miller_Rabin(n) == 1){
        cout<<n<<" la so nguyen to";
    }
    else{
        cout<<n<<" la hop so";
    }
}
