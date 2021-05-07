#include <iostream>
#include <vector>

template <typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T item);
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

}

template<typename T>
bool List<T>::isEmpty() {
    if(size = 0)
        return true;
    return false;
}


int main() {

    return 0;
}
