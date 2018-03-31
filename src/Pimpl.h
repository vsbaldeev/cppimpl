#ifndef CPPIMPL_PIMPL_H
#define CPPIMPL_PIMPL_H

#include <memory>

template <typename T>
class Pimpl {
public:
    explicit Pimpl(T* ptr) : ptr_(ptr) {}
    explicit Pimpl(std::unique_ptr<T>&& ptr) : ptr_(std::move(ptr)) {}

    T* operator->() {
        return ptr_.get();
    }

    const T* operator->() const {
        return ptr_.get();
    }

private:
    std::unique_ptr<T> ptr_;
};

#endif //CPPIMPL_PIMPL_H
