#include <bits/stdc++.h>
using namespace std;

// 25.03.10 트리 순회 (트리) 
int N;
vector<char> adj[30];

void preorder(char cur) { // 전위 순회
    if(cur == '.') return;
    cout << cur; // 노드
    preorder(adj[cur-'A'][0]); // 왼쪽
    preorder(adj[cur-'A'][1]); // 오른쪽
}

void inorder(char cur) { // 중위 순회
    if(cur == '.') return;
    inorder(adj[cur-'A'][0]); // 왼쪽
    cout << cur; // 노드
    inorder(adj[cur-'A'][1]); // 오른쪽
    
}

void postorder(char cur) { // 후위 순회
    if(cur == '.') return;
    postorder(adj[cur-'A'][0]); // 왼쪽
    postorder(adj[cur-'A'][1]); // 오른쪽
    cout << cur; // 노드
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        char mid,left,right;
        cin >> mid >> left >> right;
        adj[mid-'A'].push_back(left);
        adj[mid-'A'].push_back(right);
    }
    preorder('A'); // 전위 
    cout << "\n";
    inorder('A'); // 중위
    cout << "\n";
    postorder('A'); // 후위
    cout << "\n";
    
    return 0;
}
