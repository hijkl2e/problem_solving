#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415927;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double d{}, t{};
	int r{};
	for (int tc = 1; cin >> d >> r >> t, r; ++tc) {
		double dist = PI * d * r / 63360;
		double mph = dist / t * 3600;
		cout << "Trip #" << tc << ": ";
		cout << fixed << setprecision(2);
		cout << dist << " " << mph << "\n";
	}
	return 0;
}
