Big Homework 1 

Hang Alexandru
1211EB 
FILS UPB

About the homework:

Programming language(s): C++
Development Environment: CodeBlocks
Compiler: GNU GCC Compiler (CodeBlocks Default)


Exercise 1:
Task: Advanced Stack with getMin() and getMax() in O(1) complexity
Approach: Because getMin and getMax both have O(1) complexity, we need to find the min and max when we push elements in the stack, and when we pop an element in the stack
	  Push() : 0) If the stack is empty, the element will be both the min and the max
		   1) Compare the element with the actual min and max
	           2) if the element is smaller than min, then he is the new min. (same procedure for max)
		   3) Push the element
	Peek(): same as for the normal stack from the course
	Pop():   1) check if the element is equal to the max
			if YES, then find the new max
		 2) check if the element is equal to the min
		 	if YES, then find the new min


Exercise 2:
Task: find a path in a matrix, using a stack
Approach: use the stack to remember the visited points.
	  find all the possible routes using DFS
	  print only the correct route, from the stack

Exercise 3:
Task: Priority Queue
Approach: Use the advanced Stack from ex1 to store all the distances
	 enQueue(): enqueue the element, and push it's distance in the stack
	 deQueue(): getMin from Stack, and deQueue the element located at that distance
	
