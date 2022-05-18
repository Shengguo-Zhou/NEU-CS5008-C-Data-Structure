Who did you work with (if anyone)

By myself

How long did this take you?

1 hour

The first version, errors.c, has...errors! If you use Valgrind and run the executable, you'll see something like this:

-bash-4.2$ gcc errors.c -o errors -g

-bash-4.2$ valgrind --leak-check=full ./errors

==186017== Memcheck, a memory error detector

==186017== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.

==186017== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info

==186017== Command: ./errors

==186017==

==186017== Use of uninitialised value of size 8

==186017== at 0x400590: main (errors.c:7)

==186017==

example

==186017==

==186017== HEAP SUMMARY:

==186017== in use at exit: 8 bytes in 1 blocks

==186017== total heap usage: 1 allocs, 0 frees, 8 bytes allocated

==186017==

==186017== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1

==186017== at 0x4C29EA3: malloc (vg_replace_malloc.c:309)

==186017== by 0x4005A6: main (errors.c:7)

==186017==

==186017== LEAK SUMMARY:

==186017== definitely lost: 8 bytes in 1 blocks

==186017== indirectly lost: 0 bytes in 0 blocks

==186017== possibly lost: 0 bytes in 0 blocks

==186017== still reachable: 0 bytes in 0 blocks

==186017== suppressed: 0 bytes in 0 blocks

==186017==

==186017== For counts of detected and suppressed errors, rerun with: -v

==186017== Use --track-origins=yes to see where uninitialised values come from

==186017== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

You can see that there were 2 errors: use of an uninitialized value and a leak.

Now try no_errors.c. You should see output like this:

-bash-4.2$ gcc no_errors.c -o no_errors -g

-bash-4.2$ valgrind --leak-check=full ./no_errors

==187455== Memcheck, a memory error detector

==187455== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.

==187455== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info

==187455== Command: ./noerrors

==187455==

example

==187455==

==187455== HEAP SUMMARY:

==187455== in use at exit: 0 bytes in 0 blocks

==187455== total heap usage: 1 allocs, 1 frees, 8 bytes allocated

==187455==

==187455== All heap blocks were freed -- no leaks are possible

==187455==

==187455== For counts of detected and suppressed errors, rerun with: -v

==187455== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

No errors—WHOO! There are comments in the code that explain how the errors were fixed, essentially: we avoided using an uninitialized variable and freed the memory we had allocated for the string. This is the result you want for your programs: no errors, no leaks.
