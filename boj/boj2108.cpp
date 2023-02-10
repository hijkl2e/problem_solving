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
	sort(A.begin(), A.end());
	vector<int> B(8001);
	for (int i = 0; i < N; ++i) {
		++B[A[i] + 4000];
	}
	auto it1 = max_element(B.begin(), B.end());
	auto it2 = find(it1 + 1, B.end(), *it1);
	int avg = lround(accumulate(A.begin(), A.end(), 0) * 1.0 / N);
	int mode = (it2 == B.end() ? it1 : it2) - B.begin() - 4000;
	cout << avg << "\n" << A[N / 2] << "\n" << mode << "\n" << A[N - 1] - A[0] << "\n";
	return 0;
}
