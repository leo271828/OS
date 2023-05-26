# Bounded-Buffer Problem

> **I didn't modify the original file.**

## Compile & Run
```
$ gcc buffer.c -o buffer.exe -fopenmp 
$ ./buffer.exe
```

## Introduction
We using OpenMP in C that can maintain multithreading. 

`#pragma omp parallel sections` is the parallel part and threads will process `producer()` & `consumer()` seperately by `#pragma omp setction`. \
Two variable `in` & `out` can make mutex

## Reference
* [GitHub - jachermocilla/prodcon_omp.c](https://gist.github.com/jachermocilla/a7ab7c3992799d2b167aa3eb22d053d1)