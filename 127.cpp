#include <bits/stdc++.h>

using namespace std;

bool same(pair < char, char> a, pair<char, char> b){
	return a.first == b.first || a.second == b.second;
}

void print(vector <stack<pair <char, char>>> cards){
	int n = cards.size();
	if(n != 1)
		printf("%d piles remaining: ",n);
	else{
		printf("%d pile remaining: ",n);
	}
	
	for(int i = 0; i < cards.size(); i++){
		int a = cards[i].size();
		if(i == cards.size()-1)
			printf("%d", a);
		else
			printf("%d ", a);
	}
	printf("\n");
}


void process(vector <stack<pair <char, char>>> cards){

	for(int i = 0; i < cards.size(); i++){
		if(i >= 3 && same(cards[i-3].top(), cards[i].top())){
			cards[i-3].push(cards[i].top());
			cards[i].pop();
			if(cards[i].size() == 0){
				cards.erase(cards.begin()+i);
			}	
			i -= 4;
		}
		else if(i > 0 && same(cards[i-1].top(), cards[i].top())){
			cards[i-1].push(cards[i].top());
			cards[i].pop();
			if(cards[i].size() == 0){
				cards.erase(cards.begin()+i);
			}
			i -= 2;
		}
	}
	
	

	print(cards);
}


int main(){
	

	
	string cards;
	
	
	int counter = 0;
	
	vector <stack<pair <char, char>>> decks;
	while(cin >> cards){
		if(cards == "#")
			break;
		counter++;
		stack <pair< char, char>> temp;
		temp.push(make_pair(cards[0], cards[1]));
		decks.push_back(temp);
		
		
		
		if(counter == 52){
			process(decks);
			counter = 0;
			decks.clear();
		}
		
	}
	
}
