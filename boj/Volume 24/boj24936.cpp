#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	vector<int> B(A.size());
	for (int i = 0; i < B.size(); ++i) {
		B[i] = sum - A[i];
	}
	reverse(B.begin(), B.end());
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
