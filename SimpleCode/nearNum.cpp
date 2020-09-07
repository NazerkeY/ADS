#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, num; int count = 0, index, min;
 
    cin >> n;
    int a[101];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> num;
    index = abs(a[0] - num);
    min = 0;
    for (int i = 1; i < n; i++){
        if (abs(a[i] - num)<index){ index = abs(a[i] - num); min = i; }
 
 
    }
    cout << a[min];
    return 0;
}