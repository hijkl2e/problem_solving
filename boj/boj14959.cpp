#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(vector<int> &A) {
	vector<int> pi(A.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && A[i] != A[j]) {
			j = pi[j - 1];
		}
		if (A[i] == A[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = N - 1; i >= 0; --i) {
		cin >> A[i];
	}
	vector<int> pi = get_pi(A);
	int K = N - 1;
	int P = 1;
	for (int i = 0; i < N; ++i) {
		int k = N - i - 1;
		int p = i + 1 - pi[i];
		if (k + p < K + P || (k + p == K + P && p < P)) {
			K = k;
			P = p;
		}
	}
	cout << K << " " << P << "\n";
	return 0;
}
