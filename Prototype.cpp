#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;


class Record
{
public:
    virtual  ~Record(){};
    virtual void print()=0;
    virtual unique_ptr<Record>clone()=0;
};

class CarRecord:public Record
{
private:
    string m_carName;
    int m_ID;
public:
    CarRecord(string carName,int ID):m_carName(carName),m_ID(ID)
    {}
    void print() override
     {
          cout << "Bike Record" << endl
             << "Name  : " << m_bikeName << endl
             << "Number: " << m_ID << endl << endl;
      }

    unique_ptr<Record>clone()override
    {
        return make_unique<CarRecord>(*this);
    }
};

class PersonRecord : public Record
{
private:
    string m_personName;
    int m_age;

public:
    PersonRecord(string personName, int age) : m_personName(personName), m_age(age)
    {
    }

    void print() override
    {
        cout << "Person Record" << endl
            << "Name : " << m_personName << endl
            << "Age  : " << m_age << endl << endl;
    }

    unique_ptr<Record> clone() override
    {
        return make_unique<PersonRecord>(*this);
    }
};



enum RecordType
{
    CAR,
    BIKE,
    PERSON
};


class RecordFactory
{
private:
    unordered_map<RecordType,unique_ptr<Record>,hash<int>>m_records;
public:
    RecordFactory()
    {
        m_records[CAR]=make_unique<CarRecord>("Ferrari",5050);
        m_records[PERSON] = make_unique<PersonRecord>("Tom", 25);
    }
    unique_ptr<Record>createRecord(RecordType recordType)
    {
        return m_records[recordType]->clone();
    }
};

int main(){
RecordFactory recordFactory;

auto record = recordFactory.createRecord(CAR);
record->print();



record = recordFactory.createRecord(PERSON);
record->print();

}

















