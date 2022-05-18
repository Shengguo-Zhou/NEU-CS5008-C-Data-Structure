Your Name: Shengguo Zhou

Any resources you used: Google

About how much time you spent on this assignment: 3 days, 12 hours per day in average.

What was the most challenging part of this assignment?: The syntax of c, too many differences with java

[Optional] How could this assignment be improved? : Use java to implement all of this, I can shorten the time I used by 90%.
<br />
<br />
<br />
P.S.

For Part 1:

LinkedList is implemented in linkedlist.c and linkedlist.h

LinkedList is tested in maintest.c

I can choose a sort: either Selection or Insertion. And I choose Selection Sort. It is implemented in sort.c and sort.h. Test in part 1 of main.c and maintest.c
<br />
<br />
<br />
For Part 2:

QuickSort is implemented in QuickSort_General.c and QuickSort_General.h

It is called general because I choose pivot in a general way int this sort.
<br />
<br />
<br />
Implement a 2nd Quicksort algorithm for xtra credit (up to 5 points):

I choose the median pivot way:

Take the first, last and middle element from the array. Use the median value of those as the pivot.

This way is implement in QuickSort_MedianPivot.c and QuickSort_MedianPivot.h
<br />
<br />
<br />
Prints out a "report" of how long it takes to run your implementation on a variety of array lengths:

And I choose 4 ways to implement this comparsion.

1 : selection sort in part 1

2 : quick sort (general pivot way) in part 2

3 : quick sort2 (median pivot way) in part 2

4 : I can choose any sorting method, so I choose bubble sort. It is implement in sort2.c and sort2.h

And the quicksort(general pivot way), which should be O(nlogn), may be even a little bit slower than selection sort O(n^2), because it is implemented in a linkedlist, find certain elememts in a linkedlist can really take a lot of time.
<br />
<br />
<br />
At last: Everthing is shown clearly in the main.c

gcc main.c and then ./a.out

everything will show. And the bubble sort is really slow, you need to wait aroud 30 seconds.

Or make, then make run(this program may need 30 seconds), at last make clean.
