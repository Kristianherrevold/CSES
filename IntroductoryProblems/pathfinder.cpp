#include <bits/stdc++.h>
using namespace std;

int n = 9;  
bool grid[9][9];
int x,y;
int possible = 0;
string s;
int step = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
char labels[] = {'D','U','L','R'};

void pathfinder(int step, int x, int y,const string& s) {

	if(step == 48 && (x == 7 && y == 1)) {
		possible++;
		return;
	}
	if(x==7 && y==1) {
		return;
	}
    if(step == 48) return;

	if((!grid[x-1][y] && !grid[x+1][y]) && (grid[x][y-1] && grid[x][y+1])) {
		return;
	}
	if((grid[x-1][y] && grid[x+1][y]) && (!grid[x][y-1] && !grid[x][y+1])) {
		return;
	}
    grid[x][y] = true;

	for(int i = 0; i < 4; i++) {
        if(s[step] != labels[i] && s[step]!='?') continue;
		if( grid[x + dx[i]][y + dy[i]] == 0) {
		        pathfinder(step+1,x + dx[i], y + dy[i],s);
		}
	}
	
	grid[x][y] = false;
}

int main() {
	x = 1, y = 1;
	for(int i = 0; i < 9; i++) {
		grid[i][0] = true;
		grid[i][8] = true;
		grid[0][i] = true;
		grid[8][i] = true;
	}
    string s; cin>>s;
	pathfinder(0,x,y,s);
    cout << possible << "\n";
	return 0;
}