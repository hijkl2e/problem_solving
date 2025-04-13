#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A, B;
	while (N >= 3) {
		A.push_back(N);
		B.push_back(N - 1);
		B.push_back(N - 2);
		N -= 3;
	}
	if (N == 2) {
		A.push_back(2);
		B.push_back(1);
	}
	cout << A.size() << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
