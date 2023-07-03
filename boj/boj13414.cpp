#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, L{};
	cin >> K >> L;
	cin.ignore();
	vector<string> A(L);
	for (int i = 0; i < L; ++i) {
		cin >> A[i];
	}
	vector<string> B;
	set<string> S;
	for (int i = L - 1; i >= 0; --i) {
		if (S.insert(A[i]).second) {
			B.push_back(A[i]);
		}
	}
	reverse(B.begin(), B.end());
	if (B.size() > K) {
		B.resize(K);
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
