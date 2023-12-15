/*
#ifndef QUEUE_PROTOTYPES.HPP
#define QUEUE_PROTOTYPES.HPP
*/

#include <iostream>
template <typename T>
class Queue {
	private:

			T* ptr  ;
			size_t m_size;
			size_t cap;
			size_t first;
			size_t last;

	public:
			Queue();
			Queue(const Queue<T>&);
			Queue(Queue<T>&&);
			~Queue();
	
			void print();
			void allocator();
			bool isEmpty();
			void enqueue(T);
			void dequeue();
			T& front();
			T& rear();
			size_t size();	
			Queue& operator= (const Queue<T>&);
			Queue& operator= (Queue<T>&&);

};

#include "queue_implementation.hpp"

/*
#endif // QUEUE_PROTOTYPES
*/
