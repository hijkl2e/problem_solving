#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h1{}, m1{}, h2{}, m2{};
	char c{};
	cin >> h1 >> c >> m1 >> h2 >> c >> m2;
	int t1 = 60 * h1 + m1;
	int t2 = 60 * h2 + m2;
	int N{}, T{};
	cin >> N >> T;
	int x = (t2 - t1 - 1) / T;
	t2 = t1 + T * (N % x + 1);
	cout << N / x << "\n";
	cout << setfill('0') << setw(2) << t2 / 60 << ":" << setw(2) << t2 % 60 << "\n";
	return 0;
}
