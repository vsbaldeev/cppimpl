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
