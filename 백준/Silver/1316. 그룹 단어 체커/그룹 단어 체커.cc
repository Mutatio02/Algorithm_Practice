#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int count = 0;

    while(N--){
        string str;
		cin >> str;
		bool flag = true;
		
		for(int i=0; i<str.length(); i++){
			for(int j=0; j<i; j++){
				if(str[i] != str[i-1] && str[i] == str[j]){
					flag = false;
					break;			
				}				
			}
		}
		if(flag) count++;
	}
	
	cout << count;

    
        
    return 0;
}
