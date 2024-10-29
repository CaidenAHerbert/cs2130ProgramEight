#include <iostream>
#include <random>
#include <ctime>

//50% chance of winning if the contestant switches door vs a 33% chance if the player does not switch doors

int main() {
    int numSimulations = 100000;
    int winSwitch = 0;
    int winNoSwitch = 0;

    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> doorDist(0, 2);

    for(int i = 0; i < numSimulations; i++) {
        int winningDoor = doorDist(rng);
        int contestantChoice = doorDist(rng);

        int reveal;
        do {
            reveal = doorDist(rng);
        }
        while (reveal == contestantChoice || reveal == winningDoor);

        int remainingDoor;
        for (int door = 0; door < 3; ++door) {
            if (door != contestantChoice && door != reveal) {
                remainingDoor = door;
                break;
            }
        }

        if (remainingDoor == winningDoor) {
            ++winSwitch;
        }

        if (contestantChoice == winningDoor) {
            ++winNoSwitch;
        }
    }

    double switchWinProbability = static_cast<double>(winSwitch) / numSimulations;
    double noSwitchWinProbability = static_cast<double>(winNoSwitch) / numSimulations;

    std::cout << "Probability of winning if the contestant switches: " << switchWinProbability << std::endl;
    std::cout << "Probability of winning if the contestant does not switch: " << noSwitchWinProbability << std::endl;

    return 0;
}
