#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double w{}, h{};
	cin >> w >> h;
	double bmi = w / (h * h);
	string ans;
	if (bmi > 25) {
		ans = "Overweight";
	} else if (bmi < 18.5) {
		ans = "Underweight";
	} else {
		ans = "Normal weight";
	}
	cout << ans << "\n";
	return 0;
}
