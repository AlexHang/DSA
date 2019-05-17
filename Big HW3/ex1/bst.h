#include <iostream>
#include "list.h"
#include <math.h>
#include <algorithm>

using namespace std;

template<typename T> class BinarySearchTree {
    public:
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        T *pinfo;

        BinarySearchTree() {
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
        }

        void setInfo(T info) {
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x) {
            if (pinfo == NULL)
                setInfo(x);
            else
                insert_rec(x);
        }

        void insert_rec(T x) {
            int next_son;
            if (x <= (*pinfo))
                next_son = 0;
            else
                next_son = 1;

            if (next_son == 0) {  // left son
                if (left_son == NULL) {
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                } else
                    left_son->insert_rec(x);
            } else { // right son
                if (right_son == NULL) {
                    right_son = new BinarySearchTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;
                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                } else
                    right_son->insert_rec(x);
            }
        }

        BinarySearchTree<T>* find(T x) {
            BinarySearchTree<T> *rez;

            if (pinfo == NULL)
                return NULL;

            if ((*pinfo) == x)
                return this;

            if (x <= (*pinfo)) {
                if (left_son != NULL)
                    return left_son->find(x);
                else
                    return NULL;
            } else {
                if (right_son != NULL)
                    return right_son->find(x);
                else
                    return NULL;
            }
        }

        void removeInfo(T x) {
            BinarySearchTree<T> *t = find(x);
            if (t != NULL)
                t->remove();
        }

        void remove() {
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL) {
                if (parent == NULL) { // this == root
                    delete this->pinfo;
                    root->pinfo = NULL;
                } else {
                    if (parent->left_son == this)
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            } else {
                if (left_son != NULL) {
                    p = left_son;
                    while (p->right_son != NULL)
                        p = p->right_son;
                } else { // right_son != NULL
                    p = right_son;
                    while (p->left_son != NULL)
                        p = p->left_son;
                }

                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux;
                p->remove();
            }
        }

        void inOrderTraversal() {
            if (left_son != NULL){
                left_son->inOrderTraversal();}
            cout<<pinfo<<" "; // we should use the correct format
                                              // for printing type T values
            if (right_son != NULL)
                right_son->inOrderTraversal();
        }



        void toList() {
               // LinkedList<int> myList[100];
                if (left_son != NULL){
                    left_son->toList();}


                nodes[counter++]=(int)*(pinfo);

               // cout<<pinfo<<" "; // we should use the correct format
                                                  // for printing type T values
                if (right_son != NULL){
                     right_son->toList();
                }

            }

             void rotateBST(){

                if (root == NULL)
                    return ;
                if (root->left_son == NULL && root->right_son == NULL)
                    return ;

                //  recursively call the same method
               // BinarySearchTree<char>* flippedRoot = rotateBST(root->left_son);

                //  rearranging main root Node after returning
                // from recursive call
                root->left_son->left_son = root->right_son;
                root->left_son->right_son = root;
                root->left_son = root->right_son = NULL;

               // return flippedRoot;

            }


        void preOrderTraversal(){
             cout<<pinfo<<" "; // we should use the correct format
                                              // for printing type T values
            if (left_son != NULL)
                left_son->inOrderTraversal();

            if (right_son != NULL)
                right_son->inOrderTraversal();
        }

        void postOrderTraversal(){
            // we should use the correct format
                                              // for printing type T values
            if (left_son != NULL){
                left_son->inOrderTraversal();}

            if (right_son != NULL){
                right_son->inOrderTraversal();}

         cout<<pinfo<<" ";
        }

        T maximumElement(){
            BinarySearchTree *currNode=this;

            while(currNode -> right_son !=NULL)
                currNode = currNode->right_son;

            return *currNode->pinfo;
        }

        int getHeight(){
            if(this==NULL)
                return -1;
            else
                return std::max(this->left_son->getHeight(),this->right_son->getHeight()) + 1;
        }

        int getRootHeight(){
            int left;

            if(this==NULL)
                return -1;

            if(this->left_son==NULL)
                left = -1;
            else
                left= this->left_son->getHeight();

            int right;
            if(this->right_son==NULL)
                right = -1;
            else
                right = this->right_son->getHeight();

            return abs(left-right);
        }

        void displayHeight(int level){
            if(this==NULL)
                return;

            if(level == 0) cout<<this->pinfo<<" ";
            else{
                this->left_son->displayHeight(level -1);
                this->right_son->displayHeight(level -1);
            }
        }

        void displaybyHeight(){
            for(int i=0;i<=this->getHeight();i++){
                cout<<endl<<"Level "<<i<<":";
                displayHeight(i);
            }
        }

        void intervalNodes(T x, T y){
            if(this==NULL)
                return;

            if(*this->pinfo < x){
                this->right_son->intervalNodes(x,y);
            }else
                if(*this->pinfo > y){
                    this->left_son->intervalNodes(x,y);
                }else{
                    this->left_son->intervalNodes(x,y);

                    if(*this->pinfo != x && *this->pinfo !=y)
                        cout<<*this->pinfo<<" ";

                    this->right_son->intervalNodes(x,y);
                }
        }
};
