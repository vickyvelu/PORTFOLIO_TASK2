#include<iostream>
using namespace std;
class IoT_Node
{
  class State *current;
  public:
    IoT_Node();
    void setCurrent(State *s)
    {
        current = s;
    }
    void idle();
    void sensing();
    void processing();
};

class State
{
  public:
  virtual void idle(IoT_Node *sen)
    {
        cout << "  Idle\n";
    }
    virtual void sensing(IoT_Node *sen)
    {
        cout << "   Sensing Sensor\n";
    }
    virtual void processing(IoT_Node *sen)
    {
        cout << " processing data\n";
    }
};

void IoT_Node::idle()
{
  current->idle(this);
}

void IoT_Node::sensing()
{
  current->sensing(this);
}

void IoT_Node::processing()
{
  current->processing(this);
}

class Sense: public State
{
  public:
    Sense()
    {
        cout << "   Sensing Temperature ";
        cout << "   Sensing Humidity  ";
     int a=20;
                  for(int i=10;i<=a;i++)
                  {
                        cout << "The temperature Sensor Value: " << a <<endl;
                  }
     int b=40;
                 for(int i=20;i<=b;i++)
                  {
                        cout << "The Humidity Sensor Value: " << b <<endl;
                  }
    };
    ~Sense()
    {
        cout << "   Sensing completed\n";

    };

};

class Process: public State
{
  public:
    Process()
    {
        cout << " transferring data ";
    };
    ~Process()
    {
        cout << "   Processing completed\n";
    };

};


int main()
{
  void(IoT_Node:: *ptrs[])() =
  {
    IoT_Node::processing, IoT_Node::sensing
  };
  IoT_Node fsm;
  int num;
  while (1)
  {
    cout << "Press key to trigger state";
    cin >> num;
    (fsm.*ptrs[num])();
  }
}
