#include <iostream>
#include <string>

using namespace std;
/*
Implement a traffic light system in an intersection(int sec) where progression order is Red -> Green -> yellow. Use the below table to determine duration in secs
Color      East-west             North-south

Yellow     2                         1
green      3                         5
Both turn red for 1 sec
Example:
for duration 15 sec
EW G NS R
EW G NS R
EW G NS R
EW Y NS R
EW Y NS R
EW R NS R
EW R NS G
EW R NS G
EW R NS G
EW R NS G
EW R NS G
EW R  NS Y
EW R NS Y
EW R NS R and so on
write in cpp
 */
//TC:O(DURATION) SC:O(1
// Enumeration for different phases of traffic lights
enum Phase {
    EW_GREEN_NS_RED = 0,
    EW_YELLOW_NS_RED,
    BOTH_RED_EW_TO_NS,  // Red phase when switching from EW to NS
    EW_RED_NS_GREEN,
    EW_RED_NS_YELLOW,
    BOTH_RED_NS_TO_EW,  // Red phase when switching from NS to EW
    CYCLE_END
};

// Table for traffic light durations (in seconds)
const int trafficLightDurations[] = {
    3, // East-West Green, North-South Red (EW_GREEN_NS_RED)
    2, // East-West Yellow, North-South Red (EW_YELLOW_NS_RED)
    1, // Both Red for switching to NS (BOTH_RED_EW_TO_NS)
    5, // East-West Red, North-South Green (EW_RED_NS_GREEN)
    1, // East-West Red, North-South Yellow (EW_RED_NS_YELLOW)
    1  // Both Red for switching to EW (BOTH_RED_NS_TO_EW)
};

// Function to get the phase name for each phase
string getPhaseStatus(Phase phase) {
    switch (phase) {
        case EW_GREEN_NS_RED:
            return "EW: Green NS: Red";
        case EW_YELLOW_NS_RED:
            return "EW: Yellow NS: Red";
        case BOTH_RED_EW_TO_NS:
        case BOTH_RED_NS_TO_EW:
            return "EW: Red NS: Red";
        case EW_RED_NS_GREEN:
            return "EW: Red NS: Green";
        case EW_RED_NS_YELLOW:
            return "EW: Red NS: Yellow";
        default:
            return "Unknown Phase";
    }
}

// Function to execute each phase based on the phase and duration
void executePhase(Phase phase, int& time, int duration) {
    string phaseStatus = getPhaseStatus(phase);

    for (int i = 0; i < trafficLightDurations[phase] && time < duration; i++) {
        cout << "Time: " << time + 1 << "s -> " << phaseStatus << endl;
        time++;
    }
}

// Function to simulate the traffic lights
void simulateTrafficLights(int duration) {
    int time = 0;  // Time counter

    while (time < duration) {
        // Loop through all phases
        for (int phase = EW_GREEN_NS_RED; phase < CYCLE_END && time < duration; phase++) {
        	cout << "Phase:" << phase << endl;
            executePhase(static_cast<Phase>(phase), time, duration);
        }
    }
}

int main() {
    int duration = 20; // Setting duration to 20 for this example

    // Simulate the traffic lights based on the progression table
    simulateTrafficLights(duration);
    return 0;
}
