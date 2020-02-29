#include<iostream>
#include <stdexcept>
#include<memory>

using namespace std;

class Computer
{
public:
    virtual void Run()=0;
    virtual void Stop()=0;
    virtual ~Computer(){};
};

class Laptop :public Computer
{
public:
    void Run()override{mHibernating=false;};
    void Stop()override{mHibernating=true;};
    virtual ~Laptop() {};
private:
    bool mHibernating;
};

class Desktop:public Computer
{
public:
    void Run()override{mOn=true;};
    void Stop()override{mOn=false;};
    virtual ~Desktop(){};
private:
    bool mOn;
};

class ComputerFactory
{
public:
    static Computer *NewComputer(const std::string &description)
    {
        if(description == "laptop")
                   return new Laptop;
               if(description == "desktop")
                   return new Desktop;
               return nullptr;
    }
};

int main()
{
    std::string str="laptop";
    ComputerFactory::NewComputer(str);
}
