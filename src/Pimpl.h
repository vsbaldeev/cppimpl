#ifndef CPPIMPL_PIMPL_H
#define CPPIMPL_PIMPL_H

#include <memory>

template <typename T>
class Pimpl {
public:
    explicit Pimpl(T* ptr) : ptr_(ptr) {}

    explicit Pimpl(std::unique_ptr<T>&& ptr) : ptr_(std::move(ptr)) {}

    Pimpl(const Pimpl& other) = delete;

    Pimpl(Pimpl&& other) {
        if (this != &other) {
            ptr_ = std::move(other.ptr_);
        }
    }

    Pimpl& operator=(const Pimpl& other) = delete;

    Pimpl& operator=(Pimpl&& other) {
        if (this != &other) {
            ptr_ = std::move(other.ptr_);
        }

        return *this;
    }

    T* operator->() {
        return ptr_.get();
    }

    const T* operator->() const {
        return ptr_.get();
    }

    T& operator*() {
        return *ptr_;
    }

    const T& operator*() const {
        return *ptr_;
    };

private:
    std::unique_ptr<T> ptr_;
};

#endif //CPPIMPL_PIMPL_H
