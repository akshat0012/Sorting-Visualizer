#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

#ifndef util_hpp
#define util_hpp

class randi{
public:
    void randVec(std::vector<int>& vec, int lowerBound, int upperBound) {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(lowerBound, upperBound);
        for (int i=0; i<vec.size(); i++) {
            int randomNumber = dist(rng);
            vec[i] = randomNumber;
        }
    } 
    
    void show(std::vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            std::cout << nums[i] << ' ';
        }
        std::cout << '\n';
    }

    ~randi() {
        std::cout << "[RandomObject_deleted]\n";
    }
};


#endif
