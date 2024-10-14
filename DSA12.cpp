/*A double-ended queue (deque) is a linear list in which additions and deletions may be
made at either end. Obtain a data representation mapping a deque into a
one-dimensional array. Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque.*/




#include <iostream>
using namespace std;
const int SIZE = 10; // Define a proper size for the deque
class deque {
public:
int a[SIZE], front, rear;
deque() {
front = -1;
rear = -1;
}
void add_beg(int item);
void add_rear(int item);
void del_front();
void del_rear();
void display();
};
void deque::add_beg(int item) {
if (front == -1) { // Empty deque
front = rear = 0;
a[rear] = item;
} else if (front > 0) { // Not empty and can insert at front
front--;
a[front] = item;
} else {
cout << "\nInsertion not possible..overflow!!";
}
}
void deque::add_rear(int item) {
if (front == -1) { // Empty deque
front = rear = 0;
a[rear] = item;
} else if (rear < SIZE - 1) { // Not empty and space available
rear++;
a[rear] = item;
} else {
cout << "\nInsertion is not possible, overflow!!!";
}
}
void deque::display() {
if (front == -1) {
cout << "Deque is empty!";
return;
}
for (int i = front; i <= rear; i++) {
cout << a[i] << " ";
}
cout << endl;
}
void deque::del_front() {
if (front == -1) {
cout << "\nDeletion not possible..Deque is empty!";
return;
} else {
cout << "The deleted element is " << a[front] << endl;
if (front == rear) { // Only one element
front = rear = -1; // Reset
} else {
front++;
}
}
}
void deque::del_rear() {
if (front == -1) {
cout << "Deletion is not possible: Deque is empty";
return;
} else {
cout << "The deleted element is " << a[rear] << endl;
if (front == rear) { // Only one element
front = rear = -1; // Reset
} else {
rear--;
}
}
}
int main() {
int ch, item;
deque obj;
do {
cout << "\n__DEQUE OPERATIONS__";
cout << "\n1. Insert at beginning";
cout << "\n2. Insert at end";
cout << "\n3. Display";
cout << "\n4. Delete from front";
cout << "\n5. Delete from rear";
cout << "\n6. Exit";
cout << "\nEnter your choice: ";
cin >> ch;
switch(ch) {
case 1:
cout << "Enter the element to be inserted: ";
cin >> item;
obj.add_beg(item);
break;
case 2:
cout << "Enter the element to be inserted: ";
cin >> item;
obj.add_rear(item);
break;
case 3:
cout<<"\nInserted elements are:";
obj.display();
break;
case 4:
obj.del_front();
break;
case 5:
obj.del_rear();
break;
case 6:
cout << "Exiting..." << endl;
break;
default:
cout << "Invalid choice" << endl;
break;
}
} while (ch != 6);
return 0;
}

//output:
/*__DEQUE OPERATIONS__
1. Insert at beginning
2. Insert at end
3. Display
4. Delete from front
5. Delete from rear
6. Exit
Enter your choice: 1
Enter the element to be inserted: 10
__DEQUE OPERATIONS__
1. Insert at beginning
2. Insert at end
3. Display
4. Delete from front
5. Delete from rear
6. Exit
Enter your choice: 2
Enter the element to be inserted: 20
__DEQUE OPERATIONS__
1. Insert at beginning
2. Insert at end
3. Display
4. Delete from front
5. Delete from rear
6. Exit
Enter your choice: 3
Inserted elements are:10 20
__DEQUE OPERATIONS__
1. Insert at beginning
2. Insert at end
3. Display
4. Delete from front
5. Delete from rear
6. Exit
Enter your choice: 4
The deleted element is 10
__DEQUE OPERATIONS__
1. Insert at beginning
2. Insert at end
3. Display
4. Delete from front
5. Delete from rear
6. Exit
Enter your choice: 5
The deleted element is 20
__DEQUE OPERATIONS__
1. Insert at beginning
2. Insert at end
3. Display
4. Delete from front
5. Delete from rear
6. Exit
Enter your choice: 6
Exiting...*/
