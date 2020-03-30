#ifndef DEEPPTR_H
#define DEEPPTR_H
template <class T>
class DeepPtr{
private:
    T* t;
public:
    DeepPtr(T* = 0);
    DeepPtr(const DeepPtr&);
    ~DeepPtr();
    DeepPtr& operator=(const DeepPtr&);
    T* operator->() const;
    T& operator*() const;
    bool operator==(const DeepPtr&) const;
    bool operator!=(const DeepPtr&) const;
};


template<class T>
DeepPtr<T>::DeepPtr(T* q): t(q){}
template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& dp): t(dp.t!=0?dp.t->clone():0){
    int i;
}
template<class T>
DeepPtr<T>::~DeepPtr(){
    if(t) delete t;
}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& dp){
    if(this!=&dp){
        if(t) delete t; //distruzione polimorfa implementata in T
        if(dp.t!=0) t=(dp.t)->clone();
        else t=0;
    }
    return *this;
}
template<class T>
T* DeepPtr<T>::operator->() const{
    return t;
}
template<class T>
T& DeepPtr<T>::operator*() const{
    return *t;
}
template<class T>
bool DeepPtr<T>::operator==(const DeepPtr& p) const{
    return t == p.t;
}
template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr& p) const{
    return t != p.t;
}


#endif // DEEPPTR_H
