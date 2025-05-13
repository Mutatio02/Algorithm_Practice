    #include <bits/stdc++.h>
    using namespace std;
    // 25.05.13 문서 검색 (문자열)
    string document;
    string query;

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        getline(cin,document);
        getline(cin,query);

        int cnt = 0;
        int pos = 0;
        while(1) {
            pos = document.find(query,pos); // query 찾기
            if(pos==string::npos) break;
            cnt++;
            pos += query.length();
        }

        cout << cnt;
        
        return 0;
    }
