#include <stdio.h>
#include <iostream>
#include <math.h>

int counter=0;
int nodes[200];


#include "bst.h"

using namespace std;

BinarySearchTree<char>bst;


void getAncestor(BinarySearchTree<char> *e1, BinarySearchTree<char> *e2){

    char a1[100],a2[100];
    int i1=0,i2=0;

    *(a1+(i1++))=*e1->pinfo;
    while(e1->parent != NULL){
        *(a1+(i1++))=*e1->parent->pinfo;
        *e1=*e1->parent;
    }

    *(a2+(i2++))=*e2->pinfo;
    while(e2->parent != NULL){
        *(a2+(i2++))=*e2->parent->pinfo;
        *e2=*e2->parent;
    }

    for(int i=0;i<i1;i++){

        for(int j=0;j<i2;j++){

                //cout<<a1[j]<<" "<<a2[j];
            if(a1[i]==a2[j]){
                 cout<<a1[i];
                 return;
            }


        }

    }


}


void isGrandParent(BinarySearchTree<char> *c, BinarySearchTree<char> *p){


        if(c->pinfo == p->pinfo ){
            cout<<"yes, is is grandparent";
            return;
        }else{
            isGrandParent(c->parent,p);
        }
      //  *c=*c->parent;

    cout<<"no, it is not a grandparent";

}

bool isPerfectRec( BinarySearchTree<char>* root, int d, int level = 0)
{
    // An empty tree is perfect
    if (root == NULL)
        return true;

    // If leaf node, then its depth must be same as
    // depth of all other leaves.
    if (root->left_son == NULL && root->right_son == NULL)
        return (d == level+1);

    // If internal node and one child is empty
    if (root->left_son == NULL || root->right_son == NULL)
        return false;

    // Left and right subtrees must be perfect.
    return isPerfectRec(root->left_son, d, level+1) &&
           isPerfectRec(root->right_son, d, level+1);
}


  int findADepth(BinarySearchTree<char> *node)
{
   int d = 0;
   while (node != NULL)
   {
      d++;
      node = node->left_son;
   }
   return d;
}

// Wrapper over isPerfectRec()
bool isPerfect(BinarySearchTree<char>*root)
{
   int d = findADepth(root);
   return isPerfectRec(root, d);
}


int main(){



    char c;
    scanf(" %c", &c);
    while(c!='0'){
        bst.insert(c);
        scanf(" %c", &c);
    }

    //bst.inOrderTraversal();
s
/*

   BinarySearchTree<char>* b1 = bst.find('x');
   BinarySearchTree<char>* b2 = bst.find('y');

   cout<<"common ancestor of x and y is";
   getAncestor(b1,b2);
    cout<<endl;

   isGrandParent(b1,b2);




    bst.rotateBST();*/

    bst.toList();

    LinkedList<int>myLists[100];
    int level=1;
    myLists[0].addFirst(nodes[0]);


    for(int i=1;i<counter;i=i*2+1){
            for(int j=i;j<=(i*2);j++){
                // cout<<(char)nodes[j]<<" ";
                myLists[level].addLast(nodes[j]);
            }
            level++;


    }

    for(int i=0;i<level;i++){
        cout<<"Level"<<i<<":";
         myLists[i].printList();
         cout<<endl;
    }

    cout<<isPerfect(bst.root);
/*
*/





    return 0;
}
