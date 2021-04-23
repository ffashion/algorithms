DEBUG = -fsanitize=leak -fsanitize=address -fno-omit-frame-pointer
CFLAGS = -g  -I../Common/include
LDFGLAGS =  -L ../Common/lib
OBJ=
all:
	
	gcc $(CFLAGS) $(LDFGLAGS) -o sequenntial_storage_static  sequential_storage.c -lll
	gcc $(CFLAGS) $(DEBUG) $(LDFGLAGS) sequential_storage.c -o sequenntial_storage_debug  -lll

	
	gcc $(CFLAGS) $(LDFGLAGS) linked_list_storage.c -o linked_list_storage_static -static -lll
	gcc $(CFLAGS) $(DEBUG) $(LDFGLAGS) linked_list_storage.c -o linked_list_storage_debug -lll

	gcc $(CFLAGS) $(LDFGLAGS) double_linklist.c   -o double_linklist_static  -static -lll
	gcc $(CFLAGS) $(DEBUG) $(LDFGLAGS) double_linklist.c -o double_linklist_debug -lll

clean:
	rm -rf sequenntial_storage_static sequenntial_storage_debug
	rm -rf linked_list_storage_static linked_list_storage_debug
	rm -rf double_linklist_debug double_linklist_static
 