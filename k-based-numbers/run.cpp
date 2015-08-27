#include <iostream>
#include <vector>

using namespace std;

int digits[16] = {0};

int main(int argc, char **argv)
{
	int num_digits, base;
	cin >> num_digits >> base;

	int count = 0, carry = 0;

	while(true) {
		unsigned int not_ok = 0;
		int i = 0;
		for(carry = 1; i < num_digits - 1; i++) {
			not_ok |= (digits[i] | digits[i+1]) == 0;

			digits[i] += carry;
			if(digits[i] >= base) {
				carry = 1;
				digits[i] -= base;
			} else {
				carry = 0;
			}
		}

		if(!not_ok && digits[i] != 0)
			count++;

		digits[i] += carry;
		if(digits[i] >= base)
			break;
	}

	cout << count << endl;
	return 0;
}