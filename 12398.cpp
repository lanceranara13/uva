#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

void print(vvi board){
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++){
			if(j != board[i].size()-1)
				printf("%d ", board[i][j]);
			else{
				printf("%d", board[i][j]);
			}
		}
		printf("\n");
	}
}

pi getId(char ch){
	switch(ch){
		case 'a':
			return make_pair(0,0);
		case 'b':
			return make_pair(0,1);
		case 'c':
			return make_pair(0,2);
		case 'd':
			return make_pair(1,0);
		case 'e':
			return make_pair(1,1);
		case 'f':
			return make_pair(1,2);
		case 'g':
			return make_pair(2,0);
		case 'h':
			return make_pair(2,1);
		case 'i':
			return make_pair(2,2);
	}
}

void algorithm(const string& str, vvi& board){
	vpi coord = {make_pair(0,0),make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
	for(int i = 0; i < str.length(); i++){
		pi id = getId(str[i]);

		for(int j = 0; j < coord.size(); j++){
			if(id.first + coord[j].first >= 0 && id.first + coord[j].first < 3 && id.second + coord[j].second >= 0 && id.second + coord[j].second < 3){
				board[id.first+coord[j].first][id.second+coord[j].second] = (board[id.first+coord[j].first][id.second+coord[j].second]+1) %10;
			}
		}
	}
}


int main(){
	string in;
	int case_no = 1;
	while(getline(cin, in)){
		printf("Case #%d:\n", case_no);
		vi row(3, 0);
		vvi board(3, row);
		if(in == "")
			print(board);
		else{
			algorithm(in, board);
			print(board);
		}
		case_no++;
	}


	return 0;
}
