#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

template<class T>
class Container{
    friend class iteratore;
private:
    T* a;
    unsigned int c;
    unsigned int s;
    T* copy(unsigned int, unsigned int) const;
    static void destroy(T*);
public:
    Container(unsigned int=1, unsigned int=0);
    void push_back(const T&);
    //ITERATORE
    class iteratore{
            friend class Container;
    private:
            T* p;
    public:
        bool operator==(iteratore) const;
        bool operator!=(iteratore) const;
        iteratore& operator++();
        iteratore operator++(int);
    };
    iteratore erase(iteratore);
    iteratore begin() const;
    iteratore end() const;
    T& operator[](iteratore) const;
    T& operator[](int) const;
    void erase(unsigned int);
    unsigned int size() const;
};

//ZONA CONTAINER
template<class T>
Container<T>::Container(unsigned int c, unsigned int s): a(new T[c]),c(c), s(s){}

template<class T>
void Container<T>::push_back(const T& t)
{
    if(s>=c){
        c=c*2;
        T* aux = copy(s, c);
        destroy(a);
        a=aux;
    }
    a[s++]=t;
}

template<class T>
T* Container<T>::copy(unsigned int n, unsigned int d) const{
    if(n<=d && n<=s){
        T* p= new T[d];
        std::copy(a,a+n,p);
        return p;
    } else return nullptr;
}

template<class T>
void Container<T>::destroy(T* a){
    if(a) delete[] a;
}

template<class T>
unsigned int Container<T>::size() const
{
return s;
}

template<class T>
void Container<T>::erase(unsigned int n) {
    for(unsigned int i=n;i<s-1;i++){
        a[i]=a[i+1];
    }
    s--;
}

template<class T>
T& Container<T>::operator[](int i) const {
 return a[i];
}

//ZONA ITERATORI
template<class T>
bool Container<T>::iteratore::operator==(iteratore i) const {
    return p == i.p;
}
template<class T>
bool Container<T>::iteratore::operator!=(iteratore i) const {
    return p != i.p;
}
template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator++(){
    if (p) ++p;
    return *this;
}
template<class T>
typename Container<T>::iteratore Container<T>::iteratore::operator++(int){
    iteratore aux = *this;
    if (p) ++p;
    return aux;
}
template<class T>
typename Container<T>::iteratore Container<T>::erase(iteratore i){
    for(iteratore it=i;it!=this->end();it++){
        a[it]=a[it+1];
    }
    s--;
}

template<class T>
typename Container<T>::iteratore Container<T>::begin() const{
    iteratore aux;
    if(s>=1) aux.p=&a[0];
    else aux.p=nullptr;
    return aux;
}

template<class T>
typename Container<T>::iteratore Container<T>::end() const{
    iteratore aux;
    aux.p=&a[s];
    return aux;
}

template<class T>
T& Container<T>::operator[](Container<T>::iteratore it) const {
        return (*(it.p));
}



#endif // CONTAINER_H
