/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dianascurtu & alexhang
 *
 * Created on 16 aprilie 2019, 18:31
 */

#include <iostream>
#include <fstream>
#include "list-lab6.h"
#define nmax 30

using namespace std;
ifstream fin("txt.in");

int n; // nr. de elevi
int k; // nr. de proiecte
int x[nmax];
int viz[nmax]={0};

struct proiect{
    int id;
    char nume[20];
}p[nmax];

struct elev{
    int id;
    char nume[20];
}ev[nmax];

struct camp{
    elev elev;
    proiect proiect;
}c;

LinkedList<camp> list;



void citire(){
    
    fin>>n;
    fin.get();
    for(int i=0; i<n; i++){
        fin.getline(ev[i].nume,21);
        ev[i].id = i;
    }
    
    fin>>k;
    fin.get();
    for(int i=0; i<k; i++){
        fin.getline(p[i].nume,21);
        p[i].id = i;
    }
    
}

void add(elev e, proiect p){
    //1.2
    c.elev = e;
    c.proiect = p;
    list.addLast(c);
}

void afisare(int k){
    for(int i=1; i<=k; i++){
        //cout<<x[i]<<" "; // pentru indici
        
        cout<<ev[i-1].nume<<" - '"<<p[x[i]-1].nume<<"'  "; 
        
        add(ev[i-1],p[x[i]-1]);    
    }
cout<<"\n";
}

template <typename T>
void af(T v[],int nr){ // pentru verificarea vectorilor initiali
    for(int i=0; i<nr; i++)
        cout<<v[i].id<<" "<<v[i].nume<<"\n";
}

bool vf(int x[]){
    int viz[nmax]={0};
    int ct=0;
    for(int i=1; i<=n; i++) 
        if(!viz[x[i]]) viz[x[i]]=1, ct++;
    if(ct==k) return 1;
    return 0;
}

void back(int K)
{
    for(int i=1; i<=k; i++) {
        x[K]=i;
        if (K==n){
            if(vf(x)) afisare(K);
        }
        else back(K+1);
    }
}

void Delete(char s[]){
    Node<camp> *p;
    p = list.pfirst;
    while (p != NULL){
        if(strcmp(p->info.elev.nume,s)==0) {
            if (p != NULL){//we must re-link the pointers
                if (p->prev != NULL)
                    p->prev->next = p->next;

                if (p->next != NULL)
                    p->next->prev = p->prev;

                if (p->prev == NULL) // if p == pfirst
                    list.pfirst = p->next;

                if (p->next == NULL) // if p == plast
                    list.plast = p->prev;

                delete p; //now we can delete it
            }
        }
        p = p->next;
    }
    n--;
}

void Replace(char a[], char b[]){
    Node<camp> *p;
    p = list.pfirst;
    while (p != NULL){
        if(strcmp(p->info.proiect.nume,a)==0)
            strcpy(p->info.proiect.nume,b);

        p = p->next;
    }
}


int main(){
    
    int ex;
    cout<<"ex: ";cin>>ex;
    citire();
    
    // 1.1
    cout<<"nr. de solutii: "<<n*k<<'\n';
    back(1); 
    
    if(ex==2) {// 1.2
        cout<<"\n";
        list.printList(n);
    }
    
    if(ex==3) {// 1.3
        char s[20];
        cout<<"\n Sterge un elev din lista: \n";
        af(ev,n);
        cin>>s; 
        
        Delete(s);
        cout<<"\n";
        list.printList(n);
    }
    
    if(ex==4) {// 1.4
        char a[20], b[20];
        cout<<'\n';
        af(p,k);
        cin.get();
        cout<<"\n Inlocuieste proiectul: "; cin.getline(a,21);
        cout<<" cu proiectul: "; cin.getline(b,21);
        cout<<'\n';
        
        Replace(a, b);
        list.printList(n);
    }
    
    return 0;
}

