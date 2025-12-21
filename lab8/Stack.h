#pragma once
#include <stdexcept>
template <typename T>
class Stack {


public:
    Stack(int cap = 10): capacity(cap), topIndex(0){
        data = new T[capacity];
    }
    Stack(const Stack& other): capacity(other.capacity), topIndex(other.topIndex){
        data = new T[capacity];
        for (int i = 0; i < topIndex; i++){
            data[i] = other.data[i];
        }
    }
    ~Stack(){
        delete[] data;
    }

    Stack& operator=(const Stack& other){
        if (this != &other){
            delete[] data;
            capacity = other. capacity;
            topIndex = other.topIndex;
            data = new T[capacity];
            for (int i = 0;i < topIndex; i++){
                data[i] = other.data[i];
            } 
        }
        return *this;
    }
    Stack& operator<<(const T& value){
        if (topIndex == capacity){
            resize(capacity * 2);
        }
        data[topIndex++] = value;
        return *this;
    } 
    Stack& operator>>(T& value){
        if (topIndex == 0){
            throw std::runtime_error("Stack is empty");
        }
        value = data[--topIndex];
        return *this;
    }       

    T operator[](int index) const{
        if (index<0 or index>=topIndex){
            throw std::out_of_range("wrong index");
        }
        return data[index];
    }

    bool operator==(const Stack& other) const{
        if (topIndex != other.topIndex){
            return false;
        }
        for (int i = 0; i < topIndex; i++){
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }
    bool operator<(const Stack& other) const{
        if (topIndex > other.topIndex){
            return false;
        }
        return true;
    }

    bool empty() const{
       if (topIndex == 0)return true;
       return false; 
    }
    int size() const{
        return topIndex;
    }
     
    private:
    T* data;
    int capacity;
    int topIndex;
    void resize(int newCapacity){
        T* newdata = new T[newCapacity];
        for (int i = 0; i < topIndex; i++){
            newdata[i]=data[i];
        }
        delete[] data;
        data = newdata;
        capacity = newCapacity;
     }
   

};
