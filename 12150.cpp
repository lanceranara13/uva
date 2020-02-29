#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpi;

bool isValid(vpi grid, const int& n){
	for(int i = 0; i < grid.size(); i++){
		if(grid[i].second < 0 && abs(grid[i].second) > i+1)
			return false;
		if(grid[i].second > 0 && abs(grid[i].second) > n-i+1)
			return false;
		if(grid[i].second != 0 && grid[i+grid[i].second].second == 0)
			return false;
	}
	return true;
}

bool eval(vpi& grid, int n){
	vpi copy_grid(n, make_pair(0,0));
	bool check = true;

	for(int i = 0; i < grid.size(); i++){
		if(copy_grid[i+grid[i].second].first == copy_grid[i+grid[i].second].second)
			copy_grid[i+grid[i].second] = grid[i];
		else{
			check = false;
			break;
		}
	}
	if(!check){
		printf("-1");
		return false;
	}

	grid = copy_grid;
	return true;
}

void print(vpi grid){
	for(int i = 0; i < grid.size(); i++){
		if(i != grid.size()-1)
			printf("%d ", grid[i].first);
		else
			printf("%d", grid[i].first);
	}
}

int main(){
	int n;

	while(scanf("%d",&n)){
		if(n == 0)
			break;
		vpi grid;

		for(int i = 0; i < n; i++){
			int no, pos;
			scanf("%d%d", &no, &pos);
			grid.push_back(make_pair(no,pos));
		}

		if(isValid(grid, n)){
			bool a = eval(grid, n);
			if(a)
				print(grid);
		}
		else{
			printf("-1");
		}
		printf("\n");


	}


	return 0;
}
