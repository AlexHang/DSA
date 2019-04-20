#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "Message.h"
#include "MessageSender.h"
using namespace std;
class MessageReciever{
private:
    int Id;
    char Name[];
public:
    MessageReciever(){};
    MessageReciever(int Id, char Name[]){
        this->Id=Id;
        this->Name=Name;
    }
    int getId(){
        return this->Id;
    }
    void readMessage(&Queue<Message> q){
        cout<<q.dequeue().content;
    }
};
