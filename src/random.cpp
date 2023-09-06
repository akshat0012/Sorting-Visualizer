#include <bits/stdc++.h>
using namespace std;

vector<int> random(int _min, int _max, int numberOfBars) {
    vector<int> heights;

    std::random_device rd; // random number for seeding
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(_min, _max);
    
    for (int i=0; i<numberOfBars; i++) {
        heights.push_back(distr(gen));
    }
    return heights;
}

int main() {
    vector<int> result = random(100, 120, 50);
    for (auto& l:result) {
        cout << l << "\n";
    }
    return 0;
}
