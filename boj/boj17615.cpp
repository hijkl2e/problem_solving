#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int rcnt = count(S.begin(), S.end(), 'R');
	int bcnt = S.size() - rcnt;
	int p1{}, p2{};
	while (p1 < S.size() && S[p1] == S.front()) {
		++p1;
	}
	while (p2 < S.size() && S[S.size() - p2 - 1] == S.back()) {
		++p2;
	}
	int rskip = max(S.front() == 'R' ? p1 : 0, S.back() == 'R' ? p2 : 0);
	int bskip = max(S.front() == 'B' ? p1 : 0, S.back() == 'B' ? p2 : 0);
	int ans = min(rcnt - rskip, bcnt - bskip);
	cout << ans << "\n";
	return 0;
}
