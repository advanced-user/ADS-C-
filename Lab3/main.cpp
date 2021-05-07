#include <iostream>
#include <vector>

template <typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T item);
    void swap(int index1, int index2, std::vector<T> &list);
    bool isEmpty();
    void printList();
    void HeapSort();
    int getSize(){ return size;}

private:
    std::vector<T> list;
    std::vector<T> sortedList;
    int size;

    void printList(const std::vector<T> &list);
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
        swap(i, (i-1) / 2, list);
    }
    size++;
}

template<typename T>
void List<T>::swap(int index1, int index2, std::vector<T> &list)
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
    if(list.size() > sortedList.size())
        printList(list);
    else
        printList(sortedList);
}

template<typename T>
void List<T>::printList(const std::vector<T> &list)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::HeapSort()
{
    std::vector<T> a = list;

    int n = a.size();
    sortedList.clear();

    for(int i = 0; i < n; i++)
    {
        sortedList.push_back(a[0]);
        a[0] = a[a.size() - 1];
        a.erase(a.begin() + a.size() - 1);

        int j = 0;
        int k = 0;
        while(true)
        {
            if(2*j+1 < n-i-1 && a[2*j + 1] < a[k])
                k = 2*j + 1;
            if(2*j+2 < n-i-1 && a[2*j + 2] < a[k])
                k = 2*j + 2;
            if(k == j)
                break;
            swap(j, k, a);

            j = k;
        }
    }
}


template <typename T>
class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    int getSize() { return size;}
    bool isEmpty();
    void printQueue();
    void enqueue (T data_priority, T data_value);
    void dequeueMax();

private:
    template<typename T>
    struct Node{
        T data_priority;
        T data_value;

        Node(T data_priority, T data_value){
            this->data_priority = data_priority;
            this->data_value = data_value;
        }
    };

    int size;
    std::vector<Node<T>> list;

    void swap(int index1, int index2, std::vector<Node<T>> &list);
};

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    size = 0;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {}

template<typename T>
bool PriorityQueue<T>::isEmpty()
{
    if(size > 0)
        return false;
    return true;
}

template<typename T>
void PriorityQueue<T>::printQueue()
{
    std::vector<Node<T>> listPriorityQueue;
    std::vector<Node<T>> a = list;
    int n = a.size();
    listPriorityQueue.clear();

    for(int i = 0; i < n; i++)
    {
        listPriorityQueue.push_back(a[0]);
        a[0] = a[a.size() - 1];
        a.erase(a.begin() + a.size() - 1);

        int j = 0;
        int k = 0;
        while(true)
        {
            if(2*j+1 < n-i-1 && a[2*j + 1].data_priority > a[k].data_priority)
                k = 2*j + 1;
            if(2*j+2 < n-i-1 && a[2*j + 2].data_priority > a[k].data_priority)
                k = 2*j + 2;
            if(k == j)
                break;
            swap(j, k, a);

            j = k;
        }
    }


    for(int i = 0; i < size; i++)
    {
        std::cout << listPriorityQueue[i].data_value << " ";
    }

    std::cout << std::endl;
}

template<typename T>
void PriorityQueue<T>::enqueue(T dataPriority, T data_value)
{
    this->list.push_back(Node<T>(dataPriority, data_value));
    for(int i = list.size() - 1; i > 0 && list[(i-1) / 2].data_priority < list[i].data_priority; i = (i - 1) / 2)
    {
        swap(i, (i-1) / 2, list);
    }
    size++;
}

template<typename T>
void PriorityQueue<T>::dequeueMax()
{
    list[0] = list[list.size() - 1];
    list.erase(list.begin() + list.size() - 1);
    size--;

    int j = 0;
    int k = 0;
    int n = list.size();
    while(true)
    {
        if(2*j+1 < n && list[2*j + 1].data_priority > list[k].data_priority)
            k = 2*j + 1;
        if(2*j+2 < n && list[2*j + 2].data_priority > list[k].data_priority)
            k = 2*j + 2;
        if(k == j)
            break;
        swap(j, k, list);

        j = k;
    }
}

template<typename T>
void PriorityQueue<T>::swap(int index1, int index2, std::vector<Node<T>> &list) {
    Node<T> t = list[index1];
    list[index1] = list[index2];
    list[index2] = t;
}


int main()
{
    List<int> list;

    list.push_back(5);
    list.push_back(3);
    list.push_back(10);
    list.push_back(40);
    list.push_back(12);
    list.push_back(9);
    list.push_back(7);
    list.push_back(20);
    list.push_back(27);
    list.push_back(25);


    list.HeapSort();
    list.printList();

    PriorityQueue<int> queue;
    queue.enqueue(5, 5);
    queue.enqueue(3, 3);
    queue.enqueue(10, 10);
    queue.enqueue(40, 40);
    queue.enqueue(12, 12);
    queue.enqueue(9, 9);
    queue.enqueue(7, 7);
    queue.enqueue(20, 20);
    queue.enqueue(27, 27);
    queue.enqueue(25, 25);

    queue.printQueue();
    queue.dequeueMax();
    queue.printQueue();

    return 0;
}
