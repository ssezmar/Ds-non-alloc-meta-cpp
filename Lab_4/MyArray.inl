template<typename T>
MyArray<T>::MyArray() : data(nullptr), size(0), capacity(0) {}

template<typename T>
MyArray<T>::MyArray(std::initializer_list<T> initList) : data(nullptr), size(0), capacity(0) {
    reserve(initList.size());
    for (const auto& element : initList) {
        push_back(element);
    }
}

template<typename T>
MyArray<T>::~MyArray() {
    delete[] data;
}

template<typename T>
MyArray<T>::MyArray(const MyArray& other) : data(nullptr), size(0), capacity(0) {
    reserve(other.size);
    for (size_t i = 0; i < other.size; ++i) {
        push_back(other.data[i]);
    }
}

template<typename T>
System::String^ MyArray<T>::GetAllValuesAsString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += std::to_string(data[i]) + " | ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

template<typename T>
System::String^ MyArray<T>::GetAllValuesAsASCIIString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += static_cast<char>(data[i]) ;
        result += " | ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}


template<typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;

        reserve(other.size);
        for (size_t i = 0; i < other.size; ++i) {
            push_back(other.data[i]);
        }
    }
    return *this;
}

//template<>
//MyArray<char>& MyArray<char>::operator=(const MyArray<int>& other) {
//    delete[] data;
//    data = nullptr;
//    size = 0;
//    capacity = 0;
//
//    reserve(other.getSize());
//    for (size_t i = 0; i < other.getSize(); ++i) {
//        push_back(static_cast<char>(other[i]));
//    }
//
//    return *this;
//}
//
//template<>
//MyArray<int>& MyArray<int>::operator=(const MyArray<char>& other) {
//    delete[] data;
//    data = new int[other.getSize()];
//    size = other.getSize();
//    capacity = other.getCapacity();
//    for (size_t i = 0; i < size; ++i) {
//        data[i] = static_cast<int>(other[i]);
//    }
//    return *this;
//}

template<typename T>
size_t MyArray<T>::getSize() const {
    return size;
}

template<typename T>
size_t MyArray<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void MyArray<T>::reserve(size_t newCapacity) {
    if (newCapacity > capacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template<typename T>
void MyArray<T>::push_back(const T& value) {
    if (size >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void MyArray<T>::insert(size_t index, const T& value) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }

    if (size >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }

    for (size_t i = size; i > index; --i) {
        data[i] = std::move(data[i - 1]);
    }

    data[index] = value;
    ++size;
}

template<typename T>
void MyArray<T>::removeMostCommon() {
    if (size == 0)
        return;

    std::unordered_map<T, size_t> counts;
    for (size_t i = 0; i < size; ++i) {
        counts[data[i]]++;
    }

    size_t maxCount = 0;
    for (const auto& pair : counts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    }

    size_t writeIndex = 0; 
    for (size_t i = 0; i < size; ++i) {
        if (counts[data[i]] != maxCount) {
            data[writeIndex++] = data[i];
        }
    }
    size = writeIndex;
}




template<typename T>
void MyArray<T>::replaceOnesWithFive() {
    if constexpr (std::is_same_v<T, int>) {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == 1) {
                data[i] = 5;
            }
        }
    }
}

template<typename T>
const T& MyArray<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
T& MyArray<T>::operator[](size_t index) {
    return const_cast<T&>(static_cast<const MyArray&>(*this)[index]);
}

template<typename T>
MyArray<T>::MyArray(std::vector<int> list) : size(list.size()), capacity(list.size()) {
    data = new T[list.size()];
    for (size_t i = 0; i < list.size(); ++i) {
        data[i] = list[i];
    }
}
