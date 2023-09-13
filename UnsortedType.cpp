#include<iostream>
#include "UnsortedType.h"

template<class T>
UnsortedType<T>::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

template<class T>
bool UnsortedType<T>::isEmpty()
{
    return length == 0;
}

template<class T>
bool UnsortedType<T>::isFull()
{
    return length == max_items;
}

template<class T>
void UnsortedType<T>::makeEMpty()
{
    length = 0;
}

template<class T>
void UnsortedType<T>::Insert(T item)
{
    data[length] = item;
    length++;
}

template<class T>
void UnsortedType<T>::Delete(T item)
{
    int location = 0;
    for(int i=0;i<length;i++)
    {
        if(data[i] == item)
        {
            location = i;
            break;
        }
    }
    data[location] = data[length-1];
    length--;
}


template<class T>
int UnsortedType<T>::isLength()
{
    return length;
}

template<class T>
void UnsortedType<T>::getNextItem(T& item)
{
    currentPos++;
    item = data[currentPos];
}
template<class T>
void UnsortedType<T>::resetList()
{
    currentPos = -1;
}
template<class T>
void UnsortedType<T>::retriveValue(T& item, bool& isFound)
{
    for(int i=0;i<length;i++)
    {
        if(data[i] == item)
        {
            isFound = true;
            return;
        }
    }
}
void PrintList(UnsortedType<int> u)
{
    int temp;
    for(int i = 0 ; i<u.isLength();i++)
    {
        u.getNextItem(temp);
        cout<<temp<<endl;
    }
    u.resetList();
}
void RetriveItem(UnsortedType<int> u, int search)
{

}
