#include <bits/stdc++.h>

using namespace std;

class mycomparison
{
  bool reverse;
public:

  bool operator() (const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b) const
  {
   if(a.first == b.first)
		return a.second.first > b.second.first;

	return a.first > b.first;
  }
};


int main(){
	priority_queue <pair<int, pair<int,int>>, vector <pair<int, pair<int,int>>>, mycomparison> timeline;
	// list.push(make_pair(1,3));
	string action;
	cin >> action;
	while(action!="#"){
		int x, y;
		cin >> x >> y;
		cin >> action;
		timeline.push(make_pair(y,make_pair(x,y)));	
	}

	
	int period;
	cin >> period;

	while(period--){
		cout << timeline.top().second.first << endl;
		timeline.push(make_pair(timeline.top().second.second + timeline.top().first, 
			make_pair(timeline.top().second.first, timeline.top().second.second) ));
		timeline.pop();

	}

	
}
