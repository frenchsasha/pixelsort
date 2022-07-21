#include <opencv2/opencv.hpp>


#include <iostream>

using namespace cv;

struct data {
    int lum;
    Vec4b ptr;
};


struct node {
    data data;
    node* next;
};

class MyLinkedList {
public:
    node* head, * tail;

public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    ~MyLinkedList() {

    }

    void add_front(int lum, Vec4b ptr) {
        node* tmp = new node;
        tmp->data.lum = lum;
        tmp->data.ptr = ptr;
        tmp->next = head;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            head = tmp;
        }
    }

    void add_back(int lum, Vec4b ptr) {
        node* tmp = new node;
        tmp->data.lum = lum;
        tmp->data.ptr = ptr;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void print() {
        node* iter = head;
        while (iter != NULL) {
            std::cout << iter->data.lum << "_" << iter->data.ptr << "\n";
           // std::cout << iter->next << std::endl;

            iter = iter->next;
        }

    }

    void pop_node() {
        if (head) {
            node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int list_size() {
        int count = 0;
        node* iter = head;
        while (iter != NULL) {
            count++;
            iter = iter->next;
        }
        return count;
    }

    node* get(int index) {
        node* iter = head;
        int count = 0;
        while (head != NULL) {
            if (count == index) {
                return iter;
            }
            iter = iter->next;
            count++;
        }
    }

    void clear() {

        while (head) {
            pop_node();
        }
    }

    void swap(node* a, node* b) {

        node tmp = *b;

        b->data = a->data;
        a->data = tmp.data;

    }

    node get_tail() {
        return *tail;
    }
};

node* get_a_tail(node* head) {
    
    while (head->next!= head && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void clear_(node* head) {

    while (head->next!=NULL) {
        
            node* tmp = head;
            head = head->next;
            delete tmp;
        
    }
}

void print_(node* head) {
    node* iter = head;
    while (iter != NULL) {
        std::cout << iter->data.lum << "_" << iter->data.ptr << "\n";
        // std::cout << iter->next << std::endl;

        iter = iter->next;
    }

}



    node* partition(node* head, node* tail, node** newHead, node** newTail){
        node* pivot = tail, *prev = NULL, *cur = head, *end = tail;
    
        while (cur != pivot && cur != NULL) {
            if (cur->data.lum < pivot->data.lum) {
                if ((*newHead) == NULL)
                    (*newHead) = cur;
                
                prev = cur;
                cur = cur->next;

            }
            else {
                if (prev)
                    prev->next = cur->next;
                node* tmp = cur->next;
                cur->next = NULL;
                end->next = cur;
                end = cur;
                cur = tmp;

            }
        }

        if ((*newHead) == NULL)
            (*newHead) = pivot;

        *newTail = end;

        return pivot;
                    
    }

    node* quickSort(node* head, node* tail) {
        if (!head || head == tail)
            return tail;

        node* newHead = NULL, * newTail = NULL;

        node* pivot = partition(head, tail, &newHead, &newTail);

        if (newHead != pivot) {
            node* tmp = newHead;
            while (tmp->next != pivot) {
                if(tmp->next!=NULL)
                    tmp = tmp->next;
            }
            
            tmp->next = NULL;
            newHead = quickSort(newHead, tmp);
                
            tmp = get_a_tail(newHead);
            tmp->next = pivot;
        }
        pivot->next = quickSort(pivot->next, newTail);

        return newHead;
    }

    void sort(node* head, node* tail) {
        quickSort(head, tail);

    }
/*
int main()
{
    MyLinkedList data;
    data.add_back(1, 4);
    data.add_back(2, 3);
    data.add_back(4, 1);
    data.add_back(1, 3);

    data.add_front(6, 9);

  //  data.print();

  //  std::cout << "swapping\n";

   // data.swap(data.get(0), data.get(2));
    
    data.print();

    std::cout << "SORTING\n";
    
    print_(quickSort(data.head, data.tail));

   // data.print();
    // std::cout << data.get(1).data.lum;

   //std::cout << data.list_size();
 //  data.pop_node();
 //  std::cout << data.list_size();
 //
 //  std::cout << data.get(1).data.lum;
 //  data.clear();
 //  data.add_node(9, 9);
 //  std::cout << data.get(0).data.lum;
 //  data.add_node(5, 5);
     //std::cout << data.tails().data.lum;



    return 0;
}
*/