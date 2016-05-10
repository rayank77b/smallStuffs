# Cobol Stuff and Things

* http://www.tutorialspoint.com/cobol

```cobol
IDENTIFICATION DIVISION.
PROGRAM-ID. HELLO.

PROCEDURE DIVISION.
  DISPLAY 'Hello World'.
STOP RUN.
```

compile
```shell
cobc -free -x HELLO.COB
```

```cobol
      * simple hello world program
       IDENTIFICATION DIVISION.
       PROGRAM-ID. HELLO-WORLD.
       PROCEDURE DIVISION.
         DISPLAY 'Hello world!'.
       STOP RUN.
```
compile
```shell
cobc -free -x HELLO.COB
```
