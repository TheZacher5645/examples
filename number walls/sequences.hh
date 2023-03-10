#include <gmpxx.h>

mpz_class Fib(int n) { // valid for n = [-100 ... 100]
	const mpf_class phi      {"1.61803398874989484820458", 80};
	const mpf_class invsqrt5 {"0.44721359549995793928183", 80};

	mpf_class result {invsqrt5};
	for (int i=0; i < std::abs(n); i++)
		result *= phi;
	result *= (n >= 0 || n%2 == 0) ? 1 : -1;
	result = floor(0.5 + result);
	return mpz_class{result};
}

// https://www.youtube.com/watch?v=NO1_-qptr6c&t=904
mpz_class seq_ZeroWindows(int n) {
	bool a = mpz_perfect_square_p(mpz_class{8*n + 9}.get_mpz_t());
	if (n < 0) { a = true; }
    return mpz_class{a ? 1 : 0};
}

mpz_class seq_Rueppel(int n) {
	bool a = false;
	for (mpz_class k=1; k-1 <= n; k*=2) {
		if (n == k-1) { a = true; break; }
	}
	return mpz_class{a ? 1 : 0};
}

mpz_class seq_Rook(int n) {
    if (n == 0) { return 0; }
    if (n <  0) { return 1-(seq_Rook(-n)); }
    int d = n - (n & (n-1));
    return n / d / 2 % 2;
}

mpz_class seq_Knight(int n) {
    return (seq_Rook(n+1) - seq_Rook(n-1)) % 2;
}