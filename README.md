# looping-lex

## Loop based lexical analyzer based on OpenMP

looping-lex is a parallel lexical analyzer for small scale languages which does token matching using loops accelerated by OpenMP over traditional automata.

Loop based matching is useful, when there are a finite number of lexemes to look for in each category. It provides an alternate approach to using flex


## Building

To build with nix, run

```shell
nix-shell contrib/shell.nix
```

```shell
meson build
```

## Running

```shell
./build/flex-lex < <sample-file>
./build/looping-lex --file <sample-file>
./build/looping-lex --file <sample-file> --accelerate
```


## Benchmarks


### 30MB source file


 Index |   Naive   |  OpenMP  |   Flex  |
-------|-----------|----------|---------|
 Real  | 0m2.161s  | 0m1.126s | 0m0.27s |
 User  | 0m1.786s  | 0m4.401s | 0m0.26s |
  Sys  | 0m0.042s  | 0m0.079s | 0m0.01s |



### 90MB source file

 Index |   Naive   |  OpenMP  |   Flex  |
-------|-----------|----------|---------|
 Real  | 0m5.944s  | 0m2.181s | 0m0.50s |
 User  | 0m5.435s  | 0m13.48s | 0m0.49s |
  Sys  | 0m0.123s  | 0m0.210s | 0m0.02s |

