#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int main(){
	string str;
	
	while(getline(cin, str)){
		list <char> l;
		
		bool h = false;
		string temp = "";
		for(int i = 0; i < str.length(); i++){
			//cout << temp << endl;
			if(str[i] == '['){
				if(h && temp.size() > 0){
					for(int j = temp.length()-1; j >= 0; j--){
					l.push_front(temp[j]);
					}
					temp = "";
				}
				
				h = true;
			}
			else if(str[i] == ']'){
				h = false;
				for(int j = temp.length()-1; j >= 0; j--){
					l.push_front(temp[j]);
				}
				temp = "";
			}
			
			
			if(h && str[i] != '[' && str[i] != ']'){
				temp+= str[i];
			}else if(str[i] != '[' && str[i] != ']') {
				l.push_back(str[i]);
			}
			
		}
		
		if(temp != ""){
			for(int j = temp.length()-1; j >= 0; j--){
				l.push_front(temp[j]);
			}
		}
		for(auto a = l.begin(); a!= l.end(); a++){
			cout << *a;
		}
		cout << endl;
		
		
	}


	return 0;
}
