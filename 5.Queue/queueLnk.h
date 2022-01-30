//--------------------------------------------------------------------
//
//  Laboratory 6                                          queuelnk.h
//
//  Class declarations for the linked list implementation of the
//  Queue ADT
//
//--------------------------------------------------------------------

template < class DT >        // Forward declaration of the Stack class 
class Queue;

template < class DT >
class QueueNode              // Facilitator class for the Queue class
{
private:

    // Constructor
    QueueNode(const DT& nodeData, QueueNode* nextPtr);

    // Data members
    DT dataItem;         // Queue data item
    QueueNode* next;     // Pointer to the next element

    friend class Queue<DT>;
};

//--------------------------------------------------------------------

template < class DT >
class Queue
{
public:

    // Constructor
    Queue(int ignored = 0);

    // Destructor
    ~Queue();

    // Queue manipulation operations
    void enqueue(const DT& newData);        // Enqueue data element
    DT dequeue();                             // Dequeue data element

    void clear();                            // Clear queue

    // Queue status operations
    bool isEmpty() const;                    // Queue is empty
    bool isFull() const;                     // Queue is full

    // Output the queue structure -- used in testing/debugging
    void showStructure() const;

    void putFront(const DT& newDataItem); //Lab 2
    DT getRear(); //Lab 2
    int getLength() const; // in-Lab3

private:

    // Data members
    QueueNode<DT>* front,   // Pointer to the front node
        * rear;    // Pointer to the rear node
};
