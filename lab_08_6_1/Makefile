TARGET = app.exe
TTARGET = test.exe
HDRS_DIR = include
FLAGS = -Wall -Werror -pedantic -std=c99

SRCS = \
       src/main.c \
       src/cdio_arr.c \
       src/mem_oper.c \
       src/u_find.c

TEST_SRCS = \
       tests/UnitTests/test.c \
       src/testing.c

.PHONY: all clean

app.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TARGET) $(SRCS)

test.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TTARGET) $(TEST_SRCS)

clean:
	rm -rf $(TARGET) $(TTARGET)
