#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair <int, int> pi;
typedef vector<pi> vpi;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

void print(vvc board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
	int r,c;
    int no = 0;
    while(true){
        ++no;

        string rc;
        getline(cin, rc);
        if(rc.length() > 3){

            stringstream in(rc);
            in >> r >> c;
            if(0 == c && r == 0)
                break;
            if(no != 1)
                printf("\n");

            vvc board;

            vpi coords = {make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1), make_pair(1, 1), make_pair(1, 0), make_pair(1, -1), make_pair(0, -1)};


            for(int i = 0; i < r; i++){
                vc row;
                string str;
                getline(cin, str);
                for(int j = 0; j < str.length(); j++){
                    if(str[j] == '*' || str[j] == '.')
                        row.push_back(str[j]);
                }
                board.push_back(row);
            }


            for(int i = 0;i < r; i++){
                for(int j = 0; j < c; j++){
                    if(board[i][j] == '.'){
                        int count = 0;
                        for(int a = 0; a < coords.size(); a++){
                            if(i + coords[a].first >= 0 && i + coords[a].first <= r-1 && j + coords[a].second >= 0 && j + coords[a].second <= c-1){
                                if(board[i+coords[a].first][j+coords[a].second] == '*')
                                    count++;
                            }
                        }
                        board[i][j] = char(count+48);
                    }
                }
            }
            printf("Field #%d:\n", no);
            print(board);
        }
    }





	return 0;
}
