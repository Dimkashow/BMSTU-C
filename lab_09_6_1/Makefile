TARGET = app.exe
TTARGET = test.exe
HDRS_DIR = include
FLAGS = -Wall -Werror -pedantic -std=c99

SRCS = \
       src/main.c \
       src/Matrix.c \
       src/lab_operation.c

TEST_SRCS = \
       src/test.c \
       src/Matrix.c \
       src/lab_operation.c \

.PHONY: clean

app.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TARGET) $(SRCS) -lm

test.exe: $(SRCS)
	gcc $(FLAGS) -I $(HDRS_DIR) -o $(TTARGET) $(TEST_SRCS) -lm

clean:
	rm -rf $(TARGET) $(TTARGET)
