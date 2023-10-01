CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -lm --coverage -g

OBJS = out/sort.o out/key.o out/input.o out/output.o
TOBJ = out/check_mysort.o out/check_key.o

app.exe : $(OBJS) out/main.o
	$(CC) $(CFLAGS) $^ -o $@

unit_tests.exe : $(TOBJ) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lcheck

unit_testsing: unit_tests.exe
	./unit_tests.exe

out/%.o : src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -I ./inc -o $@

out/%.o : unit_tests/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -I ./inc -o $@

clean :
	rm *.o *.exe
