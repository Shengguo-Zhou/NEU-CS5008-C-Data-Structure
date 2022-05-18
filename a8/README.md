# Assignment 8: Multi-threaded Searching

This is some starter and example code for A8. 

* ```mt_search.c``` has some optional starter code you can use to help you get started with A8. 
    - Build and run with ```make run```
    - This runs the command ```./mt_search inputs/input1.txt 5 2 10``` 
    - To run with different parameters, you need to call something like: 
        + ```./mt_search <inputfile> <num_to_find> <num_threads> <num_numbers>```
* ```example.c``` has some code that creates 8 threads and uses a semaphore to synchronize them. 
    - Build and run this with ```make run_example```
* ```inputs``` is a folder that has files of numbers appropriate for A8. 
    - To see how many numbers are in the file: ```wc -l nums10000.txt``` , where "nums10000.txt" is the file you want to see the number of lines for. 


 
Name : Shengguo Zhou


Info about your program: 

-- ```make``` (if there is no "mt_search" file)

and then -- ```./mt_search inputs/input1.txt 5 2```

and you may choose input2.txt or nums10000.txt
+ ```./mt_search <inputfile> <num_to_find> <num_threads>```


A few observations about running your program with varying number of threads.: 
They are doing very good.


How many hours did this assignment take you?  12 hours


Did you collaborate with anyone? By myself.


Did you use external resources? List them. Google.