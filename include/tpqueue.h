// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct QItem {
        T data;
        QItem* next;
        QItem* prev;
    };
    QItem* head, * tail;
    TPQueue::QItem* create(const T& data) {
        QItem* item = new QItem;
        item->data = data;
        item->next = nullptr;
        item->prev = nullptr;
        return item;
    }
    T pop() {
        QItem* temp = head;
        T result = temp->data;
        head = head->next;
        delete temp;
        return result;
    }
    void push(const T& data) {
        QItem * temp = head;
        QItem * item = create(data);
        while (temp && temp -> data.prior >= data.prior)
            temp = temp -> next;
        if (!temp && head) {
            tail -> next = item;
            tail -> next -> prev = tail;
            tail = item;
        } else if (!temp && !head) {
            head = tail = item;
        } else if (!temp -> prev) {
            temp -> prev = item;
            item -> next = temp;
            head = item;
        } else {
            temp -> prev -> next = item;
            item -> prev = temp -> prev;
            item -> next = temp;
            temp -> prev = item;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
