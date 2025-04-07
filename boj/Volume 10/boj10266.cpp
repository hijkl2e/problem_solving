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

bool kmp(vector<int> &A, vector<int> &B) {
	vector<int> pi = get_pi(B);
	for (int i = 0, j = 0; i < A.size(); ++i) {
		while (j && A[i] != B[j]) {
			j = pi[j - 1];
		}
		if (A[i] == B[j] && ++j == B.size()) {
			return true;
		}
	}
	return false;
}

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
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> C(2 * N - 2);
	vector<int> D(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		C[i] = A[i + 1] - A[i];
		D[i] = B[i + 1] - B[i];
	}
	C[N - 1] = A[0] - A[N - 1] + 360000;
	for (int i = N; i < C.size(); ++i) {
		C[i] = C[i - N];
	}
	cout << (kmp(C, D) ? "possible" : "impossible") << "\n";
	return 0;
}
