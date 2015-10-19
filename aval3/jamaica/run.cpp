#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>

#include <cmath>

using namespace std;

typedef pair<int, int> Slope;

struct Road {
	int left;
	int right;
	Slope slope;
	double length;
};

vector<pair<int, int>> cities;
map<pair<int, int>, Road> roads;
map<pair<int, int>, list<Road*>> road_slopes;

void connect(int left, int right) {
	cout << "connect" << " " << left << " " << right << endl;

	if(left > right)
		swap(left, right);

	auto it = roads.find(make_pair(left, right));
	if(it == roads.end()) {
		auto &lc = cities[left], &rc = cities[right];
		double dx = (lc.first - rc.first), dy = (lc.first - rc.first);

		double dist = sqrt(dx * dx + dy * dy);
		Slope slope = make_pair(abs(dy), (dx * dy) > 0 ? abs(dx) : -abs(dx));
		Road road {left, right, slope, dist};

		roads.emplace(make_pair(left, right), road);	
		road_slopes[slope].emplace_front(&roads.back());
	}
}

void connect_all(int start) {
	if(start >= cities.size())
		return;

	for(int i = start+1; i < cities.size(); ++i) {
		connect(start, i);
	}

	connect_all(start+1);
}

void merge_roads() {
	for(auto it = road_slopes.begin(); it != road_slopes.end(); ++it) {
		list<Road> &roads = it->second;
		int merged;
		do {
			merged = 0;
			auto rit = roads.begin();

			for(;;) {
				auto next_it = rit; ++next;
				if(next_it == roads.end())
					break;

				auto a = rit;
				auto b = next_it;

				if(a->length == 0 || b->length == 0)
					continue;

				if(a->left == b->left) {
					if(b->length > a->length)
						swap(a, b);

					b->length = 0;
					merged++;
				}
			}
		} while(merged > 0);
	}
}


int main(int argc, char **argv) {
	int n_cities;
	cin >> n_cities;

	cities.reserve(n_cities);

	for(int i = 0; i < n_cities; ++i) {
		int x, y;
		cin >> x >> y;

		cities.emplace_back(x, y);
	}

	connect_all(0);
	merge_roads();

	double total = 0;
	for(auto &r : roads) {
		total += r.second.length;
	}

	cout << total << endl;

	return 0;
}