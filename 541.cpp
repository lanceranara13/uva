#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair <int,int> pi;


int countCol(vvi matrix){
	int n = matrix.size();
	int odd = 0;
	for(int i = 0; i < n; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(matrix[j][i] == 1)
				count++;
		}
		if(count%2==1){
			odd++;
		}
	}
	return odd;
}

int countRow(vvi matrix){
	int n = matrix.size();
	int odd = 0;
	for(int i = 0; i < n; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 1)
			count++;
		}
		if(count%2==1)
			odd++;
	}
	return odd;
}

int findCol(vvi matrix){
	int n = matrix.size();
	for(int i = 0; i < n; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(matrix[j][i] == 1)
			count++;
		}
		if(count%2==1)
			return i;
	}
}

int findRow(vvi matrix){
	int n = matrix.size();
	for(int i = 0; i < n; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 1)
			count++;
		}
		if(count%2==1)
			return i;
	}
}


void algorithm(vvi matrix){
	int oddC = countCol(matrix), oddR = countRow(matrix);
	if(oddC > 1 || oddR > 1)
		printf("Corrupt");
	else if(oddC == 1 && oddR == 1){
		printf("Change bit (%d,%d)", findRow(matrix)+1, findCol(matrix)+1);
	}
	else if(oddC == 0 && oddR == 0)
		printf("OK");
	printf("\n");
}



int main(){
	int n;

	while(scanf("%d", &n)){
		if(n == 0)
			break;

		vvi matrix;
		int bit;

		for(int i = 0; i < n; i++){
			vi row;
			for(int j = 0; j < n; j++){
				scanf("%d", &bit);
				row.push_back(bit);
			}
			matrix.push_back(row);
		}
		algorithm(matrix);
	}

	return 0;
}
