Maze.cmd: Stack.o Maze.o Source.o
	gcc -I Include-Files/ Stack.o Maze.o Source.o -o Maze.cmd
	rm Maze.o Source.o Stack.o
Stack.o:
	gcc -I Include-Files/ -c Source-Files/Stack.c
Maze.o:
	gcc -I Include-Files/ -c Source-Files/Maze.c
Source.o:
	gcc -I Include-Files/ -c Source-Files/Source.c