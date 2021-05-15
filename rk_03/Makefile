TARGET = app.exe
TTARGET = test.exe
HDRS_DIR = include
FLAGS = -Wall -Werror -pedantic -std=c99

SRCS = \
       main.c

.PHONY: clean

app.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TARGET) $(SRCS) -lm

clean:
	rm -rf $(TARGET) $(TTARGET)
