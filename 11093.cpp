#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int algorithm(const vi &p,const vi &q){
	int n = p.size();
	int ans = 0;
	if(accumulate(p.begin(), p.end(), 0) < accumulate(q.begin(), q.end(), 0))
		return 0;
	for(int i = 0; i < n; i++){
		bool check = true;
		int totalp = 0, totalq = 0;
		for(int j = i; j < n; j++){
			totalp += p[j];
			totalq += q[j];
			if(totalp < totalq){
				check = false;
				break;
			}
		}
		if(check)
			return i+1;
	}
}


int main(){
	int T;
	scanf("%d", &T);
	for(int c = 0; c < T; c++){
		int N, ans = 0;
		scanf("%d", &N);
		
		vi p,q;
		
		int catcher;
		for(int i = 0; i < N; i++){
			scanf("%d", &catcher);
			p.push_back(catcher);
		}
		
		for(int i = 0; i < N; i++){
			scanf("%d", &catcher);
			q.push_back(catcher);
		}
		
		ans = algorithm(p,q);
		
		printf("Case %d: ", c+1);
		
		if(ans == 0)
			printf("Not possible\n");
		else
			printf("Possible from station %d\n", ans);
	}
		


	return 0;
}
