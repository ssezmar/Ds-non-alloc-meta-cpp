#pragma once

#include <initializer_list>
#include <stdexcept>
#include <msclr/marshal_cppstd.h>
#include <unordered_map>

template<typename T>
class MyVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    MyVector();
    MyVector(std::initializer_list<T> initList);
    ~MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    System::String^ GetAllValuesAsASCIIString();
    //MyVector<char>& operator=(const MyVector<int>& other);
    //MyVector<int>& operator=(const MyVector<char>& other);
    size_t getSize() const;
    size_t getCapacity() const;
    void reserve(size_t newCapacity);
    void push_back(const T& value);
    void insert(size_t index, const T& value);
    void replaceOnesWithFive();
    void removeMostCommon();
    System::String^ GetAllValuesAsString();
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    MyVector(std::vector<int> list);
};

#include "MyVector.inl"
