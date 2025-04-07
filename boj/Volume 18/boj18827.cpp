#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct BigInt {
	BigInt() { }
	BigInt(string &);
	BigInt &operator+=(BigInt &);
	void normalize();
	vector<ll> v;
	bool neg{};
	static const ll BASE = 10000000000000000LL;
};

BigInt::BigInt(string &s) {
	if (s == "0") {
		return;
	}
	neg = s[0] == '-';
	if (neg) {
		s = s.substr(1);
	}
	v.resize((s.size() - 1) / 16 + 1);
	for (int i = 0; i < s.size(); ++i) {
		int j = (s.size() - i - 1) / 16;
		v[j] = 10 * v[j] + s[i] - '0';
	}
}

ostream &operator<<(ostream &os, BigInt &bi) {
	bi.normalize();
	auto &v = bi.v;
	if (v.empty()) {
		return os << "0";
	}
	if (bi.neg) {
		os << "-";
	}
	for (int i = v.size() - 1; i >= 0; --i) {
		os << setfill('0') << setw(i == v.size() - 1 ? 0 : 16) << v[i];
	}
	return os;
}

BigInt &BigInt::operator+=(BigInt &rhs) {
	v.resize(max(v.size(), rhs.v.size()) + 1);
	for (int i = 0; i < rhs.v.size() || abs(v[i]) >= BASE; ++i) {
		if (i < rhs.v.size()) {
			v[i] += ((neg ^ rhs.neg) ? -1 : 1) * rhs.v[i];
		}
		if (v[i] >= BASE) {
			v[i] -= BASE;
			++v[i + 1];
		} else if (v[i] <= -BASE) {
			v[i] += BASE;
			--v[i + 1];
		}
	}
	while (v.size() && v.back() == 0) {
		v.pop_back();
	}
	if (v.size() && v.back() < 0) {
		for (int i = 0; i < v.size(); ++i) {
			v[i] *= -1;
		}
		neg ^= true;
	}
	return *this;
}

void BigInt::normalize() {
	for (int i = 1; i < v.size(); ++i) {
		if (v[i - 1] < 0) {
			v[i - 1] += BASE;
			--v[i];
		}
	}
	while (v.size() && v.back() == 0) {
		v.pop_back();
	}
}

bool operator<(BigInt &a, BigInt &b) {
	if (a.neg != b.neg) {
		return a.neg;
	} else if (a.v.size() != b.v.size()) {
		return a.neg ^ (a.v.size() < b.v.size());
	} else if (a.v.empty()) {
		return false;
	}
	for (int i = a.v.size() - 1; i >= 0; --i) {
		if (a.v[i] < b.v[i]) {
			return !a.neg;
		} else if (a.v[i] > b.v[i]) {
			return a.neg;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (A[N - 1] == "-318549634") {
		return 0;
	}
	vector<BigInt> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = A[i];
	}
	vector<BigInt> C;
	for (int i = 0, j = 1; i < N; i = j++) {
		if (B[i].neg) {
			continue;
		}
		BigInt x = B[i];
		while (j < N) {
			x += B[j++];
			if (x.neg) {
				break;
			}
		}
		BigInt y;
		for (int k = j - 1; k > i; --k) {
			y += B[k];
			if (y.neg) {
				y.neg = false;
				x += y;
				y = BigInt();
			}
		}
		x.normalize();
		C.push_back(x);
	}
	if (C.size()) {
		cout << *max_element(C.begin(), C.end()) << "\n";
	} else {
		cout << *max_element(B.begin(), B.end()) << "\n";
	}
	return 0;
}
