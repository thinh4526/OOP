#include<iostream>
#include<string>
#include<list>
using namespace std;
class Room;
class Instructor;
//
class Instructor{
private:
    string name;
    list<Room*> room;
public:
    // getter, setter
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    //constructor
    Instructor(string name){
        this->setName(name);
    }
    void bookOneRoom(Room *r);
    void unbookOneRoom(Room *r);
    void display();
};

class Room{
private:
    string number;
    int seating;
    Instructor *instructor = NULL;
public:
    // getter, setter
    string getNumber(){
        return this->number;
    }
    int getSeating(){
        return this->seating;
    }
    void setNumber(string number){
        this->number = number;
    }
    void setSeating(int seating){
        this->seating = seating;
    }
    //constructor
    Room(string number, int seating){
        this->setNumber(number);
        this->setSeating(seating);
    }
    Instructor *getInstructor(){
        return this->instructor;
    }
    string getInstructorName(){
        return (*this->instructor).getName();
    }
    void attachInstructor(Instructor *ins);
    void detachInstructor();
};
// method
void Room::attachInstructor(Instructor *ins){
    this->instructor = ins;
}
void Room::detachInstructor(){
    this->instructor = NULL;
}
void Instructor::bookOneRoom(Room *r){
    if(r->getInstructor() == NULL){ //added after the test (điều kiện)
        this->room.push_back(r);
        r->attachInstructor(this);
    }
    else
        cout<<"This room has been booked"<<endl; // added after the test
}
void Instructor::unbookOneRoom(Room *r){
    this->room.remove(r);
    r->detachInstructor();
}
void Instructor::display(){
    cout<<"Name: "<<this->getName()<<endl;
    if(this->room.size() != 0){
        cout<<"Booked Room: "<<endl;
        for(auto r : room){
            cout<<r->getNumber()<<", seating capacity: "<<r->getSeating()<<endl;
        }
    }
    
}
int main(){
    Instructor insA("Lam");
    Instructor insB("Thao");
    Room r1("001", 100);
    Room r2("002", 50);
    Room r3("003", 75);
    //
    insA.bookOneRoom(&r1);
    insA.bookOneRoom(&r2);
    insB.bookOneRoom(&r3);
    //
    insA.unbookOneRoom(&r1);
    insB.bookOneRoom(&r1);
    insA.bookOneRoom(&r3); // added after the test
    //
    cout<<"----------------Information--------------"<<endl;
    insA.display();
    cout<<"\n\n";
    insB.display();
    return 0;
}
