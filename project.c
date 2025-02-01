#include "project.h"

int main() {
    CircularQueue road1, road2, road3;

    // Initialize queues for each road
    initializeQueue(&road1);
    initializeQueue(&road2);
    initializeQueue(&road3);

    const char *inputFilename = "D:\\DSA MCA\\project\\project4_data.csv";
    const char *outputFilename = "D:\\DSA MCA\\project\\output.txt";

    // Simulate traffic management using the provided dataset
    simulateTraffic(&road1, &road2, &road3, "D:\\DSA MCA\\project\\project4_data.csv","D:\\DSA MCA\\project\\output.txt");

    return 0;
}