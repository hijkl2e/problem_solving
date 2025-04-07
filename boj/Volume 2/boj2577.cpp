#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	string S = to_string(A * B * C);
	vector<int> D(10);
	for (char c : S) {
		++D[c - '0'];
	}
	for (int i = 0; i < 10; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
