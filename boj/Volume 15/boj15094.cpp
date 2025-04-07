#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(10);
	vector<int> B(10);
	for (int i = 0; i < 10; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> U(10);
	vector<int> R(10);
	vector<int> T(10);
	for (int i = 0; i < 10; ++i) {
		cin >> U[i] >> R[i] >> T[i];
	}
	int time{};
	for (int k = 0; k < 3; ++k) {
		for (int i = 0; i < 10; ++i) {
			if (T[i] > time) {
				time += A[i];
				T[i] = max(T[i], time);
				time += B[i];
			} else {
				T[i] += (time - T[i]) / (U[i] + R[i]) * (U[i] + R[i]);
				int r = (time - T[i]) % (U[i] + R[i]);
				if (r < U[i]) {
					time += U[i] - r;
				}
				time += A[i];
				T[i] = max(T[i] + U[i] + R[i], time);
				time += B[i];
			}
		}
	}
	time -= B[9];
	cout << time << "\n";
	return 0;
}
