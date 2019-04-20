#include <iostream>
#include <stdlib.h>
#include "MessageSender.h"
#include "MessageReciever.h"

using namespace std;
class Message{
public:
    MessageSender Sender;
    MessageReciever Reciever;
    char content[];

    Message(MessageSender s, MessageReciever r, char c[]){
        this->Sender=s;
        this->Reciever=r;
        this->content=c;
    }
};
