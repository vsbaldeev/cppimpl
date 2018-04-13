#ifndef CPPIMPL_PIMPL_H
#define CPPIMPL_PIMPL_H

#include <memory>

template <typename T, typename Pointer = std::unique_ptr<T>>
class Pimpl {
public:
    explicit Pimpl(T* ptr) noexcept(noexcept(Pointer(std::declval<T*>()))) :
            ptr_(ptr) {}

    explicit Pimpl(Pointer&& ptr) noexcept(std::is_nothrow_move_constructible<Pointer>::value) :
            ptr_(std::move(ptr)) {}

    Pimpl(const Pimpl& other) = delete;

    Pimpl(Pimpl&& other) noexcept (std::is_nothrow_move_constructible<Pointer>::value):
        ptr_(std::move(other.ptr_)) {}

    Pimpl& operator=(const Pimpl& other) = delete;

    Pimpl& operator=(Pimpl&& other) noexcept(std::is_nothrow_move_assignable<Pointer>::value) {
        if (this != &other) {
            ptr_ = std::move(other.ptr_);
        }

        return *this;
    }

    T* operator->() noexcept(noexcept(std::declval<Pointer>().get())) {
        return ptr_.get();
    }

    const T* operator->() const noexcept(noexcept(std::declval<Pointer>().get())) {
        return ptr_.get();
    }

    T& operator*() noexcept(noexcept(*std::declval<Pointer>())) {
        return *ptr_;
    }

    const T& operator*() const noexcept(noexcept(*std::declval<Pointer>())) {
        return *ptr_;
    };

private:
    Pointer ptr_;
};

#endif //CPPIMPL_PIMPL_H
