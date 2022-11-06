SRCS = static_main.c
LIBSRCS = open.c close.c put.c get.c seek.c
TARG = kvs_static

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a


all: $(TARG)

static: $(TARG)

dynamic: kvs_dynamic

kvs_dynamic :
	$(CC) -shared -o libkvs.so $(LIBSRCS)
	$(CC) -fPIC -o  kvs_dynamic dynamic_main.c -ldl

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)  


$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG) kvs_dynamic libkvs.so
