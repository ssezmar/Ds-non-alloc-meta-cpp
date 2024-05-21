#pragma once

#include <initializer_list>
#include <stdexcept>
#include <msclr/marshal_cppstd.h>
#include <unordered_map>

template<typename T>
class MyStack {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    MyStack();
    MyStack(std::initializer_list<T> initList);
    ~MyStack();
    MyStack(const MyStack& other);
    MyStack& operator=(const MyStack& other);
    System::String^ GetAllValuesAsASCIIString();
    //MyStack<char>& operator=(const MyStack<int>& other);
    //MyStack<int>& operator=(const MyStack<char>& other);
    size_t getSize() const;
    size_t getCapacity() const;
    void reserve(size_t newCapacity);
    void push(const T& value);
    void pop();
    const T& top() const;
    T& top();
    void removeMostCommon();
    System::String^ GetAllValuesAsString();
    void replaceOnesWithFive();
    MyStack(const std::vector<int>& vec);   
    std::vector<int> GetAllValuesAsVector() const;
};

#include "MyStack.inl"
