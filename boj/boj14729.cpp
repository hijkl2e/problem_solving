#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(100001);
	while (N--) {
		double x{};
		cin >> x;
		++A[1000 * x + EPS];
	}
	vector<int> B;
	for (int i = 0; B.size() < 7; ++i) {
		while (A[i] && B.size() < 7) {
			B.push_back(i);
			--A[i];
		}
	}
	for (int x : B) {
		cout << x / 1000 << "." << setfill('0') << setw(3) << x % 1000 << "\n";
	}
	return 0;
}
