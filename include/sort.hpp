#include <iostream>
#include <UI.hpp>
#include <algorithm>

#ifndef sort_hpp
#define sort_hpp

class Sort {
public:
    void bubbleSort(std::vector<int>& nums, sf::RenderWindow& window, Bars* BarsObject) {
        sf::Clock clock;
        float delay = 1.0f; // 1 second delay
    
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);

                        window.clear(sf::Color(40, 40, 40));
                        BarsObject->drawVec(nums, numberOfBars, window);
                        window.display();
                }
            }
        }
    }

    
    ~Sort() {
        std::cout<< "[SortObject_deleted]\n";
    }


};

#endif
