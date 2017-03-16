#ifndef LIST_H
#define LIST_H

#include <list>
#include <cstddef>
#include <iterator>

template <class T> class List {
private:
    std::list<T *> *objects;
    int count;
    int currentIndex;

public:
    void add(T *obj);
    T *get(int idx);
    void start();
    bool empty();
    void next();
    T *currentItem;

    List() {
        this->currentItem = NULL;
        this->currentIndex = 0;
        this->count = 0;
        this->objects = new std::list<T *>;
    }
};

template <class T>
void List<T>::add(T *obj) {
    this->objects->push_back(obj);
}

template <class T>
T *List<T>::get(int idx) {
    if (idx < this->objects->size()) {
      typename std::list<T*>::iterator it = this->objects->begin();
      std::advance(it, idx);
      return *it;
    } else {
      return NULL;
    }
}

template <class T>
void List<T>::start() {
    this->currentIndex = 0;
    if (this->objects->size() > 0) {
      this->currentItem = *this->objects->begin();
    } else {
      this->currentItem = NULL;
    }
}

template <class T>
void List<T>::next() {
    if (this->currentIndex < this->objects->size() - 1) {
      this->currentIndex++;
      typename std::list<T*>::iterator it = this->objects->begin();
      std::advance(it, this->currentIndex);
      this->currentItem = *it;
    } else {
      this->currentItem = NULL;
    }
}

template <class T>
bool List<T>::empty() {
    return !this->objects->size();
}

#endif // LIST_H