#include <algorithm>

#include <iostream>
#include <vector>

#include <cmath>
#include <cstdint>

using namespace std;

void print_heap(int32_t *n, int len)
{
    for(int i = 0; i < len; ++i) {
        cout << n[i] << endl;
    }

    cout << endl;
}

int main(int argc, char **argv)
{
    int nn;
    cin >> nn;

    int n, half = (nn / 2) + 1;

    int32_t num, *nums = new int32_t[half + 1];
    size_t len = 0;

    for(n = 0; n < half; n++) {
        cin >> num;
        nums[len++] = num;
        push_heap(nums, nums + len);
    }

    for(; n < nn; n++) {
        cin >> num;

        nums[len++] = num;
        push_heap(nums, nums + len);
        pop_heap(nums, nums + len);
        len--;
    }

    cout << fixed;
    cout.precision(1);

    if(nn % 2 != 0) {
        cout << nums[0];
    } else {
        int32_t last = nums[0];
        pop_heap(nums, nums + len);
    
        cout << float(last) * 0.5 + float(nums[0]) * 0.5;
    }

    cout << endl;
    
    return 0;

}
