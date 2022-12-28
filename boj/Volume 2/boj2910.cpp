#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	map<int, int> freq;
	map<int, int> idx;
	for (int i = N - 1; i >= 0; --i) {
		++freq[A[i]];
		idx[A[i]] = i;
	}
	sort(A.begin(), A.end(), [&](int a, int b) {
		return freq[a] > freq[b] || (freq[a] == freq[b] && idx[a] < idx[b]);
	});
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
