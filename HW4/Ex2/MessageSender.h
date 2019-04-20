#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "Message.h"
#include "MessageReciever.h"
using namespace std;
class MessageSender{
private:
    int Id;
    char Name[];
public:
    MessageSender(){};
    MessageSender(int Id, char Name[]){
        this->Id=Id;
        this->Name=Name;
    }
    int getId(){
        return this->Id;
    }
    void sendMessage(char m[], &Queue<Message> q, &MessageReciever r){
        Message aux(this,r,m);
        q.enqueue(aux);
    }
};
