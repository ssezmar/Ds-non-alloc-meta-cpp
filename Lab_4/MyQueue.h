#pragma once

#include <initializer_list>
#include <stdexcept>
#include <msclr/marshal_cppstd.h>
#include <unordered_map>

template<typename T>
class MyQueue {
private:
    T* data;
    size_t frontIndex;
    size_t rearIndex;
    size_t size;
    size_t capacity;

public:
    MyQueue();
    MyQueue(std::initializer_list<T> initList);
    ~MyQueue();
    MyQueue(const MyQueue& other);
    MyQueue& operator=(const MyQueue& other);
    System::String^ GetAllValuesAsASCIIString();
    //MyQueue<char>& operator=(const MyQueue<int>& other);
    //MyQueue<int>& operator=(const MyQueue<char>& other);
    size_t getSize() const;
    size_t getCapacity() const;
    void reserve(size_t newCapacity);
    void enqueue(const T& value);
    void dequeue();
    const T& front() const;
    T& front();
    void removeMostCommon();
    System::String^ GetAllValuesAsString();
    void replaceOnesWithFive();
    MyQueue(const std::vector<int>& vec);
    std::vector<int> GetAllValuesAsVector() const;
};

#include "MyQueue.inl"
