#include <vector>
#include <iostream>
using namespace std;


void dfs(vector<vector<int>> &g,int i,int j, int oldVal,int newVal){
	int n = g.size();
	int m = g[0].size();
	
	if(i<0 || j<0) return;
	if(i>=n || j>=m) return;
	if(g[i][j] != oldVal)
	   return;
	   
	g[i][j] = newVal;
	   
	dfs(g,i+1,j,oldVal,newVal);
}

vector<vector<int>> changeMatrixGraphValue(vector<vector<int>> g,int i,int j, int from, int to){
	dfs(g,i,j,from,to);
}



// this function cointing component
int numIsland(vector<vector<int>> &grid){
	int ans = 0;
	for(int i=0;i<grid.size();i++){
		for(int j=0;i<grid[0].size();j++){
			if(grid[i][j] == 0) continue;
		    dfs(grid,i,j,grid[i][j],0);
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	
}