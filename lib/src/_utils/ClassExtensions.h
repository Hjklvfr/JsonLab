#ifndef JSON_LAB_CLASSEXTENSIONS_H
#define JSON_LAB_CLASSEXTENSIONS_H

#include <string>

class Object {
    virtual std::string getClassName() {
        return {"Object"};
    }
};

template<typename Base, typename T>
bool instanceof(const T* ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

template<typename T>
inline void unused(T) {}

template<typename Base, typename T>
bool refInstanceof(const T& ptr) {
    try {
        unused(dynamic_cast<const Base&>(ptr));
        return true;
    }
    catch (str::bad_cast& e) {
        return false;
    } 
}

#endif