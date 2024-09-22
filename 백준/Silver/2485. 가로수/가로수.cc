#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a,int b) {
    while(b!=0) {
        int temp = b;
        b= a%b;
        a= temp;
    }
    return a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N,0);
    vector<int> d;

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    for(int i=0; i<N-1; i++) {
        d.push_back(v[i+1]-v[i]); // 간격
    }

    int g = d[0];
    for(int i=0; i<d.size(); i++) {
        g = gcd(g,d[i]); // 간격들 사이에 최대공약수
    }
    
    int dist = v[N-1] - v[0];
    int answer = dist / g - (N-1);

    cout << answer;

    return 0;
}
