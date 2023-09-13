#include <iostream>

#include "quetype.h"

template<class T>
quetype<T>::quetype()
{
    front = -1;
    rear = -1;
}

template<class T>
void quetype<T>::makeEmpty()
{
    front = -1;
    rear = -1;
}

template<class T>
bool quetype<T>::isEmpty()
{
    return (rear == -1 && front == -1);
}

template<class T>
bool quetype<T>::isFull()
{
    return (front == (rear+1)%max_size);
}

template<class T>
void quetype<T>::Enqueue(T item)
{
        if(isEmpty())
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = (rear+1)%max_size;
        }
        data[rear] = item;
}

template<class T>
void quetype<T>::Dequeue()
{
    if(rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front = (front+1)%max_size;
    }
}

template<class T>
T quetype<T>::Front()
{
    return data[front];
}
