#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "n e\n- -----------\n0 1\n1 2\n2 2.5\n";
	double e = 2.5;
	int d = 2;
	for (int i = 3; i < 10; ++i) {
		d *= i;
		e += 1.0 / d;
		cout << i << " ";
		cout << fixed << setprecision(9);
		cout << e << "\n";
	}
	return 0;
}
