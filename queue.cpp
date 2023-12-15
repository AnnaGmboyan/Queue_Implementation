#include "queue_prototypes.hpp"

int main()
{
		
		Queue<int>  q;
		
		//pushing element into queue
		std::cout << "Pushing elements into queue: ";
		q.enqueue(9);
		q.enqueue(2);
		q.enqueue(5);
		q.enqueue(4);
		q.enqueue(7);
		q.print();
		

		//checking if the queue is empty
		if(q.isEmpty()) {
				std::cout << "The queue is empty" << std::endl;
		} else {
				std::cout << "The queue is not empty" << std::endl;
				
		}

		//printing elements of the queue
		std::cout << "Elemets of the queue: ";
		q.print();
	

		//poping the last element
		std::cout  << "Before poping the last elemet: ";
		q.print();
		std::cout  << "After poping the last elemet: ";
		q.dequeue();
		q.print();

		//front()
		std::cout << "First element of the queue: " << q.front() << std::endl;
		std::cout << "Changing the first elemet's value into 10: " << std::endl; 
		q.front() = 10;
		std::cout << "Elemets of the queue: ";
		q.print();
		
		//rear()
		std::cout << "Last element of the queue: " << q.rear() << std::endl;
		std::cout << "Changing the last  elemet's value." << std::endl; 
		q.rear() = 3;
		std::cout << "Elemets of the queue: ";
		q.print();

		//copy constructor
	//	q.dequeue();
		Queue<int> q3(q);
		std::cout << "New constructed object with copy constructor is: ";
		q3.print();

		//printing size of the q ueue
		std::cout << "Size of the queue is:  "<< q.size() << std::endl;

		//copy assignment operator check
		Queue<int> q2;
		q2 = q;
		std::cout << "Copied queue with copy assignment operator: ";
		q2.print();
}
