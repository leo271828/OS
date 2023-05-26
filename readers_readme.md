# Readers-Writers Problem

> **I didn't modify the original file.**

## Compile & Run
```
$ gcc readers.c -o readers.exe -pthread
$ ./readers.exe
```

## Introduction
It's First R-W Problem variation.
We using **Pthread**  and **Semaphore** to design the program. 

`pthread_create` & `pthread_join` in Pthread are distribute threads to readers & wirters where in the `main()` function. \
Semaphore is used to prevent race condition then `wrt` initialized to 1.

## Reference
* [GitHub - codophobia/readers-writers-solution-in-c](https://github.com/codophobia/readers-writers-solution-in-c)