#include<bits/stdc++.h>
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void solve(){

    int n;  cin >> n;
    map<int, int> mp;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(!mp.count(x))  cnt += (n - i) * (i+1);
        else              cnt += (n - i) * (i - mp[x]);
        mp[x] = i;
    }

    cout << cnt << "\n";
}

signed main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){solve();}
    return 0;
}