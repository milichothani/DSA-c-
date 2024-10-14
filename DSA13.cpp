/*Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the
system using circular queue using array.*/




#include <iostream>
#include <string>
using namespace std;
class CircularQueue {
private:
string* orders; // Pointer to dynamically allocate an array to store pizza orders
int front;
int rear;
// Index of the front order
// Index of the rear order
int maxSize; // Maximum number of orders
public:
CircularQueue(int size);
~CircularQueue();
bool isFull();
bool isEmpty();
void placeOrder(const string& order);
void serveOrder();
void displayOrders();
};
CircularQueue::CircularQueue(int size) {
maxSize = size;
orders = new string[maxSize];
front = rear = -1;
}
CircularQueue::~CircularQueue() {
delete[] orders;
}
bool CircularQueue::isFull() {
return (rear + 1) % maxSize == front; // Check if the queue is full
}
bool CircularQueue::isEmpty() {
return front == -1; // Check if the queue is empty
}
void CircularQueue::placeOrder(const string& order) {
if (isFull()) {
cout << "Order queue is full! Cannot place more orders." << endl;
return;
}
if (isEmpty()) {
front = rear = 0; // Initialize front and rear if empty
} else {
rear = (rear + 1) % maxSize; // Circular increment
}
orders[rear] = order; // Place the order
cout << "Order placed: " << order << endl;
}
void CircularQueue::serveOrder() {
if (isEmpty()) {
cout << "No orders to serve!" << endl;
return;
}
cout << "Serving order: " << orders[front] << endl;
if (front == rear) {
front = rear = -1; // Reset if the queue becomes empty
} else {
front = (front + 1) % maxSize; // Circular increment
}
}
void CircularQueue::displayOrders() {
if (isEmpty()) {
cout << "No orders in the queue!" << endl;
return;
}
cout << "Current orders in the queue: ";
int i = front;
while (true) {
cout << orders[i] << " ";
if (i == rear) break; // Stop if we've reached the rear
i = (i + 1) % maxSize; // Circular increment
}
cout << endl;
}
int main() {
int maxOrders;
cout << "Enter the maximum number of orders: ";
cin >> maxOrders;
CircularQueue pizzaParlor(maxOrders);
int choice;
string order;
do {
cout << "\n__PIZZA PARLOR__" << endl;
cout << "1. Place Order" << endl;
cout << "2. Serve Order" << endl;
cout << "3. Display Orders" << endl;
cout << "4. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter the pizza order: ";
cin.ignore(); // To ignore the newline character left by cin
getline(cin, order); // Get the entire line for the order
pizzaParlor.placeOrder(order);
break;
case 2:
pizzaParlor.serveOrder();
break;
case 3:
pizzaParlor.displayOrders();
break;
case 4:
cout << "Exiting..." << endl;
break;
default:
cout << "Invalid choice! Please try again." << endl;
break;
}
} while (choice != 4);
return 0;
}



//output:
/*Enter the maximum number of orders: 2
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 1
Enter the pizza order: 01
Order placed: 01
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 1
Enter the pizza order: 02
Order placed: 02
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 3
Current orders in the queue: 01 02
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 2
Serving order: 01
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 2
Serving order: 02
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 3
No orders in the queue!
__PIZZA PARLOR__
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 4
Exiting*/
