
# Smart Traffic Management System 🚦

## Project Overview
This project simulates a **Smart Traffic Management System** using **Circular Queues** in C. It aims to optimize traffic light timing at a **3-road junction** by analyzing the random arrival of vehicles and managing lane queues effectively.

## Features
- **Circular Queue Implementation**: Uses an array-based circular queue with a maximum size of 200 vehicles per road.
- **Traffic Simulation**: Reads vehicle arrival data from a CSV file and processes it to simulate traffic flow.
- **Traffic Light Control**: Implements a traffic light algorithm to determine the duration of green and red signals.
- **Efficient Data Handling**: Vehicles enter and leave queues dynamically, ensuring optimal road usage.
- **Output Logging**: Generates an output file (`project4_output.txt`) to record vehicle movements and light changes.

## Files in the Repository
- `project.c` - Main program implementing the traffic simulation logic.
- `project.h` - Header file containing function prototypes and queue structures.
- `project4_data.csv` - Sample dataset with vehicle arrival information.
- `project4_output.txt` - Output file storing simulation results.
- `DSA-Project4.pdf` - Project description and problem statement.

## How to Run the Project
### Prerequisites
- A **C Compiler** (GCC recommended)
- A working **C development environment** (Linux/Mac terminal or Windows with MinGW)

### Steps
1. Clone this repository:
   ```sh
   git clone https://github.com/your-username/Smart-Traffic-Management.git
   cd Smart-Traffic-Management
   ```
2. Compile the program:
   ```sh
   gcc project.c -o traffic_simulation
   ```
3. Run the program:
   ```sh
   ./traffic_simulation
   ```
4. View the output in `project4_output.txt`:
   ```sh
   cat project4_output.txt
   ```

## Algorithm Explanation
The project uses **Circular Queues** to efficiently manage vehicle flow:
- **Enqueue**: When a vehicle arrives, it is added to the queue of the respective road.
- **Dequeue**: When the light turns green for a road, a fixed number of vehicles leave the queue.
- **Traffic Light Rotation**: The green signal shifts between roads at predefined time intervals.
- **Handling Queue Overflow**: If a queue is full, incoming vehicles are denied entry.

## Possible Enhancements 🚀
- **Linked List Implementation**: Instead of an array, a dynamic queue could be used.
- **Real-Time Sensor Integration**: Modify the algorithm to consider live traffic density.
- **Adaptive Signal Timing**: Use machine learning to optimize light intervals.

## Author
👤 **Sujan G V**  
📧 sujangv94@gmail.com  
🔗 [GitHub Profile](https://github.com/Sujangv011)

## License
This project is licensed under the **MIT License**.

---

🚀 Happy Coding & Traffic Management!
```
