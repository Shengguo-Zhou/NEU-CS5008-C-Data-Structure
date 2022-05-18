all: sort

sort:
	gcc main.c -o a.out

run:
	./a.out

.PHONY: clean

clean:
	rm a.out



### This builds the hashtable library. Change the filenames accordingly. 
# Hashtable.o: Hashtable.c Hashtable.h LinkedList.o
# 	gcc -c -Wall -g Hashtable.c -o Hashtable.o

# ## Builds the LinkedList library, if you're using it. 
# LinkedList.o: LinkedList.c LinkedList.h
# 	gcc -c -Wall -g LinkedList.c -o LinkedList.o


# ## Compiles your hashtable tests.
# test_hashtable.o : test_hashtable.cc
# 	g++ -c -Wall -I $(GOOGLE_TEST_INCLUDE) test_hashtable.cc \
# 		-o test_hashtable.o

# ## Puts it all together. 
# test_suite: $(GOOGLE_TEST_LIB) test_hashtable.o Hashtable.o LinkedList.o
# 	g++ -o test_suite test_hashtable.o Hashtable.o LinkedList.o \
# 		 -L${HOME}/lib/gtest -lgtest -lpthread
# 	@echo -e "\033[38;5;198m===================================="
# 	@echo Run tests by running ./test_suite
# 	@echo -e "====================================\033[0m"

# clean: 
# 	rm -rf *~ main
