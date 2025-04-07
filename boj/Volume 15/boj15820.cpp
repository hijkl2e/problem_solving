#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + M);
	vector<int> B(N + M);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i] >> B[i];
	}
	int p{};
	while (p < A.size() && A[p] == B[p]) {
		++p;
	}
	if (p == A.size()) {
		cout << "Accepted\n";
	} else if (p < N) {
		cout << "Wrong Answer\n";
	} else {
		cout << "Why Wrong!!!\n";
	}
	return 0;
}
