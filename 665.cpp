#include <bits/stdc++.h>
using namespace std;

typedef set <int> si;
typedef vector <int> vi;



void algorithm(si &numbers, const vi& l, const vi& r, const char& ch){	//sinear Time O(n)
	int n = r.size();
	
	if(ch == '='){
		for(int i = 0; i < n; i++){
		    auto lfind = numbers.find(l[i]), rfind = numbers.find(r[i]);
			
			if(lfind != numbers.end())
			    numbers.erase(lfind);
			if(rfind != numbers.end())
			    numbers.erase(rfind);
		}
	}
	
	/*
	else if(ch == '<'){
		for(int i = 0; i < n; i++){
		    auto lfind = numbers.find(l[i]);
			if(lfind != numbers.end())
			    numbers.erase(lfind);
		}
	}
	
	else if(ch == '>'){
		for(int i = 0; i < n; i++){
		    auto rfind = numbers.find(r[i]);
		    if(rfind != numbers.end())
			    numbers.erase(rfind);
		}
	}
	*/
}

int main(){
	int M, N, K;
	
	scanf("%d", &M);
	
	while(M--){
		scanf("%d%d", &N, &K);
		
		int n;
		vi counting_numbers(N);
		iota(counting_numbers.begin(), counting_numbers.end(), 1); 		//Populate Vector with 1 - N
		si numbers;
		
		numbers.insert(counting_numbers.begin(), counting_numbers.end());
		
		while(K--){
			vi l, r;
			scanf("%d", &n);
			
			int temp;
			for(int i = 0; i < n; i++){		//Left
				scanf("%d", &temp);
				l.push_back(temp);
			}
			
			for(int i = 0; i < n; i++){		//Right
				scanf("%d", &temp);
				r.push_back(temp);
			}
			
			char result;
			//scanf("%c",result);
			cin >> result;
			
			algorithm(numbers, l, r, result);
		}
		
		if(numbers.size() > 1)
			cout << 0;
		else
			cout << *numbers.begin();
		cout << endl;
		
		if(N != 0)
		    cout << endl;
		
	}	
	return 0;
}