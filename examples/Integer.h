#ifndef CPPIMPL_DATABASEMANAGER_H
#define CPPIMPL_DATABASEMANAGER_H

#include "src/Pimpl.h"

class Integer {
public:
    explicit Integer(int value);
    ~Integer();
    Integer(Integer&& other);
    Integer& operator=(const Integer& other);


    int value() const;
    void setValue(int value);

private:
    class Impl;
    Pimpl<Impl> impl_;
};


#endif //CPPIMPL_DATABASEMANAGER_H
