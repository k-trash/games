LDLIBS := `pkg-config --cflags --libs gtk+-2.0`
CC := gcc
CFLAGS := `pkg-config --cflags --libs gtk+-2.0`

black_jack: black_jack.o jack_header.o jack_gui.o

clean:
	$(RM) *.o
