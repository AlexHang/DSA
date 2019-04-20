#include <iostream>
#include <string.h>
using namespace std;


class Message;
class MessageReciever;
class MessageSender;

struct date{
    int d;
    int m;
    int y;
};

class MessageSender{
private:
    int Id;
    char Name[10];
public:
    MessageSender(){};
    MessageSender(int Id, char name[]){
        this->Id=Id;
        strcpy(this->Name,name);
    }
    int getId(){
        return this->Id;
    }

    void showName(){
        for(int i=0;i<strlen(Name);i++)
            cout<<Name[i];
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
    date d;
    Message(char c[], MessageSender s, MessageReciever r, int day, int month,int year){
        strcpy(this->content,c);
        this->sender=s;
        this->reciever=r;
        this->d.d=day;
        this->d.m=month;
        this->d.y=year;
    };
    void showDate(){
        cout<<":"<<d.d<<"/"<<d.m<<"/"<<d.y<<" : ";
    }
};


#include "MyQueue.h"


MessageSender s1(3,"Raluca");
MessageReciever r1(1,"Maria");
Queue <Message> Inbox;


void sendMessage(char c[]){
   Message aux(c,s1,r1,21,3,2019);
    Inbox.enqueue(aux);
}

void readMessage(){
    char c[10];
    Message recieved=Inbox.dequeue();
    recieved.sender.showName();
    recieved.showDate();
  strcpy(c,recieved.content);
  for(int i=0;i<strlen(c);i++)
    cout<<c[i];
    cout<<endl;
}

int main(){
    char c[]="Buna";
    char c1[]="Ce Faci ?";
    sendMessage(c);
    sendMessage(c1);
    sendMessage(c);
    readMessage();
    readMessage();
    //cout<<"hey";

}

