# Makefile Stuff

```make
MYSQL_CONFIG=$(shell which mysql_config)
MW_CFLAGS=$(shell $(MYSQL_CONFIG) --cflags)
CGO_LDFLAGS=wrapper.o $(shell $(MYSQL_CONFIG) --libs)

prereq:
	@test -x "$(MYSQL_CONFIG)" || \
		(echo "Can't find mysql_config in your path."; false)

wrapper.o: wrapper.c wrapper.h
	#gcc -fPIC -std=c99 -pedantic -Wall -Wextra -o wrapper.o -c wrapper.c
	gcc $(MW_CFLAGS) -o wrapper.o -c wrapper.c
```

