template<typename T>
MyVector<T>::MyVector() : data(nullptr), size(0), capacity(0) {}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> initList) : data(nullptr), size(0), capacity(0) {
    reserve(initList.size());
    for (const auto& element : initList) {
        push_back(element);
    }
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other) : data(nullptr), size(0), capacity(0) {
    reserve(other.size);
    for (size_t i = 0; i < other.size; ++i) {
        push_back(other.data[i]);
    }
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
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

template<typename T>
System::String^ MyVector<T>::GetAllValuesAsASCIIString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += static_cast<char>(data[i]);
        result += " | ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

//template<>
//MyVector<char>& MyVector<char>::operator=(const MyVector<int>& other) {
//    delete[] data;
//    data = new char[other.getSize()];
//    size = other.getSize();
//    capacity = other.getCapacity();
//    for (size_t i = 0; i < size; ++i) {
//        data[i] = static_cast<char>(other[i]);
//    }
//    return *this;
//}
//
//template<>
//MyVector<int>& MyVector<int>::operator=(const MyVector<char>& other) {
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
size_t MyVector<T>::getSize() const {
    return size;
}

template<typename T>
size_t MyVector<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void MyVector<T>::reserve(size_t newCapacity) {
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
void MyVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void MyVector<T>::insert(size_t index, const T& value) {
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
void MyVector<T>::replaceOnesWithFive() {
    if constexpr (std::is_same_v<T, int>) {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == 1) {
                data[i] = 5;
            }
        }
    }
}

template<typename T>
void MyVector<T>::removeMostCommon() {
    if (size == 0)
        return;

    std::unordered_map<T, size_t> counts;
    for (size_t i = 0; i < size; ++i) {
        counts[data[i]]++;
    }

    T mostCommon;
    size_t maxCount = 0;
    for (const auto& pair : counts) {
        if (pair.second > maxCount) {
            mostCommon = pair.first;
            maxCount = pair.second;
        }
    }

    size_t writeIndex = 0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != mostCommon) {
            data[writeIndex++] = data[i];
        }
    }
    size = writeIndex;
}



template<typename T>
System::String^ MyVector<T>::GetAllValuesAsString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += std::to_string(data[i]) + " | ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
T& MyVector<T>::operator[](size_t index) {
    return const_cast<T&>(static_cast<const MyVector&>(*this)[index]);
}
template<typename T>

MyVector<T>::MyVector(std::vector<int> list) : size(list.size()), capacity(list.size()) {
    data = new T[list.size()];
    for (size_t i = 0; i < list.size(); ++i) {
        data[i] = list[i];
    }
}
