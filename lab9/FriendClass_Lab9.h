#ifndef FRIEND_CLASS_H
#define FRIEND_CLASS_H

#include "Fish_Lab9.h"
#include "Mammals_Lab9.h"
#include <vector>

class FriendClass {
public:
    void showDetails(const MarineAnimal& animal);
    void calculateStatistics(const std::vector<MarineAnimal*>& animals);
};

#endif // FRIEND_CLASS_H
