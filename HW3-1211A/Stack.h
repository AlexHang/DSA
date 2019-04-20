#include <iostream>
using namespace std;
#define NMAX 10 // pre-processing directive

template<typename T>
class Stack {
    private:
	// an array of NMAX dimension
	T stackArray[NMAX];
	/* the top of the stack, representing the INDEX of last element of the stackArray:0, 1, 2,....*/
    int topLevel;
    public:
        	void push(T x) { //puts an element in the stack array
		//check if the stack array has the maximum dimension
		if (topLevel >= NMAX - 1) {
            		cout<<"The stack is full: we have already NMAX elements!\n";
               		 //exit the function without making anything
			return;
        		}
        		/*add an element=> the index of the last element of the stack Array increases and put the value of the new element in the stack array*/
            	stackArray[++topLevel] = x;
      	  }
       	 int isEmpty() {
    		//returns 1, if topLevel>=0, meaning the stack array has elements
        		// returns 0, otherwise
            	return (topLevel < 0);
     	}

     	int getSize(){
            return topLevel;
     	}

     	 T pop() {
        	// extracts and element from the stack array and returns the new top
            if (isEmpty()) {
                // the extraction is made only if the array is not empty
	          	cout<<"The stack is empty! \n";
                T x;
                return x;
            }
	// the topLevel decreases and the new top is changed
            return stackArray[topLevel--];
}
T peek() {
	  // returns the top of the stack
	   if (isEmpty()) {
	                // the extraction is made only if the array is not empty
		cout<<"The stack is empty! \n";
	                	T x;
	                	return x;
        	}
            return stackArray[topLevel];
}
Stack() { // constructor
	topLevel = -1; // the stack is empty in the beginning
}

~Stack() { // destructor}
};
};
