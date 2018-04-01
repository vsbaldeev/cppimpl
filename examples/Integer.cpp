#include "Integer.h"

class Integer::Impl {
public:
    explicit Impl(int value);

    int value() const;
    void setValue(int value);

private:
    int value_;
};

Integer::Impl::Impl(int value) : value_(value) {}

Integer::~Integer() {}

Integer::Integer(Integer&& other): impl_(std::move(other.impl_)) {

}

Integer& Integer::operator=(const Integer& other) {
    if (this != &other) {
        (*impl_).value();
        impl_->setValue(other.value());
    }
    return *this;
}

int Integer::Impl::value() const {
    return value_;
}

void Integer::Impl::setValue(int value) {
    value_ = value;
}

Integer::Integer(int value) : impl_(new Impl(value)) {}

int Integer::value() const {
    return impl_->value();
}

void Integer::setValue(int value) {
    impl_->setValue(value);
}
