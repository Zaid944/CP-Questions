#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define endl "\n"
#define int long long
// #define int unsigned long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set_p tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define OJ \
  freopen("inputcp.txt", "r", stdin); \
  freopen("output.txt", "w", stdout);
bool isPerfect(int n){double x = (double)(sqrt(n));int y = (sqrt(n));return (x - y) == 0;}
int Pow(int a, int b){int d = 1;for(int i = 1; i <= b; i++)d = (((d % mod) * (a % mod)) % mod)%mod;return d;}
string getString(char x){string s(1, x);return s;}
int ceil_(int x, int y){return x / y + (x % y != 0);}
int getLargestFactor(int n, int x){int p = 1;for(int i = 2; i <= sqrt(n); i++){if(n % i == 0 and n / i <= x){p = i; break;}}return n / p;}
vector<pair<int,int>>MergeKar(vector<pair<int,int>>&v){vector<pair<int,int>>bhej;for(int i = 0; i < v.size(); i++){if(bhej.size() == 0){bhej.push_back(v[i]);}
else{if(bhej[bhej.size() - 1].second < v[i].first){bhej.push_back(v[i]);}else{bhej[bhej.size() - 1].second = v[i].second;}}}return bhej;}
int arr[100000] = {1};
map<int,int>primes;
void sieve(){for(int p = 2; p*p < 100000; p++){if(arr[p] == 1){cout << p << endl;for(int i = p * p; i < 100000; i += p)arr[i] = 0;}} for(int i = 2; i < 100000; i++){if(arr[i] == 1)primes[i]++;}}
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}
size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
int NoOfFactor(int g){int ans = 0;for(int i = 1; i*i <= (g); i++){if(g % i == 0){ans++;if(i != g / i)ans++;}}return ans;}
int power(int x,  int y)
{int res = 1;x = x % mod;if (x == 0) return 0;while (y > 0){if (y & 1) res = (res * x) % mod;y = y >> 1;x = (x * x) % mod;}return res % mod;}
bool isPrime(int n){for(int i = 2; i <= sqrt(n); i++)if(n % i == 0)return false;return true;}
//.. problem A brute force na chle toh
//.. problem A mei pattern bnane ka bhi soch
//.. problem B mei pehle ache se brute force sochle 
//.. fir kuch aur soch
//.. agr implementation mushkil krdi hai aur wa aa
//.. rha hai toh easy implementation krrr
// ---------------------------------------------------------------------------------------------------------------------------------

bool cmp(pair<int,int>x, pair<int,int>y){
  return x.first > y.first;
}
// w s e n
vector<vector<int>>dir = {{0,-1}, {1,0}, {0,1}, {-1,0}};
int dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int sr, int sc){
  int n = grid.size(), m = grid[0].size();
  vis[sr][sc] = true;
  int s = 0;
  for(int d = 0; d < dir.size(); d++){
    int r = sr + dir[d][0];
    int c = sc + dir[d][1];
    if(r >= 0 and c >= 0 and r < n and c < m and !vis[r][c]){
      int z = (((grid[sr][sc]) >> d)&1);
      int y = (((grid[r][c]) >> ((d+2)%4))&1);
      if(z == 0 and y == 0){
        s += dfs(grid, vis, r, c);
      }
    }
  }
  return s + 1;
}
void Solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>>grid(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
    cin >> grid[i][j];
  }
  vector<vector<bool>>vis(n, vector<bool>(m, false));
  vector<int>ans;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!vis[i][j]){
        int s = dfs(grid, vis, i, j);
        ans.push_back(s);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << endl;
}


int32_t main(){
  OJ;
  // sieve();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t =1;
  // cin >> t ;
  while(t--){
    Solve();
  }
}