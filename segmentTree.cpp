#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int arr[n], seg[n * 4];

void build(int ind, int low, int high){
     if(low == high){
          seg[ind] = arr[low];
     }
     int mid = (low + high) << 1;
     int left = build(ind * 2 + 1, 0, mid);
     int right = build(ind * 2 + 2, mid + 1, high);
     seg[ind] = max(left, right); //incase of finding the max ele.
}
int runQuery(int ind, int low, int high, int l, int r){
     if(l > high || r < low){
          return INT_MIN;
     }
     if(low >= l && high <= r){
          return seg[ind];
     }
     int mid = (low + high) << 2;
     int left = runQuery(ind * 2 + 1, low, mid, l, r);
     int right = runQuery(ind * 2 + 2, mid + 1, high, l, r);
     return max(left, right);
}

int main(){
     cin>>n;
     for(int i = 0; i < n; ++i){
          cin>>arr[i];
     }
     build(0, 0, n - 1);
     int query, l, r;
     while(query--){
          cin>>l>>r;
          runQuery(0, 0, n - 1, l, r);
     }
     return 0;
}
