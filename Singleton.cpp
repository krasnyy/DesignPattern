#include <iostream>
using namespace std;


class Mutex
{

};

class Lock{
public:
    Lock(Mutex &m):mutex(m){}
    ~Lock(){}
private:
    Mutex &mutex;
};


class Singleton
{
public:
    static Singleton *GetInstance();
    int a;
    ~Singleton(){cout << "In Destructor" << endl;}
private:
    Singleton(int _a) : a(_a) { cout << "In Constructor" << endl; }

     static Mutex mutex;


     Singleton(const Singleton& );
     Singleton& operator =(const Singleton& other);
};

Mutex Singleton::mutex;

Singleton *Singleton::GetInstance()
{
    Lock lock(mutex);
    std::cout << "Get Instance" << std::endl;
    static Singleton inst(1);
    return &inst;
}

int main()
{
    Singleton* singleton = Singleton::GetInstance();
    cout << "The value of the singleton: " << singleton->a << endl;
    return 0;
}
