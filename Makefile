all: clean compile

compile:
	gcc -lcurl geteador.c -o geteador
	gcc -lcurl posteador.c -o posteador

clean:
	rm posteador
	rm geteador
