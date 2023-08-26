#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	multiset<string> S;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		S.insert(s);
	}
	for (int i = 0; i < N - 1; ++i) {
		string s;
		cin >> s;
		S.erase(S.find(s));
	}
	cout << *S.begin() << "\n";
	return 0;
}
