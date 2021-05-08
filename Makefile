all:
	gcc -g -o procr procr.c read_process_file.c;
install:
	install ./procr /usr/local/bin/procr;
