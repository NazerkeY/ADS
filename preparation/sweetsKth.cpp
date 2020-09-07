# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
 
const int N = (int)3e5 + 5;
const int inf = (int)1e9 + 7;
 
int n;
 
int sz;
long long totalSum;
long long a[N];
 
int heapify_up(int v) {
	while (v > 1 && a[v] < a[v / 2]) {
		swap(a[v], a[v/2]);
		v /= 2;
	}
	return v;
}
 
void heapify_down(int v) {
	while (v <= sz) {
		int l = 2 * v; // left son
		int r = 2 * v + 1; // right son
		int s = v; // min among a[v],a[l],a[r]
 
		/* let's find min */
		if (l <= sz && a[l] < a[s])
			s = l;
		if (r <= sz && a[r] < a[s])
			s = r;
		// if v is min, then everything is ok
		if (s == v)
			return;
		// go down to vertex s
		swap(a[v], a[s]);
		v = s;
	}
}
 
void add(long long x) {
	// add to the end
	sz++;
	a[sz] = x;
	// propogate (heapify) upwards
	heapify_up(sz);
}
 
long long top() {
	// min element is on top
	return a[1];
}
 
void remove_top() { // a.k.a. pop()
	// swap min with last element
	swap(a[1], a[sz]);
	// delete last element (delete min)
	sz--;
	// propogate top element downwards
	heapify_down(1);
}
 
int q, k;
 
int main(){
  cin >> q >> k;
  while(q--){
    string s;
    cin >> s;
    if(s == "insert"){
      int x;
      cin >> x;
      totalSum += x;
      add(x);
      if(sz > k){
        totalSum -= top();
        remove_top();
      }
    } else{
      cout << totalSum << "\n";
    }
  }
  return 0;
}