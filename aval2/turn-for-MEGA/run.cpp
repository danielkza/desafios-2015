#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int sem_cars_per_minute, minutes;
    cin >> sem_cars_per_minute >> minutes;

    vector<int> cars_each_minute;
    cars_each_minute.reserve(minutes);

    for(int i = 0; i < minutes; i++) {
        int cars;
        cin >> cars;
        cars_each_minute.push_back(cars);
    }

    int cars_waiting = 0;
    for(int cars_approaching : cars_each_minute) {
        cars_waiting = (cars_waiting + cars_approaching) - sem_cars_per_minute;
        cars_waiting = max(cars_waiting, 0);
    }

    cout << cars_waiting << endl;
    return 0;

}
