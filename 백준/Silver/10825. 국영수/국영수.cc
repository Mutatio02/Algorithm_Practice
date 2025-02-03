#include <bits/stdc++.h>
using namespace std;
// 25.2.2 국영수(정렬 II) 
int N;
bool compare(const tuple<string,int,int,int>& a, const tuple<string,int,int,int>& b) {
    if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // 국어 점수 감소
    if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b); // 국어 점수가 같으면 영어 점수 증가
    if(get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b); // 국어 영어가 같으면 수학 점수 감소
    return get<0>(a) < get<0>(b); // 사전순 증가
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<tuple<string,int,int,int>> student; // 이름 국 영 수

    for(int i=0; i<N; i++) {
        string name;
        int x,y,z;
        cin >> name >> x >> y >> z;
        student.push_back(make_tuple(name,x,y,z));
    }
    
    sort(student.begin(),student.end(),compare);

    for(const auto& s : student) {
        string str = get<0>(s);

        cout << str << "\n";
    }
    
    return 0;
}
