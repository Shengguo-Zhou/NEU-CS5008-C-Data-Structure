# Assignment 6(7): Finding Anagrams with Hashtables



Name : Shengguo Zhou

Time: 20 hours

Did you collaborate with any other students/TAs/Professors?: TAs, Google, Other Students.

External resources: Google

How to run it:

gcc main.c

./a.out

OR

make 

make run



Details are in the write-up on Canvas. 

Provided files: 

* ```words.txt```: The word file you need to read in to find anagrams with. 
* ```Hashtable_easy.h```: A starting point to structuring your hashtable that 
stores strings (```char*```s). **IF** you want to use it. 
* ```Hashtable.h```: **IF** you want, you can use this to start structuring 
and building your hashtable. 
* ```Hashtable.c```: Stub file for your hashtable code, contains FNV Hash function. 
* ```LinkedList_easy.h```: Contains API for a LinkedList that holds strings. It's an easier 
implementation than the other LinkedList. 
* ```LinkedList.h```: Contains API for a generic LinkedList implementation that you can 
use for your Hashtable implementation, if you'd like.
* ```Makefile```: Generic starting Makefile
* ```test_hashtable.cc```: A starting test file for you to use to test your hashtable implementation. 


## Easier versus More Challenging Approach: 

This week, you can choose whether to take a more challenging or less challenging 
approach to doing the assignment. Here are some pointers for whichever path you take: 

### To use the starting code to make it easier: 

* Utilize ```LinkedList_easy.h``` and ```Hashtable_easy.h``` to implement your linked list. 
* Review the functions declared in the header file. Implement the basics to get 
started (Create, Destroy, Insert), and then implement the other functions if/when 
you get to a point where you think they will be helpful. 
* When you read in the file, be sure to malloc every word. 
* Use the resources below to see how to read in a file line by line. 

### Using the starting code for more challenge: 

* Use the Hashtable/LinkedList files that aren't marked "easy", OR write your own. These 
files have 2 main differences from the "easy" files, and the differences 
allow the LinkedList and Hashtable to hold any type of data, rather than 
a specific type, such as a ```char*``` or ```int```. This generic type 
is specified with a ```void*```. When doing this, we also utilize **function pointers** 
to Destroy and Compare payloads. 



# Resources: 

* https://medium.com/basecs/hashing-out-hash-functions-ea5dd8beb4dd (Hash Functions)
* https://medium.com/basecs/taking-hash-tables-off-the-shelf-139cbf4752f0?source=---------17----------------------- (Hash Tables, generally)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hashTables (Hashtables in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#File_IO  (Reading a file in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#functionPointers (Function Pointers, for more challenge)




