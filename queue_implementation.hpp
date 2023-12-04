//default constructor
template <typename T>
Queue<T>::Queue()
{
	ptr = nullptr;
	m_size = 0;
	cap = 0;
	first = 0;
	last = 1;
	
}

//destructor
template <typename T>
Queue<T>::~Queue()
{
		m_size = 0;
		cap = 0;
		first = 0;
		last = 0;
	if(ptr) {
		delete[] ptr;
		ptr = nullptr;
	}
}

//checking if queue is empty
template <typename T>
bool Queue<T>::isEmpty()
{
		return  m_size == 0;
}

//pushing elements into queue
template <typename T>
void Queue<T>::enqueue(T elem)
{
    if(!ptr)
    {
        cap = 2;
        ptr = new T[cap];
    }
    if (last == cap)
    {
        // Replace the elements of queue one by one
        if (first >= cap / 2)
        {
            for (size_t i = first; i < last - 1; ++i)
            {
                ptr[i - first] = ptr[i];
            }
        }
        // Allocate a new memory
        else
        {
           cap = cap * 2;
            T* tmp = new T[cap];
                for (size_t i = first; i < last - 1; ++i)
                {
                    tmp[i - first] = ptr[i];
                }
                delete [] ptr;
                ptr = tmp;
        }
        last =  last - first;
        first = 0;
    }
    ptr[last - 1] = elem;
    last++;
    m_size++;
//	std::cout << "cap is " << cap << " last is: " <<  last << " first is: " << first << " size is " << m_size <<  std::endl;
}


//poping elemet from queue
template <typename T>
void Queue<T>::dequeue()
{
		if(m_size) {
				first++;
				m_size--;
				return;
		} std::cout << "unvalid reference" << std::endl;
}

template <typename T>
void Queue<T>::pr()
{
		for(int i = 0; i < cap; ++i)
		{
			std::cout << ptr[i] << " ";
		}
		std::cout << std::endl;
}

//function to print all elements of the queue
template <typename T>
void Queue<T>::print()
{
		for(int i = first; i < first + m_size; ++i)
		{
			std::cout << ptr[i] << " ";
		}
		std::cout << std::endl;
}

//returns first element of the queue
template <typename T>
T& Queue<T>::front()
{
	return ptr[first];
}


//returns the last element of the queue
template <typename T>
T& Queue<T>::rear()
{
		return  ptr[last - 2];
}

//returns size of the queue
template <typename T>
size_t Queue<T>::size()
{
		return m_size;
}

//copy constructor
template <typename T>
Queue<T>::Queue(const Queue<T>& obj)
{

	/*	
	if (ptr != obj.ptr) {
		m_size = obj.m_size;
		cap = obj.cap;
		first = obj.first;
		ptr = new T[obj.cap];

		for (size_t i = first; i < first + m_size; ++i) {
				ptr[i - first] = obj.ptr[i];
		}
	}
	*/

			cap = obj.cap;
			m_size = obj.m_size;
			first = 0;
			last = obj.last - obj.first;
			ptr = nullptr;
			if(obj.ptr)
			{	
					ptr = new T[cap];
					for(size_t i = obj.first, j = 0; j < m_size; ++i, ++j)
				{
				//	std::cout << obj.ptr[i] << "-";
						ptr[j] = obj.ptr[i];
				//		std::cout << ptr[j] << " ";
				}
			}
			
}

//move constructor
template <typename T>
Queue<T>::Queue(Queue<T>&& obj)
{
		cap = obj.cap;
		m_size = obj.m_size;
		first = obj.first;
		last = obj.last;
		ptr = obj.ptr;
		
		if(obj.ptr)
		{
				delete[] obj.ptr;
		}
		
			obj.ptr = nullptr;
			obj.cap = 0;
			obj.m_size = 0;
			obj.first = 0;
			obj.last = 0;
}

//copy assignment
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& obj)
{
	if(this != &obj){
		
			if(ptr)
			{
				delete[] ptr;
			}

			cap = obj.cap;
			m_size = obj.m_size;
			first = 0;
			last = obj.last - obj.first;
			ptr = new T[cap];

			if (obj.ptr)
			{

				for(int i = obj.first; i < obj.last - 1; ++i)
				{
						ptr[i - obj.first] = obj.ptr[i]; 
				}
							
			}
	}
			return *this;
}

//move assignment
template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& obj)
{
	if(ptr != obj.ptr) 
	{
			if(ptr) 
			{
					delete[] ptr;
			}
			cap = obj.cap;
			m_size = obj.m_size;
			first = obj.first;
			last = obj.last;
			ptr = obj.ptr;

			obj.ptr = nullptr;
			obj.cap = 0;
			obj.m_size = 0;
			obj.first = 0;
			obj.last = 0;
	}
	return *this;
}
