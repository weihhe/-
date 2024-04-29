#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<stack>

using namespace std;
const int N = 20;

int bo[N][N],n,k;
int hs[N][N];
stack<int> ans;
string ans_2;

void dfs(int x,int y)
{
	if(x <1 || y < 1 || x > N || y > N)	{
		ans.pop();
		return;
	}

	hs[x][y]=1;

	if(x == N && y == N) {
		bool fl = true;
		for(int i = 1; i<=N; i++) {
			for(int j = 1; j<=N; j++) {
				if(hs[i][j] != 1) {
					fl = false;
				}
			}
		}
		if(fl) {
			if(!ans.empty()) {
				ans_2 += (ans.top()+'0');
				ans.pop();
			}
		}
		return;
	}

	if(bo[x][y] ==k) {
		if(bo[x+1][y] == 0) {//r
			ans.push(2);
			dfs(x+1,y);
		}
		if(bo[x][y-1] == 0) {//u
			ans.push(0);
			dfs(x,y-1);
		}
		if(bo[x-1][y] == 0) {//l
			ans.push(6);
			dfs(x-1,y);
		}
		if(bo[x+1][y] == 0) {//d
			ans.push(4);
			dfs(x+1,y);
		}
		if(bo[x+1][y-1] == 0 && (hs[x+1][y] != 1 && hs[x][y-1] != 1)) {//ru
			ans.push(1);
			dfs(x+1,y-1);
		}
		if(bo[x-1][y-1] == 0&& (hs[x-1][y] != 1 && hs[x][y-1] != 1)) {//lu
			ans.push(7);
			dfs(x-1,y-1);
		}
		if(bo[x+1][y+1] == 0&& (hs[x+1][y] != 1 && hs[x][y+1] != 1)) {//rd
			ans.push(3);
			dfs(x+1,y+1);
		}
		if(bo[x-1][y+1] == 0&&(hs[x-1][y] != 1 && hs[x][y+1] != 1)) {//ld
			ans.push(5);
			dfs(x-1,y+1);
		}
	}
	if(bo[x][y] < k) {
		if(bo[x+1][y] == bo[x+1][y]+1) {//r
			ans.push(2);
			dfs(x+1,y);
		}
		if(bo[x][y-1] == bo[x][y-1]+1) {//u
			ans.push(0);
			dfs(x,y-1);
		}
		if(bo[x-1][y] == bo[x-1][y]+1) {//l
			ans.push(6);
			dfs(x-1,y);
		}
		if(bo[x+1][y] == bo[x+1][y]+1) {//d
			ans.push(4);
			dfs(x+1,y);
		}
		if(bo[x+1][y-1] == bo[x+1][y-1]+1&& (hs[x+1][y] != 1 && hs[x][y-1] != 1)) {//ru
			ans.push(1);
			dfs(x+1,y-1);
		}
		if(bo[x-1][y-1] == bo[x-1][y-1]+1&& (hs[x-1][y] != 1 && hs[x][y-1] != 1)) {//lu
			ans.push(7);
			dfs(x-1,y-1);
		}
		if(bo[x+1][y+1] == bo[x+1][y+1]+1&& (hs[x+1][y] != 1 && hs[x][y+1] != 1)) {//rd
			ans.push(3);
			dfs(x+1,y+1);
		}
		if(bo[x-1][y+1] == bo[x-1][y+1]+1&&(hs[x-1][y] != 1 && hs[x][y+1] != 1)) {//ld
			ans.push(5);
			dfs(x-1,y+1);
		}
	}

	hs[x][y]=0;
	ans.pop();

}



int main()
{
	cin>>n>>k;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=n; j++) {
			cin>>bo[i][j];
		}
	}
	dfs(1,1);
	hs[1][1] = 1;
	reverse(ans_2.begin(),ans_2.end());
	cout<<ans_2;

	return 0;

}
