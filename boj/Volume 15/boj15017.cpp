#include <bits/stdc++.h>

using namespace std;

using rec = tuple<double, double, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<rec> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[a, b, c] = A[i];
		cin >> c >> b >> a;
	}
	sort(A.begin(), A.end());
	double mini{}, minv = 1e9;
	for (int i = 0; i < N; ++i) {
		double sum{};
		for (int j = i < 3 ? 3 : 2; j >= 0; --j) {
			if (i == j) {
				continue;
			}
			sum += get<0>(A[j]);
		}
		sum += get<1>(A[i]);
		if (minv > sum) {
			mini = i;
			minv = sum;
		}
	}
	cout << fixed << setprecision(10);
	cout << minv << "\n";
	cout << get<2>(A[mini]) << "\n";
	for (int j = mini < 3 ? 3 : 2; j >= 0; --j) {
		if (mini == j) {
			continue;
		}
		cout << get<2>(A[j]) << "\n";
	}
	return 0;
}
