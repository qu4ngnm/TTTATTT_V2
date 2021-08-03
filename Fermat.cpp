//Fermat

#include<iostream>
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
int main()
{
    int a, r, n, t;
    cout<<"Nhap n: ";cin>>n;
    cout<<"Nhap t: "; cin>>t;
    for(int i =1 ; i<t; i++){
        a = i+1;
        r = nhanBP(a, n-1, n);
        if(r != 1){
            cout<<"Voi a="<<a<<" n la Hop so";
            cout<<n<<" la hop so !";

        }
        else{
            cout<<"Voi a="<<a<<" n la Nguyen to\n";
        }
    }
    if(r == 1 ){
        cout<<n<<" co the la so nguyen to";
    }

}
