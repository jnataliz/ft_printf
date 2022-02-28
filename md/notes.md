# 2022-02-07
- compilazione manuale usando `gcc`
- makefile
  - struttura
  - come fare le regole
  - variabili
- file .h
  - `#ifndef` preambolo

# 2022-02-09
- usare `libft` e rimuovere librerie che non si possono usare
  - `stdlib.h`, `unistd.h`
- creare piccolo test per string `"Hello World!"`
- scrivere code `ft_printf` per questo test
- Output test():
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
    res = printf("%c %d\n", 50, 10.8);
    2 0
    res = 4
    res = printf("%c %d\n", 50, 10,8);
    2 10
    res = 5
    res = printf("%c %d %u\n", 50, 45);
    2 45 0
    res = 7
```
# 2022-02-12
- fixare problem in cui non riuscivamo a usare `libft.a`
  - il problema era che la `make clean` in `libft` non cancellava la `libft.a`
- creare test in cui usiamo `ft_printf` con input `"Hello world\n"`
  - stampare il risultato `res` con le funzioni in `libft`
  - vediamo le funzioni in `libft.h`
    - c'e' una funzione `ft_putnbr_fd` che stampa un numero sull'output
    - possiamo usare questa funzione per stampare `res` il risultato di `ft_printf`
      - invece di convertire l'intero `res` in una stringa usando `ft_itoa`
      - e poi stampare la stringa usando `ft_putstr_fd`
- nel codice di `ft_putnbr_fd`
  - `write(fd, &s, 1);` cos'e' `&`?
    - l'operatore `&` ritorna l'indirizzo di una variabile
    - ogni variabile ha una locazione in memoria
    - la memoria e' suddivisa in parole
    - ogni parola puo' essere riferita con un indirizzo
    |indirizzo| valore     |
    |---------|------------|
    |0001     |  3         |
    |0002     | -1         |
    |0003     | "ciao"     |
    |0004     |  3         |
    - un puntatore e' una variabile che contiene un indirizzo
    ```c
      int x = 0;
      int *px;
      px = &x; // px contiene l'indirizzo di x
      *px = 2; // accede a l'indirizzo di x e ne modifa il valore
      ft_putnbr(x, 1); //stampa: 2
    ```
- differenza tra `char *text` e `*text`
```c
char *text; int *px;
char c;
c = 'H';
text = &c;
ft_putnbr_fd((int) text, 1); // stampa: l'indirizzo di `c`
ft_putchar_fd('\n', 1); // stampa: ''
ft_putchar_fd(*text, 1); // stampa: 'H'
ft_putchar_fd('\n', 1); // stampa: '
```
  - una stringa e' un puntatore a carattere
  - punta al primo carattere della stringa
```c
char *text; int *px;
char c[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w','o', 'r','d','\n'};
char *c1 = "Hello word\n";
ft_putchar_fd(c[1], 1);  // stampa: 'e'
ft_putchar_fd('\n', 1);
ft_putchar_fd(c1[2], 1);  // stampa: 'l'
ft_putchar_fd('\n', 1);
ft_putchar_fd(*c1, 1);  // stampa: 'H'
ft_putchar_fd('\n', 1);
ft_putchar_fd(*(c1+1), 1);  // stampa: 'e'
ft_putchar_fd('\n', 1);
ft_putstr_fd(c1+1, 1);  // stampa: 'ello word\n'
ft_putchar_fd('\n', 1);
text = &c;
ft_putnbr_fd((long int) text, 1); // stampa: l'indirizzo di `c`
ft_putchar_fd('\n', 1); // stampa: ''
ft_putchar_fd(*text, 1); // stampa: 'H'
ft_putchar_fd('\n', 1);
ft_putstr_fd(text, 1); //stampa: 'Hello word\n'
```
- `ft_printf` passa il primo test, stampa `"Hello word\n"`
- possiamo:
  - scrivere il prossimo test (un po' piu' difficile)
  - provare a soddisfare `norminette` :(
    
- soddisfatto `norminette`
	- in `vscode` i tab vengono sostituiti da spazi
		- `ctrl+shift+p` -> `settings`
			- cerca `detect indentation` e disattiva
				- questo in base al file decide
					- quanti spazi deve essere lungo un tab
					- se usare spazi quando viene inserito un tab
			- cerca `insert spaces` e disattiva
			- cerca `tab size` e qui decidiamo quanti spazi deve essere lungo un tab
		- `norminette main.c` per lanciare `norminette` sul file `main.c`
- scritto `test2` per flag `%c`
- funzioni variadiche `...`
	- https://www.geeksforgeeks.org/variadic-functions-in-c/
		- esempio
```c
// C program for the above approach

#include <stdarg.h>
#include <stdio.h>

// Variadic function to add numbers
int AddNumbers(int n, ...)
{
	int Sum = 0;

	// Declaring pointer to the
	// argument list
	va_list ptr;

	// Initializing argument to the
	// list pointer
	va_start(ptr, n); 
	// va_start prende come secondo argomento, l'ultimo parametro
	// prima dei ...

	for (int i = 0; i < n; i++)

		// Accessing current variable
		// and pointing to next one
		Sum += va_arg(ptr, int);

	// Ending argument list traversal
	va_end(ptr);

	return Sum;
}

// Driver Code
int main()
{
	printf("\n\n Variadic functions: \n");

	// Variable number of arguments
	printf("\n 1 + 2 = %d ",
		AddNumbers(2, 1, 2));

	printf("\n 3 + 4 + 5 = %d ",
		AddNumbers(3, 3, 4, 5));

	printf("\n 6 + 7 + 8 + 9 = %d ",
		AddNumbers(4, 6, 7, 8, 9));

	printf("\n");

	return 0;
}
``` 
- Output
```
Variadic functions: 

 1 + 2 = 3 
 3 + 4 + 5 = 12 
 6 + 7 + 8 + 9 = 30
```
# 2022-02-13
- cercare di soddisfare il test per stampare `%c`
- usare le funzioni variadiche `va_list`
	- usare `va_arg` per trovare il prossimo argomento
- iterare sulla stringa di formato `text` carattere per carattere con un ciclo
	`while` 

# 2022-02-14
- invece di stampare tutta la stringa `text` andiamo carattere per carattere
	- se il carattere e' `'%'` andiamo a controllare il prossimo carattere per
		vedere che flag e'
- fare `free` delle stringhe create

# 2022-02-16
- `%i` e `%d` sono uguali
- devo ritornare errore se passo `MAX_INT` o `MIN_INT`?
	- no, non possiamo gestire l'overflow o l'underflow
- cosa succede con `printf(NULL)`
- aggiungiamo flag `%s` e relativo test
- ogni volta che allochiamo con `malloc` dobbiamo ricordarci di fare `free`
	- per liberare la memoria
```c
#include <stdlib.h>

void *malloc(size_t size);
void free(void *ptr);
```
- `ft_itoa`
	- prende un numero
	- ti ritorna una stringa con il numero rappresentato in base dieci
	- ritorna un `char*`
	- quanto e' lunga la stringa che devo ritornare?
		- di quanti caratteri ho bisogno?
```c
"10" = ft_itoa(10); // 2 caratteri
"2022" = ft_itoa(2022); // 4 caratteri
```
- allocazione statica
```c
	int[5] nums = {0, 1, 2, 3, 4};
```
- a tempo di compilazione sappiamo quanto spazio riservare in memoria
- ci sono dei case come nella `ft_itoa` dove non sappiamo a priori
	di quanto spazio abbiamo bisogno
- in questo caso usiamo l'allocazione dinamica
```c
void *malloc(size_t size);
```
- prende una dimensione `size`
- ritorna un tipo `void *`
	- `void *` e' un puntatore a `void`
	- questo tipo e' usato per rappresentare un generico puntatore
	- tutti i puntatori possono essere visti come `void *`
```c
// allocare una stringa lunga 10
char *str;
str = (char *) malloc(10 * sizeof(char));
// la memoria allocata non e' inizializzata
print(str[9]); // non sappiamo cosa stampa, dipende dallo stato della memoria
... // uso str
// quando ho finito di usare str devo liberare la memoria puntata da str
free(str);
```
- programma di esempio
```c
	int *nums;
	printf("Alloco 10 interi\n");
	nums = (int *) malloc(10 * sizeof(int));
	int i;
	i = 0;
	printf("Stampo 10 interi\n");
	while (i < 10)
	{
		printf("%i\n", nums[i]);
		i++;
	}
	printf("Libero 10 interi\n");
	free(nums);
	printf("Stampo 10 interi\n");
	i = 0;
	while (i < 10)
	{
		printf("%i\n", nums[i]); // da un risultato diverso ad ogni esecuzione
		i++;
	}
```
# 2022-02-17
- aggiungere chiamate a `free` per la memoria allocata
- se non c'e' memoria disponibile la `malloc` ritorna `NULL`
	- bisogna sempre controllare il valore di ritorno della `malloc` per vedere
- cancelliamo la memoria allocata dalle funzioni chiamate da `ft_printf`
	- solo `ft_itoa` alloca una stringa con malloc
	- ci siamo salvati la stringa ritornata
	- abbiamo passato la stringa alla funzione `free` qu
- `valgrind` tool per controllare
- ristrutturare la `ft_printf`

# 2022-02-19
- `struct`
```c
struct flag
{
	char code;
	int length;
};
int main(void)
{
	struct flag f;
	struct f; // non valido! 
	f.code = 'c';
	f.length = 1;
	print(f.code);
	printf("%-000.00", 378.2023); //+378.20
}
```
- `flag.h`, `flag.c`
```c
struct flag
{
	...
};
parse_flag
exec_flag
```
- perche' dobbiamo avere un `flag.h`?
- se creiamo solo `flag.c`
- dobbiamo ridichiare i prototipi per `parse_flag` ed `exec_flag` in ogni file
	che li usa
```c
//ft_printf.c
parse_flag
exec_flag
...
ft_printf() {
	exec_flag..
}
```
- se creiamo sia `flag.h` e `flag.c`
- dobbiamo semplicemente includere `flag.h` perche' questo contiene gia' i
	prototipi
```c
//ft_printf.c
#include "flag.h"
```
```c
//tests.c
#include "flag.h"
```
- implementare `exec_flag` e `parse_flag`
- se ti vengono delle funzioni troppo lunghe
	- puoi fare una funzione per caso:
	- `exec_flag_s`
	- `exec_flag_c`
- ottimizazzione:
	- `ft_printf`: se non ci sono flag, stampiamo carattere per carattere
		- stampare e' lento
		- `"Hello World"`
			- stampo `'H'`, stampo `'e'`, stampo	`'l'`
		- `"Hello %s"`
			- stampo `"Hello "`
			- gestire il flag `"%s"`

# 2022-02-21
- spostare file `*.h` nella cartella `include`
- spostare file `*.c` nella cartella `src`
- ottimizzare le linee, rimuovere linee superfluee
- fare flag `%x`
	- fare test
	- cominciare test

# 2022-02-23
- `int` vs `unsigned int`
```c
1 -> 0001
2 -> 0010
3 -> 0011
4 -> 0100

-1 -> 1001
-2 -> 1010
-3 -> 1011
-4 -> 1100

int	x;
unsigned int u;

x = 2; // x = 0 
x = -2; // x = 1010
            	8421
u = x; // u = 1010 -> 10
print(u);
// complemento a 2 
// 
// -1 -> 1111 -> 15 
// -2 -> 1110
```
- se mi arriva `-1` devo stampare `FFFFFFFF`, ma io non consider quel caso
```
-1
				binary									    int  unsigned int
11111111111111111111111111111111 -> -1 -> 4294967295

FFFFFFFF
```
- implementare `ft_xtoa`

# 2022-02-24
- finire `ft_xtoa`
- flag ancora da fare `%p`, `%u`, `%%`, `%X`
- incominciato a fare flag `%u`

# 2022-02-26
- usare `printfTester`
	- dobbiamo modificare il `Makefile` per creare la libreria per la `ft_printf`
- rivedere
	- `ft_xtoa` maiuscolo, minuscolo
	- `ft_uitoa` controllare
- metere apposto `Makefile`
	- creare libreria `libftprintf.a`
	- 
- fare git repository
- fare flag `%p`
```
	char *p = "test"; // {'t', 'e', 's', 't', '\0'}-
	int	*x = 20;
	int i = 20;
	int *y = &i;
// 0x..01 20  x
// 0x..02 20  i
// 0x..03 0x..02 y
```
- trattare l'indirizzo come un `long int` (8 byte)
- riutilizzare caso `%x`
- flag `%s` fallisce nel caso la stringa e' `NULL`
	- vedere cosa fa `printf` in questo caso
	- farsi un test
	- cercare di soddisfare il test
# 2022-02-27
- `int` -> 4 bytes
- `unsigned int` -> 4 bytes
- `unsigned long int` = `unsigned long` -> 8 bytes
-	`long int` = `long` -> 8 bytes
- flag `%p` non va
	- stampa solo dalla meta' in poi di caratteri
- differenza tra `long` e `int`

- `NULL` = `0x00` = `(void *) 0`
- sistema operativo e' un programma
- al lancio del pc il sistem operativo viene caricato in memoria
- viene caricato in un'area di memoria dove non e' possibile ne leggere
	ne scrivere
```
0x00
0x01
0x02
0x03
0x04
...

```
- `int *`, `char *`, `void *`
	- un puntatore e' un indirizzo in memoria
	- un indirizzo occupa sempre 8 bytes (su una macchina a 64bit)
	```
	00000000
	00000000
	00000000
	00000000
	00000000
	00000000
	00000000
	00000000
	```
	- `int*` o `char*` e' sempre un indirizzo in memoria
		- hanno la stessa dimensione
	- `void *` per indicare un indirizzo generico
		- se vogliamo usare la memoria a cui punta come un `int`
		- dobbiamo fare un cast `(int *)`
- controllare uguaglianze tra stringhe
```c
	if (str1 == "0")
	{
		y = ft_printf("(nil)");
		return (y);
	}
```
- `str1` -> `char *`
- `str1` -> `0x0083e`
	
- `(str1 == "0")` -> 
- `zero` -> `0x009ef`
```
0x00083 '0'
0x00084 \0
0x00085
```

# ft_printf [![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/jnataliz/ft_printf)](https://github.com/JaeSeoKim/badge42)
[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/jnataliz)](https://github.com/JaeSeoKim/badge42)
