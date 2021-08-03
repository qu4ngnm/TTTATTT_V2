//Phep nhan trong Fp
#include<iostream>
using namespace std;
int ucln(long long a, long long b)
{
    if(b==0){
        return a;
    }
    return ucln(b, a%b);
}
int main()
{
    long long a=921891237645; long long b=827123984710;
    ucln(a,b);
}


