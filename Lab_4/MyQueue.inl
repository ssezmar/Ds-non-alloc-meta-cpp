template<typename T>
MyQueue<T>::MyQueue() : data(nullptr), frontIndex(0), rearIndex(0), size(0), capacity(0) {}

template<typename T>
MyQueue<T>::MyQueue(std::initializer_list<T> initList) : MyQueue() {
    reserve(initList.size());
    for (const auto& element : initList) {
        enqueue(element);
    }
}

template<typename T>
MyQueue<T>::~MyQueue() {
    delete[] data;
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue& other) : MyQueue() {
    reserve(other.size);
    for (size_t i = other.frontIndex; i < other.rearIndex; ++i) {
        enqueue(other.data[i]);
    }
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        frontIndex = 0;
        rearIndex = 0;
        size = 0;
        capacity = 0;

        reserve(other.size);
        for (size_t i = other.frontIndex; i < other.rearIndex; ++i) {
            enqueue(other.data[i]);
        }
    }
    return *this;
}

template<typename T>
System::String^ MyQueue<T>::GetAllValuesAsASCIIString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += static_cast<char>(data[i]);
        result += " -> ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

//template<>
//MyQueue<int>& MyQueue<int>::operator=(const MyQueue<char>& other) {
//    delete[] data;
//    data = nullptr;
//    size = 0;
//    frontIndex = 0;
//    rearIndex = 0;
//    capacity = 0;
//
//    reserve(other.getSize() const;
//    );
//
//    for (size_t i = other.frontIndex; i < other.rearIndex; ++i) {
//        enqueue(static_cast<int>(other.[i]));
//    }
//
//    return *this;
//}
//
//template<>
//MyQueue<char>& MyQueue<char>::operator=(const MyQueue<int>& other) {
//    delete[] data;
//    data = nullptr;
//    size = 0;
//    frontIndex = 0;
//    rearIndex = 0;
//    capacity = 0;
//
//    reserve(other.size);
//
//    for (size_t i = other.frontIndex; i < other.rearIndex; ++i) {
//        enqueue(static_cast<char>(other.data[i]));
//    }
//
//    return *this;
//}

template<typename T>
size_t MyQueue<T>::getSize() const {
    return size;
}

template<typename T>
size_t MyQueue<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void MyQueue<T>::reserve(size_t newCapacity) {
    if (newCapacity > capacity) {
        T* newData = new T[newCapacity];
        size_t j = 0;
        for (size_t i = frontIndex; i < rearIndex; ++i) {
            newData[j++] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        frontIndex = 0;
        rearIndex = size;
        capacity = newCapacity;
    }
}

template<typename T>
void MyQueue<T>::enqueue(const T& value) {
    if (size >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[rearIndex] = value;
    ++size;
    rearIndex = (rearIndex + 1) % capacity;
}

template<typename T>
void MyQueue<T>::dequeue() {
    if (size > 0) {
        frontIndex = (frontIndex + 1) % capacity;
        --size;
    }
}

template<typename T>
const T& MyQueue<T>::front() const {
    if (size == 0) {
        throw std::out_of_range("Queue is empty");
    }
    return data[frontIndex];
}

template<typename T>
T& MyQueue<T>::front() {
    return const_cast<T&>(static_cast<const MyQueue&>(*this).front());
}

template<typename T>
void MyQueue<T>::removeMostCommon() {
    if (size == 0)
        return;

    std::unordered_map<T, size_t> counts;
    size_t current = frontIndex;
    for (size_t i = 0; i < size; ++i) {
        counts[data[current]]++;
        current = (current + 1) % capacity;
    }

    T mostCommon;
    size_t maxCount = 0;
    for (const auto& pair : counts) {
        if (pair.second > maxCount) {
            mostCommon = pair.first;
            maxCount = pair.second;
        }
    }

    while (size > 0 && data[(rearIndex - 1 + capacity) % capacity] == mostCommon) {
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        --size;
    }
}


template<typename T>
System::String^ MyQueue<T>::GetAllValuesAsString() {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += std::to_string(data[i]) + " -> ";
    }
    return msclr::interop::marshal_as<System::String^>(result);
}

template<typename T>
void MyQueue<T>::replaceOnesWithFive() {
    if constexpr (std::is_same_v<T, int>) {
        if (size > 0 && data[frontIndex] == 1) {
            data[frontIndex] = 5;
        }
    }
}

template<typename T>
std::vector<int> MyQueue<T>::GetAllValuesAsVector() const {
    std::vector<int> result;
    for (size_t i = 0; i < size; ++i) {
        result.push_back(static_cast<int>(data[i]));
    }
    return result;
}


template<typename T>
MyQueue<T>::MyQueue(const std::vector<int>& other) : data(nullptr), size(0), capacity(0) {
    reserve(other.size());
    for (size_t i = 0; i < other.size(); ++i) {
        enqueue(other[i]);
    }
}
