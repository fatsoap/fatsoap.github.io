/*
 *
 * Fatsoap
 * algorithm note
 * 2020/11/6 update
 *
 */



/* fast io */
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

/* python big integer */
s = input()
a = int(s.split())
b = int(s.split())
//do something


/* prime */
//160ms , 2*10e7 time complexity
int N = 10000000; //10e7 prime
static bool notPrime[10000000] = { 1, 1 };	
int SQRT = sqrt(N);
for (int i = 2; i <= SQRT; i++)
	if (!notPrime[i])
		for (int j = i << 1; j < N; j += i)
			notPrime[j] = true;
			
/* Number theory*/
Goldbach’s Conjecture : 大於等於四的偶數可以由兩個質數相加而成


/* Dijkstra shortest path */
------------------------->root initialize, 到不了的點設無限大or超大
for(int j=0; j<n;j++) dis[j] = length[root][j];
dis[root] = 0, used[root] = 1;
------------------------->
int point = root, min_len = 0;
------------------------->n-1個邊
for(int i=0; i<n-1; i++){
	int min_l = 99999, min_p = root;
	for(int j=0; j<n; j++){
		------------------------->(a)累加->從root到點的最小距離, 更新dis
		if(length[point][j] + dis[point] < dis[j] && used[j]!=1){
			dis[j] = length[point][j] + dis[point];
		}
		------------------------->(b)非累加->從used的點連到的最小距離, 更新dis
		if(length[point][j] < dis[j] && used[j]!=1){
			dis[j] = length[point][j];
		}
		------------------------->找出dis中最小的且沒用過的,紀錄位置
		if(dis[j]<min_l && used[j]!=1){
			min_l = dis[j];
			min_p = j;
		}
	}
	------------------------->標註已用過,更新檢查點
	point = min_p;
	used[min_p] = 1;
	------------------------->©有表明結束點
	if(min_p==stop_point) break;
}
------------------------->(a)dis值為root走最短路徑到某點耗的值
------------------------->(b)dis總和為最短路徑cost
for(int i=0; i<n ;i++)total += dis[i];
------------------------->

/* binay search */
int l = 0 , r = n-1 
while(l<r){
	//situation 1 (左邊不行，往右邊收斂)
	mid = (l+r)/2
	if l = mid+1
	else r = mid
	
	//situation 2 (右邊不行，往左邊收斂) 
	mid = (l+r)/2+1
	if l = mid
	else r = mid-1
	
}


/* segment tree */
void build(int l, int r, int now){
	if(l==r){
		tree[now] = array[l];
		return;
	}
	int mid = (l+r)/2;
	build(l, mid ,now2);
	build(mid+1, r, now2+1);
	tree[now] = tree[now2] XXX tree[now2+1];
}

void add(int l, int r, int now){
	if(l==r){
		tree[now] = XXX;
		return;
	}
	int mid = (l+r)/2;
	if(index<=mid)add(l, mid, now2);
	else add(mid+1, r, now2+1);
	tree[now] = tree[now2] XXX tree[now2+1];
}

int search(int l, int r, int now){
if(L<=l && r<=R){
return tree[now];
}
int mid = (l+r)/2;
if(R<=mid)return search(l, mid, now2);
else if(mid+1<=L)return search(mid+1, r, now2+1);
else return search(l, mid, now2) XXX search(mid+1, r, now2+1);
}


/* descret(離散化) */
const int N = XXX;
int n, m;
int descret[N];

struct node{
	int val, new_index;
}tree[N];

int main(){
	for(int i=0; i<n; i++){
		cin>>tree[i].val;
		descret[i] = tree.val;
	}	
	sort(descret, descret+n);
	m = unique(descret, descret+n) - descret;
	for(int i=0; i<n; i++){
		tree[i].new_index = lower_bound(descret, descret+n, tree[i].val) - descret;
	}
}

/* LCA */
/* root = 0 */
const int N = 2e5+5, gN = log2(N);
int t_in[N], t_out[N], depth[N];
int t = 0, n;
bool used[N];
vector<int> kid[N];
vector<vector<int> > anc(N, vector<int>(gN,0) );

bool isAnc(int x, int y){
	return t_in[x] <= t_in[y] && t_out[y] <= t_out[x];
}

int LCA(int x, int y){
	if(isAnc(x, y))return x;
	if(isAnc(y, x))return y;
	
	for(int i=log2(n); i>-1; i--){
		if(!isAnc(anc[x][i], y))
			x = anc[x][i];
	}
	return anc[x][0];
}

void build_dfs(int now , int dad , int deep){
	if(used[now]) return;
	used[now] = true;
	t_in[now] = t++;
	depth[now] = deep;
		
	for(int i=0; i<log2(n); i++){
		anc[now][i] = dad;
		dad = anc[dad][i];
		if(anc[now][i]==0) break;
	}
	for(int i=0; i<kid[now].size(); i++){
		dfs(kid[now][i], now ,deep+1);
	}
	
	t_out[now] = t++;
}

int main()
{
	memset(); used, t_in, t_out, depth
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		kid[a].push_back(b);
		kid[b].push_back(a);
	}
	build_dfs(0,0,0);	
	lca = LCA(x,y);
}

/* Two sorted array find median */
/* time complexity O( log(n+m) ) */
shorter array is flag1 , longer array is flag2
add two flags , and divide two array into four pieces

left piece of two array , total element amount equal to right total amount

//odd
flag1 + flag2 = total size / 2 + 1

//even
flag1 + flag2 = total size / 2

