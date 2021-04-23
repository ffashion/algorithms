CFLAGS = -g  -I../Common/include
LDFGLAGS =  -L ../Common/lib
DEBUG = -fsanitize=leak -fsanitize=address -fno-omit-frame-pointer
all:
	gcc $(CFLAGS) $(LDFGLAGS) test_stack.c -o test_stack -lll
	gcc $(CFLAGS) $(LDFGLAGS) $(DEBUG) test_stack.c -o test_stack_debug -lll
clean:
	rm -rf test_stack test_stack_debug