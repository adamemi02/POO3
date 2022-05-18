#include <iostream>

using namespace std;

class Car
{
public:
    virtual int GetFuel() = 0;
    virtual int GetRangePerFuel() = 0;
    virtual const char* GetType() = 0;
};

class BMW : public Car {
public:
    int GetFuel() override { return 15; }
    int GetRangePerFuel() override { return 5; }
    const char* GetType() override { return "BMW"; }
};

class Ford : public Car {
public:
    int GetFuel() override { return 10; }
    int GetRangePerFuel() override { return 7; }
    const char* GetType() override { return "Ford"; }

    void Custom_Type_Method() {
        cout<<"This is a FORD"<<endl;
    }
};

class Toyota : public Car {
public:
    int GetFuel() override { return 20; }
    int GetRangePerFuel() override { return 6; }
    const char* GetType() override { return "Toyota"; }
};

class SingletonTrack {
    static SingletonTrack *instance;
    int track_length;
    int cars_count;
    Car** cars_list;

    SingletonTrack() {
        track_length = 0;
        cars_list = new Car*[100];
        cars_count = 0;
    }

public:
    static SingletonTrack *getInstance() {
        if (!instance)
            instance = new SingletonTrack;
        return instance;
    }

    int getTrackLength() {
        return this -> track_length;
    }

    void setTrackLength(int new_length) {
        this -> track_length = new_length;
    }

    void insertInRace(Car* new_car) {
        if(cars_count < 100)
        {
            cars_list[cars_count++] = new_car;
        }
    }

    template <class T>
    T* getRaceParticipant(int index) {
        return (T*)&cars_list[index];
    }

    void executeRace()
    {
        for(int i = 0; i < cars_count; i++)
        {
            if(cars_list[i] -> GetFuel() * cars_list[i] -> GetRangePerFuel() < track_length)
            {
                cout<<"Car "<<i<<" could not finish the race"<<endl;
            }
            else
            {
                cout<<"Car "<<i<<" finished the race"<<endl;
            }
        }
    }
};

SingletonTrack *SingletonTrack::instance = 0;

int main(){
    SingletonTrack *s = s->getInstance();
    s->setTrackLength(100);
    cout << s->getTrackLength() << endl;
    s->insertInRace(new BMW());
    s->insertInRace(new Ford());
    s->insertInRace(new Toyota());
    s->getRaceParticipant<Ford>(1)->Custom_Type_Method();
    s->executeRace();
    return 0;
}

