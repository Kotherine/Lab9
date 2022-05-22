// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

#include <queue>
#include <mutex>
#include <iostream>
#include <string>
//класс, выполняющий все методы класса std::queue
//Реализован для упрощения работы (не требуется следить за мьютексами)
class Queue{
 public:
  //Добавляет элемент в конец queue.
  void push(std::string& str){
    std::scoped_lock<std::mutex> lk{mtx};
    queue_.push(str);
  }
  //Возвращает ссылку на первый элемент в начале queue.
  std::string front(){
    std::scoped_lock<std::mutex> lk{mtx};
    return queue_.front();
  }
  //Удаляет элемент из начала queue.
  void pop(){
    std::scoped_lock<std::mutex> lk{mtx};
    queue_.pop();
  }
  //Проверяет, является ли queue пустым.
  bool empty(){
    std::scoped_lock<std::mutex> lk{mtx};
    return queue_.empty() ? 1 : 0;
  }

 private:
  std::mutex mtx;
  std::queue<std::string> queue_;
};

#endif  // INCLUDE_QUEUE_HPP_
