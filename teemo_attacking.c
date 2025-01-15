#include <stdio.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0) {
        return 0; // No attacks, no poison
    }

    int totalPoisonedTime = 0;

    // Iterate through the timeSeries array
    for (int i = 0; i < timeSeriesSize - 1; i++) {
        // Add the smaller value between the gap and the duration
        totalPoisonedTime += (timeSeries[i + 1] - timeSeries[i] < duration) 
                             ? (timeSeries[i + 1] - timeSeries[i]) 
                             : duration;
    }

    // Add the full duration for the last attack
    totalPoisonedTime += duration;

    return totalPoisonedTime;
}

int main() {
    int timeSeries[] = {1, 4};
    int timeSeriesSize = 2;
    int duration = 2;

    int result = findPoisonedDuration(timeSeries, timeSeriesSize, duration);
    printf("Total Poisoned Time: %d\n", result);

    return 0;
}

