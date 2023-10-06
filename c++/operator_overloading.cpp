#include <iostream>
#include <list>
using namespace std;

struct MyChannel{
    string name;
    int subscriberCount;

    MyChannel(string name, int subscriberCount)
    {
        this->name=name;
        this->subscriberCount=subscriberCount;
    }
};

//global operator function
ostream& operator<<(ostream& COUT, MyChannel& yt)
{
    COUT << "Name : " << yt.name << endl;
    COUT << "Subscriber Count : "<<yt.subscriberCount<<endl;
    return COUT;
}

//member operator function
struct MyCollection{
    list<MyChannel> myChannels;
    void operator+=(MyChannel& channel) //here we have passed only one argument because 'myc' will be available automatically.
    {
        this->myChannels.push_back(channel);
    }

    // void operator-=(MyChannel& channel) //here we have passed only one argument because 'myc' will be available automatically.
    // {
    //     this->myChannels.remove(channel);
    // }
};

ostream& operator<<(ostream& COUT, MyCollection& myc)
{
    for(MyChannel m:myc.myChannels)
        COUT<< m <<endl;
    return COUT;
}

int main()
{
    MyChannel mt1 = MyChannel("CodeRunner", 10000);
    MyChannel mt2 = MyChannel("Run", 1200);
    // cout << mt1 << mt2; 
    // operator<<(cout,mt1);
    MyCollection myc;
    myc += mt1;// we only need to pass yt1 in argument
    myc += mt2;
    cout << myc;
}
