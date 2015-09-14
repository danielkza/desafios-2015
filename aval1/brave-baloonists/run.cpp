#include <iostream>
#include <map>
#include <algorithm>
#include <functional>

#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    std::map<int, int> factors;

    for(int i = 1; i <= 10; ++i) {
        int n;
        cin >> n;

        int d = 2;
        while(n > 1) {
            ldiv_t quot = ldiv(n, d);
            if(quot.rem == 0) {
                try {
                    factors.at(d)++;
                } catch(out_of_range) {
                    factors[d] = 1;
                }

                n = quot.quot;
            } else if(++d > n / 2) {
                try {
                    factors.at(n)++;
                } catch(out_of_range) {
                    factors[n] = 1;
                }
                break;
            }
        }
    }

    for(auto f : factors) cout << f.first << " " << f.second << endl;

    int div_c = factors.size() + 2; // count the number one and the result itself

    div_c += rec(factors.begin(), factors.end(), factors.size(), 1);

    for(auto it = factors.begin(); it != factors.end(); ++it) {
        for(int j = 1; j < factors.size(); i++) {
            for(int s = 1; s < (j - 1); s++) {

            }
        }
    }
    // cout << div_c << endl;

    cout << div_c % 10 << endl;
}
