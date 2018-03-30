#ifndef SINGLETON_H
#define SINGLETON_H
#include <cstdlib>
#include <utility>      // std::forward
template<class Type>
class Singleton
{
public:

    template <typename... Args>
    static Type &GetInstance(Args&&... args)
    {
        if(nullptr == ClassInstance){
            if(nullptr == ClassInstance){
                ClassInstance = (Type*)malloc(sizeof(Type));
                new (ClassInstance) Type(std::forward<Args>(args)...);
            }
        }
        return *ClassInstance;
    }

protected:
    Singleton(void) = default;

    Singleton(Singleton& single) = delete;

    Singleton(Singleton&& single) = delete;

    ~Singleton(void){
        ClassInstance->~Type();
    }
private:
    static Type* ClassInstance;
};

template <class Type>
Type* Singleton<Type>::ClassInstance = nullptr;
#endif // SINGLETON_H
