#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
public:
    List(int);
    ~List();

    int getSize();
    int getValueIndex(T);

    void insertValue(int, T);
    void deleteValue(int);
    void setValue(int, T);
    T getValue(int);

private:
    int capacity;
    int size;
    T *values;
};


template <typename T>
List<T>::List(int cap)
{
    capacity = cap;
    size = 0;
    values = new T[capacity];
}

template <typename T>
List<T>::~List() {}

template <typename T>
int List<T>::getSize()
{
    return size;
}

template <typename T>
int List<T>::getValueIndex(T t)
{
    for (int i = 0; i < size; i++)
    {
        if (t < values[i])
        {
            return i;
        }
    }

    return size;
}

template <typename T>
void List<T>::insertValue(int index, T t)
{
    if (index >= size)
    {
        values[size] = t;
    }
    else
    {
        int j = size;
        while (j > index)
        {
            values[j] = values[j - 1];
            j--;
        }
        values[index] = t;
    }
    size++;
}

template <typename T>
void List<T>::deleteValue(int index)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    int i = index;
    for (; i + 1 < size; i++)
    {
        values[i] = values[i + 1];
    }
    size--;
}

template <typename T>
void List<T>::setValue(int index, T t)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    values[index] = t;
}

template <typename T>
T List<T>::getValue(int index)
{
    if (index < 0 || index >= size)
    {
        return T(0);
    }
    return values[index];
}

#endif /* LIST_H */