//Nghich Đảo
#include <iostream>
using namespace std;
int gcd_extend(int a, int b, int *x, int *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  int x1, y1;
  int gcd = gcd_extend(b, a%b,  &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * y1;
  return gcd;
}
int modulo_inverse_euclidean(int n, int m) {
  int x, y;
  if (gcd_extend(n, m, &x, &y) != 1) return -1; // not exist
  return (x % m  + m) % m; // vì x có thể âm
}

int main()
{
    int p = 489573857;
    int a = 45682375 ;
    cout<<modulo_inverse_euclidean(a, p);
}
