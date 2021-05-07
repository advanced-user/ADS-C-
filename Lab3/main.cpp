#include <iostream>
#include <vector>

template <typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T item);
    void swap(int index1, int index2);
    bool isEmpty();
    void printList();
    void HeapSort();
    int getSize(){ return size;}

private:
    std::vector<T> list;
    int size;
};

template<typename T>
List<T>::List()
{
    size = 0;
}

template<typename T>
List<T>::~List() = default;

template<typename T>
void List<T>::push_back(T item)
{
    list.push_back(item);
    for(int i = list.size() - 1; i > 0 && list[(i-1) / 2] > list[i]; i = (i - 1) / 2)
    {
        swap(i, (i-1) / 2);
    }
    size++;
}

template<typename T>
void List<T>::swap(int index1, int index2)
{
    T t = list[index1];
    list[index1] = list[index2];
    list[index2] = t;
}

template<typename T>
bool List<T>::isEmpty() {
    if(size = 0)
        return true;
    return false;
}

template<typename T>
void List<T>::printList()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    List<int> list;

    list.push_back(5);
    list.push_back(3);
    list.push_back(10);
    list.push_back(12);
    list.push_back(9);
    list.push_back(7);
    list.push_back(20);
    list.push_back(27);
    list.push_back(25);
    list.push_back(40);

    list.printList();

    return 0;
}
