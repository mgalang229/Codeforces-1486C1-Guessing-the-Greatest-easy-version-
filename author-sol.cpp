#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
	if (l >= r)
		return -1;
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int ans;
	cin >> ans;
	return ans - 1;
}

void test_case(int& tc) {
	int n;
	cin >> n;
	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int smax = ask(l, r - 1);
		if (smax < m) {
			if (ask(l, m - 1) == smax)
				r = m;
			else
				l = m;
		} else {
			if (ask(m, r - 1) == smax)
				l = m;
			else
				r = m;
		}
	}
	cout << "! " << r << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
