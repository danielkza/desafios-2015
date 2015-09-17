#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int i_low, low_inc, i_high, high_dec;

    cin >> i_low >> low_inc >> i_high >> high_dec;
    int low = i_low, high = i_high;

    for(;;) {
        if(low >= high)
            break;

        low = min(low + low_inc, high);

        if(low >= high)
            break;

        high -= high_dec;
    }

    cout << max(low, i_low) << endl;

    return 0;

}
