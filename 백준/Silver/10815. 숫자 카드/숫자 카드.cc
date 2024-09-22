#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> input(N,0);
    for(int i=0; i<N; i++) {
        cin >> input[i];
    }
    sort(input.begin(),input.end()); // 이진 탐색을 위해 정렬이 필요

    int M;
    cin >> M;
    int number = 0;
    for(int i=0; i<M; i++) {
        cin >> number;
        if(binary_search(input.begin(),input.end(),number)) {
            cout << "1" << " ";
        }
        else {
            cout << "0" << " ";
        }
    }

    return 0;
}