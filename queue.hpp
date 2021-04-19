#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data, priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  //membuat elemen baru
  ElementPtr<T> pBaru = new Element<T>;
  pBaru->data = value;
  pBaru->priority = priority;
  pBaru->next = nullptr;
  //keadaan saat queue kosong
  if(q.head==nullptr && q.tail==nullptr){
    q.head = pBaru;
    q.tail = pBaru;
  }
  //keadaan saat queue ada isi
  else{
    ElementPtr<T> pHelp = q.head;
    ElementPtr<T> pRev = nullptr;
    while(pBaru->priority <= pHelp->priority){
      if(pHelp->next==nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp->next;
    }
    //insert first
    if(pHelp==q.head && pBaru->priority > pHelp->priority){
      pBaru->next = pHelp;
      q.head = pBaru;
    }
    //insert last
    else if(pHelp == q.head && pBaru->priority < pHelp->priority){
      pHelp->next = pBaru;
      q.tail = pBaru;
    }
    //insert di tengah
    else{
      pRev->next = pBaru;
      pBaru->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> pHapus;
  //keadaan saat queue kosong
  if(q.head == nullptr && q.tail == nullptr){
    pHapus = nullptr;
  }
  //keadaan saat queue hanya ada 1 elemen
  else if(q.head->next==nullptr){
    pHapus = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }
  //keadaan saat queue memiliki elemen >1
  else{
    pHapus = q.head;
    q.head = q.head->next;
    pHapus->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
