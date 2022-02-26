```c
    res = printf("Hello word\n");
    Hello word
    res = 11
	
    res = printf("%d\n", 23);
    23
    res = 3
	
    res = printf("This year is: %d\n", year);
    This year is: 2022
    res = 19
	
    res = printf("%c\n", 50);
    2
    res = 2

		// float passato per %d
    res = printf("%c %d\n", 50, 10.8);
    2 0
    res = 4

		// piu' parametri che flag
    res = printf("%c %d\n", 50, 10,8);
    2 10
    res = 5

		// piu' flag che parametri
    res = printf("%c %d %u\n", 50, 45);
    2 45 0
    res = 7

		// formato NULL
		res = printf(NULL); // non stampa niente
		res = -1

		res = printf("%s", "Questa è una stringa\n");
		Questa è una stringa
		res = 22

		res = printf("%x\n", 184545);
		2d0e1
		6
	
		printf("%q\n", 2323);
		%
		2
```