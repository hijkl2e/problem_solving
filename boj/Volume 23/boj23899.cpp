#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	bool yes = A == B;
	for (int i = N - 1; i > 0; --i) {
		int j = max_element(A.begin(), A.begin() + i + 1) - A.begin();
		if (j < i) {
			swap(A[j], A[i]);
			if (A == B) {
				yes = true;
				break;
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
