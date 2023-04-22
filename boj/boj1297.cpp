#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d{}, h{}, w{};
	cin >> d >> h >> w;
	double x = sqrt(d * d * 1.0 / (h * h + w * w));
	h = h * x + EPS;
	w = w * x + EPS;
	cout << h << " " << w << "\n";
	return 0;
}
