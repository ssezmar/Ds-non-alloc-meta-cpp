template<typename T>
MyStack<T>::MyStack() : data(nullptr), size(0), capacity(0) {}

template<typename T>
MyStack<T>::MyStack(std::initializer_list<T> initList) : MyStack() {
    reserve(initList.size());
    for (const auto& element : initList) {
        push(element);
    }
}

template<typename T>
MyStack<T>::~MyStack() {
    delete[] data;
}

template<typename T>
MyStack<T>::MyStack(const MyStack& other) : data(nullptr), size(0), capacity(0) {
    reserve(other.size);
    for (size_t i = 0; i < other.size; ++i) {
        push(other.data[i]);
    }
}

template<typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;

        reserve(other.size);
        for (size_t i = 0; i < other.size; ++i) {
            push(other.data[i]);
        }
    }
    return *this;
}

template<typename T>
System::String^ MyStack<T>::GetAllValuesAsASCIIString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += static_cast<char>(data[i]);
        result += " -> ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

//template<>
//MyStack<char>& MyStack<char>::operator=(const MyStack<int>& other) {
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
//MyStack<int>& MyStack<int>::operator=(const MyStack<char>& other) {
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
size_t MyStack<T>::getSize() const {
    return size;
}

template<typename T>
size_t MyStack<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void MyStack<T>::reserve(size_t newCapacity) {
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
void MyStack<T>::push(const T& value) {
    if (size >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void MyStack<T>::pop() {
    if (size > 0) {
        --size;
    }
}

template<typename T>
const T& MyStack<T>::top() const {
    if (size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return data[size - 1];
}

template<typename T>
T& MyStack<T>::top() {
    return const_cast<T&>(static_cast<const MyStack&>(*this).top());
}

template<typename T>
void MyStack<T>::removeMostCommon() {
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
System::String^ MyStack<T>::GetAllValuesAsString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += std::to_string(data[i]) + " -> ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

template<typename T>
void MyStack<T>::replaceOnesWithFive() {
    if constexpr (std::is_same_v<T, int>) {
        if (size > 0 && data[size - 1] == 1) {
            data[size - 1] = 5;
        }
    }
}

template<typename T>
std::vector<int> MyStack<T>::GetAllValuesAsVector() const {
    std::vector<int> result;
    for (size_t i = 0; i < size; ++i) {
        result.push_back(static_cast<int>(data[i]));
    }
    return result;
}

template<typename T>
MyStack<T>::MyStack(const std::vector<int>& other) : data(nullptr), size(0), capacity(0) {
    reserve(other.size());
    for (size_t i = 0; i < other.size(); ++i) {
        push(other[i]);
    }
}
