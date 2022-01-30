// --------------------------------------------------------------------
//
// 2020112377 ±è¹Î¼ö
//  Laboratory B, In-lab Exercise 1                       ossim.cpp
//
//  (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).


#include <iostream>
#include <cstdlib>
#include "ptyqueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int priority,              // Task's priority
        arrived;               // Time when task was enqueued

    void setPty(int newPty)
    {
        priority = newPty;
    }   // Set the priority

    int pty() const
    {
        return priority;
    }   // Returns the priority
};

//--------------------------------------------------------------------



void main()
{

    PtyQueue<TaskData> taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals;             // Number of new tasks arriving

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    int lowwaits = 0;
    int highwaits = 0;
    numArrivals = 0;
    srand(500); //seed°ªÀ» 500À¸·Î

    for (minute = 0; minute < simLength; ++minute)
    {
        cout << endl << endl << "Current minute = " << minute << endl;
        if (!(taskPQ.isEmpty())) { //If the queue is not empty
            task = taskPQ.dequeue(); //then remove the task at the front of the queue. 
            cout << "Task Dequeued" << endl;
            cout << "This task's priority: " << task.pty() << endl;
            cout << "This task was arrived at " << task.arrived <<
                ", and waited for " << minute - task.arrived << " minutes" << endl;

            if (task.pty() == 0) {
                if (minute - task.arrived > lowwaits)
                    lowwaits = minute - task.arrived;
            }

            else if (task.pty() == 1) {
                if (minute - task.arrived > highwaits)
                    highwaits = minute - task.arrived;
            }


        }

    int k = rand()%4; //Compute a random integer k between 0 and 3.

            if (k == 1) { //If k is 1, then add one task to the queue. 
                numArrivals++;
                int nums = rand() % numPtyLevels; // 0 ~ 1
                task.setPty(nums);
                task.arrived = minute;
                taskPQ.enqueue(task);
                cout << "Adding 1 task" << endl;
            }

            else if (k == 2) { // If k is 2, then add two tasks.
                numArrivals++;
                int nums = rand() % numPtyLevels; // 0 ~ 1
                task.setPty(nums);
                task.arrived = minute;
                taskPQ.enqueue(task);

                numArrivals++;
                nums = rand() % numPtyLevels; // 0 ~ 1
                task.setPty(nums);
                task.arrived = minute;
                taskPQ.enqueue(task);
                cout << "Adding 2 tasks" << endl;
            }

            else { //Otherwise (if k is 0 or 3), do not add any tasks to the queue.
                cout << "No task was added this time" << endl;
            }

            cout << endl << endl;
            taskPQ.showStructure();

        }
        cout << "Longest wait for any low-priority(0) task : " << lowwaits << endl;
        cout << "Longest wait for any high-priority(1) task : " << highwaits << endl;

        system("pause");

} 

