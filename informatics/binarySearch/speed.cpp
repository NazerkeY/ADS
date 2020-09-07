//4 1 1 3
//5 1 2 4
#include <iostream>
using namespace std;
int main()
{
int n, x, y, i, j, l, r, m;
double speed;
cin >> n >> i >> j;
x=i<j?i:j;
y=i>j?i:j;
l=0;
r = (n-1)*y;
while (l != r) {
m = (l+r)/2;
j = m / x + m / y;
if (j < n-1) l = m + 1;
else r = m;
}
cout << r + x;
return 0;
}