-------------flag1   -----------------    : array1
----------------flag2    --------------   : array2
if ( arr1[ flag1 ] <= arr2[ flag2 + 1 ]  && arr2[ flag2 ] <= arr1[ flag1 + 1 ]  ){
	//size = odd
	median =  max( arr1[ flag1 ] , arr2[ flag2 ] )
	//size = even
	median =  max( arr1[ flag1 ] , arr2[ flag2 ] ) + max( arr1[ flag1 +1 ] , arr2[ flag2 + 1 ] );
} else {
	check flag1 should move right or left
}
	
------------------------------------------------------------------------------

const int INF = 2147483647;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
	vector<int> tt = a;
	if(a.size()>b.size()){
		a = b, b = tt;
	}
	a.insert(a.begin(),-1);
	a.push_back(INF);
	b.insert(b.begin(),-1);
	b.push_back(INF);
	
	float search_times = log(a.size()) / log(2)  +  1;
	vector<float>ans(4,0);
	int start = 0, end = a.size()-1, px, py, all_size = a.size()+b.size()-4;
	for(int i=0; i<search_times; i++){
		px = (start+end)/2;
		py = (all_size+1)/2 - px;
		if(a[px]<=b[py+1] && b[py]<=a[px+1]){
			break;
		}else if(a[px]>b[py+1]){
			end = px;
		}else{
			start = px;
		} 
	}
	ans[0]=a[px], ans[1]=a[px+1], ans[2]=b[py], ans[3]=b[py+1];
	sort(ans.begin(), ans.end());
	if(all_size%2 == 0){
		return (ans[1]+ans[2])/2;
	}else{
		return ans[1];
	}
}
	
/* Palindrome Number */
bool function(int x) {
	if(x==0)return true;
	if(x<0 || x%10==0)return false;        
	int tmp = 0;
	while(x>tmp){
		tmp = tmp*10 + x%10;
		x /= 10;
	}
	return x == tmp || x == tmp / 10;
}

/* 3Sum */
vector<{num1, num2, num3} > 3Sum ( int target, vector<int> v ) {
	if(size<=2) return empty;
	sort ( v.begin() , v.end() );
	for(int i=0; i<size; i++){
		if(i>0 && v[i]==v[i-1])continue; //repeat first num
		num1 = v[i];
		num2 , num3 =  2Sum(target-num1, v) 
	}
}

/* 2Sum : Finding pairs that sum is equal to given target. */
vector<pair<int, int> > 2Sum ( int target, vector<int> v ) {
     vector<pair<int, int> > ans;    //return stuff;
     sort ( v.begin() , v.end() );    //sort array first
     int l = 0 , r = v.size()-1;    //two pointer : begin & end of array
     while(l<r){
         int a = v[l] , b = v[r];
         if ( a + b > target) {  //sum bigger than target
             r--;    //right pointer move left
         } else if ( a + b < target) {     //su smaller than target
             l++;    //left pointer move right;
         } else {    //sum equal to target
             ans.push_back( {a,b} );
             while( l < r  &&  a == v[l] ) l++;    //void repeat pairs
             while( l < r  &&  b == v[r] ) r--;    //void repeat pairs
         }
     }
     return ans;
}

/*  Regular Expression Matching */

/* 
 *
 * only lower case
 * input s, p
 * p have regular expression
 * 
 */
 
//Preprocess:
dp[0][0] = 1;
for i = 1 ~ len-1
    if p[i]=='*' or 'A'<=p[i]<='Z'
        dp[0][i] = dp[0][i-1]
//DP
for i = 1 ~ len-1
    for j = 1 ~ len-1    
        if  s[i] == p[j] or p[j] == '.'  //same char or any char
                 dp[i][j] = dp[i-1][j-1]    //top-left ( fill char ) 
        else if p[j]=='*' or s[i] == p[j] + 32  // '*' or same capital
                dp[i][j] = dp[i-1][j] or dp[i][j-1]    //left ( empty str )  or top ( fill char )       
        else if 'A'<=p[j]<='Z'  //different capital 
                dp[i][j] = dp[i][j-1]    //left ( empty str )  
        else 
            dp[i][j] = 0    //false
if(dp[s.length()-1][p.length()-1] == true ) cout<<"YES";
else "NO";



bool isMatch(string s, string pp) {
	string p;
	for(int i=0; i<pp.length(); i++){
		if(i==pp.length()-1){
			p += pp[i];
			continue;
		}    
		if(pp[i+1]=='*'){                
			if(pp[i] == '.') p += "*";                    
			else   p.push_back( (char)((int)(pp[i])-32) ); //change to capital letter          
			i++;
		}else{
			p += pp[i];
		}        
	}
	s = "-" + s, p = '-' + p;
	vector<vector<int> > dp(s.length(), vector<int>(p.length(), 0) );
	dp[0][0] = 1;
	for(int i=1; i<p.length(); i++){
		if(p[i]=='*' || ('A'<=p[i] && p[i]<='Z')) dp[0][i] = dp[0][i-1];
	}
	for(int i=1; i<s.length(); i++){
		for(int j=1; j<p.length(); j++){
			if(s[i]==p[j] || p[j]=='.'){
				dp[i][j] = dp[i-1][j-1];
			}else if(s[i]==p[j]+32){
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}else if('A'<=p[j] && p[j]<='Z'){
				dp[i][j] = dp[i][j-1];
			}else if(p[j]=='*'){
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}else {
				dp[i][j] = 0;
			}
		}
	}
	return dp[s.length()-1][p.length()-1];
}

	
	