mydata:
	# shared 
	# gcc -c -fPIC mydata.c -o mydata_shared.o -I ../include -g -Wall
	gcc -c -fPIC sll.c -o sll.o -I ../include -g -Wall
	gcc -c -fPIC dll.c -o dll.o -I ../include -g -Wall
	gcc -c -fPIC darray.c -o darray.o -I ../include -g -Wall
	gcc -c -fPIC stack.c -o stack.o -I ../include -g -Wall

	# gcc --shared mydata_shared.o  -o libmydata.so -g -Wall
	
	gcc --shared sll.o dll.o darray.o stack.o -o libll.so -g -Wall

	# static 
	gcc -c darray.c -o darray_static.o -I ../include -g  -Wall
	gcc -c sll.c -o sll_static.o -I ../include -g  -Wall
	gcc -c dll.c -o dll_static.o -I ../include -g  -Wall
	gcc -c stack.c -o stack_static.o -I ../include -g  -Wall
	ar r libll.a sll_static.o dll_static.o darray_static.o stack_static.o

	# gcc -c mydata.c -o mydata_static.o -I ../include -g  -Wall
	# ar r libmydata.a mydata_static.o


clean:
	rm -rf mydata.o mydata_shared.o mydata_shared.so libmydata.so  mydata_static.o libmydata.a
	rm -rf sll*.o dll*.o darray*.o
	rm -rf libll.a libll.so
	rm -rf *.o 