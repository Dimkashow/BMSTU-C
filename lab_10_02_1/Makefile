TARGET = app.exe
TTARGET = test.exe
HDRS_DIR = include
FLAGS = -Wall -Werror -pedantic -std=c99

SRCS = \
       src/main.c \
       src/sorting.c \
       src/mem_operations.c \
       src/struct_operations.c

TEST_SRCS = \
       src/test.c \
       src/sorting.c \
       src/mem_operations.c \
       src/struct_operations.c

.PHONY: all clean

app.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TARGET) $(SRCS)

test.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TTARGET) $(TEST_SRCS)

clean:
	rm -rf $(TARGET) $(TTARGET)
