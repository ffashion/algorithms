CFLAGS= -I ./Common/include -L./Common/lib/
all:
	$(MAKE) -C Common/lib/ -f lib.mk
	$(MAKE) -C LinearTable -f LinearTable.mk
	$(MAKE) -C StackAndQueue -f StackAndQueue.mk 
clean:
	$(MAKE) -C Common/lib/ -f lib.mk clean 
	$(MAKE) -C LinearTable -f LinearTable.mk clean
	$(MAKE) -C StackAndQueue -f StackAndQueue.mk clean
	