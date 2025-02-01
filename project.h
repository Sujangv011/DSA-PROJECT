#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 200

// Structure for circular queue
typedef struct {
    int vehicles[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

// Function prototypes
void initializeQueue(CircularQueue *q);
int isFull(CircularQueue *q);
int isEmpty(CircularQueue *q);
void enqueue(CircularQueue *q, int vehicle);
int dequeue(CircularQueue *q);
void simulateTraffic(CircularQueue *road1, CircularQueue *road2, CircularQueue *road3, const char *filename, const char *outputFilename);

void initializeQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(CircularQueue *q) {
    return q->count == MAX_QUEUE_SIZE;
}

int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

void enqueue(CircularQueue *q, int vehicle) {
    if (isFull(q)) {
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->vehicles[q->rear] = vehicle;
    q->count++;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int vehicle = q->vehicles[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return vehicle;
}

void simulateTraffic(CircularQueue *road1, CircularQueue *road2, CircularQueue *road3, const char *filename, const char *outputFilename) {
    FILE *file = fopen(filename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    if (!file || !outputFile) {
        printf("Failed to open input or output file.\n");
        return;
    }

    char line[300];
    fgets(line, sizeof(line), file); // Skip the header line

    int lightChangeInterval = 10; // Change light every 10 seconds
    int currentRoad = 1; // Start with road1
    int lightChanges = 0;
    int time = 0;

    // Print old format header to terminal
    printf("Time    Road 1                  Road 2                  Road 3\n");
    printf("-------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        char road[10], vehicle[20];
        float arrivalTime;
        sscanf(line, "%[^,],%[^,],%f", road, vehicle, &arrivalTime);

        int vehicleID = atoi(&vehicle[8]); // Extract numeric part of vehicle ID

        // Simulate arrival of vehicles
        printf("%-8d", time);
        if (strcmp(road, "Road 1") == 0) {
            if (isFull(road1)) {
                printf("FULL                      ");
                fprintf(outputFile, "Time %d: Road 1 is FULL.\n", time);
            } else {
                enqueue(road1, vehicleID);
                printf("Vehicle %d 1       ", vehicleID);
                fprintf(outputFile, "Time %d: Vehicle %d entered Road 1.\n", time, vehicleID);
            }
        } else {
            printf("                     ");
        }

        if (strcmp(road, "Road 2") == 0) {
            if (isFull(road2)) {
                printf("FULL                      ");
                fprintf(outputFile, "Time %d: Road 2 is FULL.\n", time);
            } else {
                enqueue(road2, vehicleID);
                printf("Vehicle %d 1       ", vehicleID);
                fprintf(outputFile, "Time %d: Vehicle %d entered Road 2.\n", time, vehicleID);
            }
        } else {
            printf("                     ");
        }

        if (strcmp(road, "Road 3") == 0) {
            if (isFull(road3)) {
                printf("FULL                      \n");
                fprintf(outputFile, "Time %d: Road 3 is FULL.\n", time);
            } else {
                enqueue(road3, vehicleID);
                printf("Vehicle %d 1       \n", vehicleID);
                fprintf(outputFile, "Time %d: Vehicle %d entered Road 3.\n", time, vehicleID);
            }
        } else {
            printf("\n");
        }

        // Simulate vehicles leaving
        if (time % lightChangeInterval == 0) {
            for (int i = 0; i < 5; i++) { // Allow 5 vehicles to leave
                printf("%-8d", time);
                int leavingVehicle = -1;
                if (currentRoad == 1) {
                    if (isEmpty(road1)) {
                        printf("EMPTY                      ");
                        fprintf(outputFile, "Time %d: Road 1 is EMPTY.\n", time);
                    } else {
                        leavingVehicle = dequeue(road1);
                        printf("Vehicle %d 0       ", leavingVehicle);
                        fprintf(outputFile, "Time %d: Vehicle %d left Road 1.\n", time, leavingVehicle);
                    }
                } else {
                    printf("                     ");
                }

                if (currentRoad == 2) {
                    if (isEmpty(road2)) {
                        printf("EMPTY                      ");
                        fprintf(outputFile, "Time %d: Road 2 is EMPTY.\n", time);
                    } else {
                        leavingVehicle = dequeue(road2);
                        printf("Vehicle %d 0       ", leavingVehicle);
                        fprintf(outputFile, "Time %d: Vehicle %d left Road 2.\n", time, leavingVehicle);
                    }
                } else {
                    printf("                     ");
                }

                if (currentRoad == 3) {
                    if (isEmpty(road3)) {
                        printf("EMPTY                      \n");
                        fprintf(outputFile, "Time %d: Road 3 is EMPTY.\n", time);
                    } else {
                        leavingVehicle = dequeue(road3);
                        printf("Vehicle %d 0       \n", leavingVehicle);
                        fprintf(outputFile, "Time %d: Vehicle %d left Road 3.\n", time, leavingVehicle);
                    }
                } else {
                    printf("\n");
                }
            }
            currentRoad = (currentRoad % 3) + 1;
            lightChanges++;
        }
        time++;
    }
    fclose(file);
    fclose(outputFile);
    printf("-------------------------------------------------------------------\n");
    printf("Simulation ended. Total light changes: %d.\n", lightChanges);
}
