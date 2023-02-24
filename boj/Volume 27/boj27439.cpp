#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> mul(vector<ll> &v1, vector<ll> &v2) {
	vector<ll> res(v1.size() + v2.size());
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v2.size(); ++j) {
			res[i + j] += v1[i] * v2[j];
		}
	}
	for (int i = 1; i < res.size(); ++i) {
		res[i] += res[i - 1] / 10000000;
		res[i - 1] %= 10000000;
	}
	while (res.back() == 0) {
		res.pop_back();
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	auto cmp = [](vector<ll> &a, vector<ll> &b) {
		return a.size() > b.size();
	};
	priority_queue<vector<ll>, vector<vector<ll>>, decltype(cmp)> pq(cmp);
	for (int i = 0; i <= N; ++i) {
		pq.push(vector<ll>{max(i, 1)});
	}
	while (pq.size() > 1) {
		vector<ll> v1 = pq.top(); pq.pop();
		vector<ll> v2 = pq.top(); pq.pop();
		vector<ll> res = mul(v1, v2);
		pq.push(res);
	}
	vector<ll> v = pq.top();
	cout << v.back();
	for (int i = v.size() - 2; i >= 0; --i) {
		cout << setw(7) << setfill('0') << v[i];
	}
	cout << "\n";
	return 0;
}
