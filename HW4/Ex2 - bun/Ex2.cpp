#include <iostream>
#include <string.h>
using namespace std;


class Message;
class MessageReciever;
class MessageSender;


class MessageSender{
private:
    int Id;
    char Name[];
public:
    MessageSender(){};
    MessageSender(int Id, char Name[]){
        this->Id=Id;
        strcpy(this->Name,Name);
    }
    int getId(){
        return this->Id;
    }
};

class MessageReciever{
public:
    int Id;
    char Name[];

    MessageReciever(){};
    MessageReciever(int Id, char Name[]){
        this->Id=Id;
        strcpy(this->Name,Name);
    }
    int getId(){
        return this->Id;
    }
};

class Message{
public:
    char content[10];
    MessageSender sender;
    MessageReciever reciever;
    Message(){};
    Message(char c[], MessageSender s, MessageReciever r){
        strcpy(this->content,c);
        this->sender=s;
        this->reciever=r;
    };
};


#include "Queue.h"


MessageSender s1(3,"Alex");
MessageReciever r1(1,"ionel");
Queue Inbox;


void sendMessage(char c[]){
   Message aux(c,s1,r1);
    Inbox.enqueue(aux);
}

void readMessage(){
    char c[10];
  strcpy(c,Inbox.dequeue().content);
  for(int i=0;i<strlen(c);i++)
    cout<<c[i];
    cout<<endl;
}

int main(){
    char c[]="Salut";
    char c1[]="Neata";
    sendMessage(c);
    sendMessage(c1);
    sendMessage(c);
    readMessage();
    readMessage();
    //cout<<"hey";

}

