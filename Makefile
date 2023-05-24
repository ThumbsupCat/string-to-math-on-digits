build:
	gcc RPN.c -o rpn

run:
	./RPN

run_valgrind:
	valgrind --leak-check=full ./rpn

clean:
	rm rpn