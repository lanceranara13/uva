#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi getNum(string str){
    
    vi final;
    
    for(int i = 0; i < str.length(); i++){
        if(isdigit(str[i]))
            final.push_back(int(str[i])-'0');
    }
    
    return final;
}

void print(vvi mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++)
            printf("%d", mat[i][j]);
        printf("\n");
    }
}

void increment(vvi &mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            mat[i][j] = (mat[i][j] + 1) % 10;
        }
    }
}

void decrement(vvi &mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            if(mat[i][j] - 1 == -1)
                mat[i][j] = 9;
            else
                mat[i][j] -= 1;
        }
    }
}

void transpose(vvi &mat){
    vvi copy_mat(mat.begin(), mat.end());
    
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            mat[i][j] = copy_mat[j][i];
        }
    }
}

int main(){
	int t;
    
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int n;
        
        scanf("%d", &n);
        vvi matrix;
        for(int j = 0; j <= n; j++){
            vi row;
            string str;
            getline(cin, str);
            if(str.length() != 1){
                row = getNum(str);
                matrix.push_back(row);
            }
        }
        
        
        int n_ope;
        
        scanf("%d", &n_ope);
        
        for(int j = 0; j <= n_ope; j++){
            string op;
            getline(cin, op);
            if(op.length() != 1){
                stringstream operation(op);
                
                operation >> op;
                
                if(op == "row"){
                    int x1,x2;
                    operation >> x1 >> x2;
                    vi temp;
                    temp = matrix[x2-1];
                    matrix[x2-1] = matrix[x1-1];
                    matrix[x1-1] = temp;
                    
                }
                else if(op == "col"){
                    int x1,x2;
                    operation >> x1 >> x2;
                    for(int k = 0; k < n; k++){
                        swap(matrix[k][x1-1], matrix[k][x2-1]);
                    }
                }
                else if(op == "inc"){
                    increment(matrix);
                }
                else if(op == "dec"){
                    decrement(matrix);
                }
                else if(op == "transpose"){
                    transpose(matrix);
                }
            }
        }
        
        printf("Case #%d\n", i+1);
        print(matrix);
        printf("\n");
    }

	return 0;
}