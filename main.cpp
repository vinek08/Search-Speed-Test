#include <chrono>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
int binarySearch();
int linearSearch();
int findSearch();

int main() {
	srand(time(0));
	binarySearch();
	linearSearch();
	findSearch();
}

int binarySearch() {
	auto start = chrono::steady_clock::now();
	vector <int> v(100000000);
	generate(v.begin(), v.end(), []() { return rand() % 100; });
	sort(v.begin(), v.end());
	bool found = binary_search(v.begin(), v.end(), 17);
	cout << "\n 17 found" << boolalpha << " " << found << '\n';
	auto stop = chrono::steady_clock::now();
	auto time = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout <<"Time of binary_search: " << time.count() << "ms" << '\n';
	return 0;
}

int linearSearch() {
	auto start = chrono::steady_clock::now();
	bool found = false;
	vector <int > v(100000000);
	generate(v.begin(), v.end(), []() { return rand() % 100; });
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 17) {
			found = true;
			break;
		}
	}
	cout << "\n 17 found" << " " << boolalpha << found << '\n';
	auto stop = chrono::steady_clock::now();
	auto time = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Time of linear search: " << time.count() << "ms \n";
	return 0;
}

int findSearch() {
	auto start = chrono::steady_clock::now();
	vector <int> v(100000000);
	int target = 17;
	bool found = false;
	generate(v.begin(), v.end(), []() { return rand() % 100; });
	auto it = find(v.begin(), v.end(), 17);
	if (it != v.end())
		found = true;
	cout << "\n 17 found" << " " << boolalpha << found << '\n';
	auto stop = chrono::steady_clock::now();
	auto time = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Time of find: " << time.count() << "ms \n";
	return 0;
}