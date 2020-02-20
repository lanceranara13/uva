/*-------------------------------------------------------------------------*/
/* Filename : 201810383_10611.cpp										   */
/* Description :                                                           */
/* Author : Lance Steven C. Ranara                                         */
/* Course and Year : BSCS - 2                                              */
/* Last Modified : Feb 20, 2020                                            */
/* Honor Code : This is my own code. I have worked hard in completing      */
/* this work and I have not copied from any unauthorized                   */
/* resource. I am also well aware of the policies                          */
/* stipulated in the college student handbook regarding                    */
/* academic dishonesty.                                                    */
/*-------------------------------------------------------------------------*/


#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef set <int> si;

int binary_search(vi arr, int l, int r, int x) //Recursive Approach
{ 
    if(l > r){
		printf("%d %d" , arr[r] , arr[l]);
		return -1;
	}
		
	int m = l + (r-l)/2;
	
	if(arr[m] > x)
		return binary_search(arr, l, m-1, x);
	else if(arr[m] < x)
		return binary_search(arr, m+1, r, x);
	return m;
} 

int binarySearch(vi arr, int l, int r, int x) //Iterative Approach
{ 
    while (l <= r) { 
        int m = l + (r-l)/2; 
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 
  
	printf("%d %d" , arr[r] , arr[l]);
    return -1; 
} 




int main(){
	int N,Q,c;
	
	scanf("%d", &N);
	
	si chimps;
	
	for(int i = 0; i < N; i++){
		scanf("%d", &c);
		chimps.insert(c);
	}
	
	vi lady_chimps(chimps.begin(), chimps.end());
	N = lady_chimps.size();
	int minimun = lady_chimps[0], maximum = lady_chimps[N-1], last = -1;
	scanf("%d", &Q);
	
	while(Q--){
		scanf("%d",&c);
		int pos;
		if(c < minimun){
			printf("X %d", minimun);
		}
		else if(c > maximum){
			printf("%d X", maximum);
		}
		else if(minimun == maximum)
			printf("X X");
		else if(c == minimun){
			printf("X %d", lady_chimps[1]);
		}
		else if(c == maximum){
			printf("%d X", lady_chimps[N-2]);
		}
		else {
		    if(last != c)
			    pos = binarySearch(lady_chimps, 0, N-1, c);
			
			if(pos != -1)
				printf("%d %d", lady_chimps[pos-1], lady_chimps[pos+1]);
		}
		last = c;
		printf("\n");
	}

	return 0;
}
