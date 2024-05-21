#include <iostream>
#include <string>
#include <initializer_list>
#include <unordered_map>
#include <stdexcept>
#include <msclr/marshal_cppstd.h> // для использования msclr::interop::marshal_as<System::String^>
#include <vcclr.h> // для работы с указателями на управляемые объекты .NET





template<typename T>
class MyArray {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    MyArray();
    MyArray(std::initializer_list<T> initList);
    ~MyArray();
    MyArray(const MyArray& other);
    System::String^ GetAllValuesAsString();
    System::String^ GetAllValuesAsASCIIString();
    MyArray& operator=(const MyArray& other);
    size_t getSize() const;
    size_t getCapacity() const;
    void reserve(size_t newCapacity);
    void push_back(const T& value);
    void insert(size_t index, const T& value);
    void removeMostCommon();
    void replaceOnesWithFive();
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    MyArray(std::vector<int> list);
};

#include "MyArray.inl" // Включаем файл с реализацией методов
