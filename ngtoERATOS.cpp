#include<iostream>
using namespace std;
int main()
{
    long long num;
    cin>>num;
    bool checkPrimes[num+1];
    for(long long i=2 ;i<num; i++){
        checkPrimes[i]=true;
    }
    for(long long i=2;i<num ; i++){
        if(checkPrimes[i]==true){
            for(long long j=2 * i;j<num;j+=i){
                checkPrimes[j]=false;
            }
        }
    }
    for (long long i = 2; i <= num; i++) {
        if (checkPrimes[i] == true) {
      cout<<i<<"    ";
    }
  }

}
