#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	deque<bool> vst(26);
	for (int i = 1; i < N; ++i) {
		vst[max(A[0][0], A[i][1]) - 'A'] = true;
	}
	vst[max(A[0][1], A[1][0]) - 'A'] = true;
	for (int i = 0; i < N; ++i) {
		reverse(A[i].begin(), A[i].end());
	}
	sort(A.begin(), A.end());
	for (int i = 1; i < N; ++i) {
		vst[max(A[0][0], A[i][1]) - 'A'] = true;
	}
	vst[max(A[0][1], A[1][0]) - 'A'] = true;
	vector<char> B;
	for (int i = 0; i < 26; ++i) {
		if (vst[i]) {
			B.push_back(i + 'A');
		}
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
