#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt{};
	while (getline(cin, S), S != "고무오리 디버깅 끝") {
		if (S == "문제") {
			++cnt;
		} else {
			cnt += cnt ? -1 : 2;
		}
	}
	cout << (cnt ? "힝구" : "고무오리야 사랑해") << "\n";
	return 0;
}
