#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"ABCDEFGHJLM", "ACEFGHILM", "ACEFGHILM", "ABCEFGHLM", "ACEFGHLM",
		"ACEFGHLM", "ACEFGHLM", "ACEFGHLM", "ACEFGHLM", "ABCFGHLM"
	};
	int N{};
	cin >> N;
	auto &S = A[N - 1];
	cout << S.size() << "\n";
	for (int i = 0; i < S.size(); ++i) {
		cout << S[i] << (i == S.size() - 1 ? "\n" : " ");
	}
	return 0;
}
