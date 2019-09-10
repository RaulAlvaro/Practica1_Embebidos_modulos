# Archivo Makefile simple
PROYECTO=practica
DESTDIR=/usr/local/bin
CFLAGS=-Wall
LDFLAGS=-lm
CC=gcc

all: $(PROYECTO)

%.o: $.c
	$(CC) -c $<  $(CFLAGS)

#$(PROYECTO): muestreo.o procesamiento.o archivos.o
$(PROYECTO): $(patsubst %.c, %.o,$(wildcard *.c))
	$(CC) $^ -o $@ $(LDFLAGS)

.PHONY: clean


install: all
	if [ ! -d $(DESTDIR) ]; then \
		sudo mkdir $(DESTDIR); \
	fi; \
	sudo cp $(PROYECTO) $(DESTDIR)

uninstall:
	sudo rm /usr/local/bin/$(PROYECTO)

clean:
	rm -f *.o $(PROYECTO)

