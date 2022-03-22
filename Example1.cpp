#include <iostream>

using namespace std;

class Solution {
public:
	Solution() { return; }
	int divide(int A, int B) {
		long flag = 1;
		if ((A > 0 && B < 0) || (A < 0 && B>0)) flag = -1;

		long dividendo = labs(A);
		long divisor = labs(B);
		long cociente = 0;
		long temp = 0;

		for (int i = 31; i >= 0; i--) {
			if (temp + (divisor << i) <= dividendo) {
				temp = temp + (divisor << i);
				cociente = cociente + (1L << i);
			}
		}

		if (flag == 1 && cociente >= INT_MAX) return INT_MAX;
		if (flag == -1 && cociente >= INT_MAX) return INT_MIN;
		return flag*cociente;
	}
};

int main() {
	Solution sol();
	int A = 10, B = 2;
	cout << A << "/" << B << "=" << sol().divide(A,B) << endl;
	return 0;
}