# GDB Gnu Debugger Samples/Tutorials

run `perl -e 'print "A"x1040'`  $(...)


Simple C code

```c
int main() {

    int a=2;
    int b=3;
    
    int c;
    
    c = a+b;

    return 0;
}
```

```shell
gcc -ggdb -S xx.c we get:

 .file "c2.c"
 .text
 .globl main
 .type main, @function
main:
.LFB0:
 .cfi_startproc
 pushq %rbp
 .cfi_def_cfa_offset 16
 .cfi_offset 6, -16
 movq %rsp, %rbp
 .cfi_def_cfa_register 6
 movl $2, -4(%rbp)
 movl $3, -8(%rbp)
 movl -8(%rbp), %eax
 movl -4(%rbp), %edx
 addl %edx, %eax
 movl %eax, -12(%rbp)
 movl $0, %eax
 popq %rbp
 .cfi_def_cfa 7, 8
 ret
 .cfi_endproc
.LFE0:
 .size main, .-main
 .ident "GCC: (Debian 4.7.2-5) 4.7.2"
 .section .note.GNU-stack,"",@progbits

or disas it with gdb (x64 machine):

   0x00000000004004ac <+0>:     push   %rbp          
   0x00000000004004ad <+1>:     mov    %rsp,%rbp   
// save stack     
//  %rbp  64 bit base pointer
   
   0x00000000004004b0 <+4>:     movl   $0x2,-0x4(%rbp)    
// int a=2;  locale variablee auf stack
// die variable ist um 4 byte gegeneuber base pointer gespeichert.

   0x00000000004004b7 <+11>: movl   $0x3,-0x8(%rbp)    
// int b=3

   0x00000000004004be <+18>: mov    -0x8(%rbp),%eax
   0x00000000004004c1 <+21>: mov    -0x4(%rbp),%edx    
// von stack in register laden

   0x00000000004004c4 <+24>: add    %edx,%eax          
   0x00000000004004c6 <+26>: mov    %eax,-0xc(%rbp) 
// register addieren   
// auf stack speichern  int c=a+b;
   
   0x00000000004004c9 <+29>: mov    $0x0,%eax          
   0x00000000004004ce <+34>: pop    %rbp
   0x00000000004004cf <+35>: retq  
// return 0;  exit main
```


Links:

http://en.wikipedia.org/wiki/GNU_Assembler

http://www.ibm.com/developerworks/linux/library/l-gas-nasm/index.html

http://sourceware.org/binutils/docs-2.20/as/

Assembling: 

GAS:
```shell
as –o program.o program.s
```

Linking (common to both kinds of assembler):
```shell
ld –o program program.o
```

Linking when an external C library is to be used:
```shell
ld –-dynamic-linker /lib/ld-linux.so.2 –lc –o program program.o
```

comments:  # comment  or /* comment */

directives: (pseudo ops)  .blabla

.intel_syntax noprefix   # intel syntax  einschalten

.globl  _start   # main entry point

.text            # text segment (code)

.data            # data segment


coding:

$4  a value 4

$len  a variable


# at&t syntax (default syntay of gnu as)

movl    $4, %eax  # load a value 4 in eax register (long)


# intel syntax

mov  edx, eax  # load value of register eax to edx


Intel: mov al, byte ptr foo 

intel syntax has the information about size near foo


AT&T: movb foo, %al

at&t syntax has the size information in mov code b for byte

byte b(8-bit), word w(16-bit), long l(32-bit), r (64-bit)

simple programm:


int main()  {


}


generate on x64:

```c
.file "c.c"

.text

.globl main

.type main, @function

main:

.LFB0:

.cfi_startproc

pushq %rbp

.cfi_def_cfa_offset 16

.cfi_offset 6, -16

movq %rsp, %rbp

.cfi_def_cfa_register 6

popq %rbp

.cfi_def_cfa 7, 8

ret

.cfi_endproc

.LFE0:

.size main, .-main

.ident "GCC: (Debian 4.7.2-5) 4.7.2"

.section .note.GNU-stack,"",@progbits

```

pushq %rbp

is the prolog of the function: it save the base pointer on stack

movq %rsp, %rbp

and set the new basepointer to actual stack pointer


popq %rbp

is the epilog/end of the function. it restore the stack pointer.

        ret

return to the address saved on stack bevore bp was saved.   

al, ah: 1 byte

ax:  2 byte

eax: 4 byte

rax: 8 byte

|__64__|__56__|__48__|__40__|__32__|__24__|__16__|__8___|
|__________________________RAX__________________________|
|xxxxxxxxxxxxxxxxxxxxxxxxxxx|____________EAX____________|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|_____AX______|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|__AH__|__AL__|

simle example:

int a,b,c;

a=23;

b=94;

c=a+b;

int a,b,c;    

# there are 3 variables 4 byte size (32 bit)


a=23;

movl	$23, -4(%rbp)   # save value 23 on stack 

           # rbp-4 (4 byte from actual base pointer)


b=94;

    movl	$94, -8(%rbp)   # save value 94 on stack 

           # rbp-8 (4+4 byte from actual base pointer)

                       

# the compiler calculate the size and andress for each value

# therefore he must know is it an integer or character size	                       


movl	-8(%rbp), %eax  # b

movl	-4(%rbp), %edx  # a

# load b in eax, a in adx

addl	%edx, %eax

# add them, the result is stored in eax

movl	%eax, -12(%rbp)

# save eax ( result ) in c 3x4=12 byte from stack pointer.

int a=-23; unsigned int b=94; long c; c=a+b;

movl $-23, -4(%rbp) # the value is -23 movl $94, -8(%rbp) # there is no difference to int, but what happen if we set b=-94? # as generate: movl $-94, -8(%rbp) is set -94. # here we must do 2er complement. movl -4(%rbp), %edx movl -8(%rbp), %eax addl %edx, %eax movl %eax, %eax movq %rax, -16(%rbp) # 16? 2*4+8=16, because long has 8 byte (64bit) size

char a=-23;

short  b=94;

int  c=144;

long d=32;

long long e;

e=d+c+a+b;


movb	$-23, -1(%rbp)

# char a=-23; 1 byte long

# the opcode is mov b, move a byte


movw	$94, -4(%rbp)

# short b=94; 2 byte long -> 2+1=3, but why 4?

# the answer is the alligment, 3 is not alliment on 2 modulus

# the opcode is mov w, move a word: 2 byte

movl	$144, -8(%rbp)

# int c=144; 4 byte long + 4 = 8

# the opcode is mov l, move a long (integer)

movq	$32, -16(%rbp)	

# long d=32; 8 byte long + 8 byte = 16

# the opcode is mov q, move a quad word: 4 word: 4*2=8 Byte

movl	-8(%rbp), %eax	

movslq	%eax, %rdx

# load c in eax

# and extend a sign 32bit eax, to quad 64 bit rdx

# mov signed long to quad

# to extend a unsgined: movzlq


movq	-16(%rbp), %rax

addq	%rax, %rdx

# load d in rax	

# add a quad word: rax=rax+rdx


movsbq	-1(%rbp), %rax

addq	%rax, %rdx

# load a in rax and extend from signed byte to quad word

# add it: rax=rax+rdx


movswq	-4(%rbp), %rax

addq	%rdx, %rax

# load b to rax and extend it from signed word to quad word

# add it: rax=rax+rdx


movq	%rax, -24(%rbp)

# the result is not stored in rax

# save it in e: long long is here 8 byte long: 8+16=24 byte to base pointer


int a=34;

int b=73;

int c=a-b;


movl	$34, -4(%rbp)   # a=34

movl	$73, -8(%rbp)   # b=73

movl	-8(%rbp), %eax  # eax=b

movl	-4(%rbp), %edx  # edx=a

movl	%edx, %ecx      # ecx=edx=a

subl	%eax, %ecx      # ecx=a-b=ecx-eax

movl	%ecx, %eax      # eax=ecx=result

movl	%eax, -12(%rbp) # store c=eax

# why compiler generate thus a complex sub, 

# is at moment not known.

# simpler is:


movl	-4(%rbp), %ecx

subl	%eax, %ecx  

movl	%ecx, -12(%rbp)

# int c=a*b;

movl	-4(%rbp), %eax  # load a to eax

imull	-8(%rbp), %eax  # multiplicate b with eax,

# there is a multiplication of memory with register.	

movl	%eax, -12(%rbp) # c=eax



# int c=a/b;

movl	-4(%rbp), %eax  # load a to eax

movl	%eax, %edx      # edx=eax

sarl	$31, %edx       # shift edx right 31 bits:  edx=edx&gt;&gt;31,

                       # save the signed bit in edx

idivl	-8(%rbp)        # signed division of memory eax(edx rest)=edx:eax/b

movl	%eax, -12(%rbp) # c=eax, rest in edx


# int c=a%b;

movl	-4(%rbp), %eax  # eax=a

movl	%eax, %edx      # edx=eax=a

sarl	$31, %edx       # save the signed bit

idivl	-8(%rbp)        # signed div: eax(edx rest)=edx:eax/b

movl	%edx, -12(%rbp) # save the rest c=edx

# int c=a&amp;b;

movl	-8(%rbp), %eax  # eax=b

movl	-4(%rbp), %edx  # edx=a

andl	%edx, %eax      # eax=eax and edx

movl	%eax, -12(%rbp) # c=eax


# int c=a|b;

movl	-8(%rbp), %eax  # eax=b

movl	-4(%rbp), %edx  # edx=a

orl	%edx, %eax          # eax= eax or edx

movl	%eax, -12(%rbp) # c=eax


# int c=a^b;

movl	-8(%rbp), %eax  # eax=b

movl	-4(%rbp), %edx  # edx=a

xorl	%edx, %eax      # eax = eax xor edx

movl	%eax, -12(%rbp) # c=eax


# int c=~b;

movl	-8(%rbp), %eax  # eax=b

notl	%eax            # eax = not eax

movl	%eax, -12(%rbp) # c=eax

int b=11;


int main()  {


int a=73;

a=b;


}


.file	"c.c"

.globl	b

.data

.align 4

.type	b, @object

.size	b, 4

b:

.long	11                

# b is stored global in memory


.text

.globl	main

.type	main, @function

main:

....

movl	$73, -4(%rbp)      

# a is stored local on stack


movl	b(%rip), %eax       

#  rip: relative to instruction pointer


# the value of b in eax

movl	%eax, -4(%rbp)

# store eax in a: a(local on stack)=b(global in data memory);


# now look at gdb output:


   0x00000000004004b0 <+4>:	movl   $0x49,-0x4(%rbp)

   0x00000000004004b7 <+11>:	mov    0x2003c3(%rip),%eax  

                             # 0x600880 <b>

   0x00000000004004bd <+17>:	mov    %eax,-0x4(%rbp)


# 0x2003c3(%rip) ->  address of b i 0x2003c3+rip

# if we run the programm, we get ip~0x4004bd on point <+11>

# 0x4004bd+0x2003c3 = ~0x600880

# local

const int a=73;

int b=11;

b=a;

a=b; // don't compile -&gt; error: assignment of read-only variable ‘a’


movl	$73, -4(%rbp)

movl	$11, -8(%rbp)

movl	-4(%rbp), %eax  # is the same:  b=a 

movl	%eax, -8(%rbp)

# the compiler look that in constant variables no one write.

#global

const int a=73;

int b=11;


int main()  {

b=a;

// a=b; // don't compile

}


.globl	a

.section	.rodata

.align 4

.type	a, @object

.size	a, 4

a:

.long	73              # a stored in data segment

                       # there is no information about const.

.globl	b               

.data

.align 4

.type	b, @object

.size	b, 4

b:                          # b stored in data segment

.long	11

.text

.globl	main

.type	main, @function

main:

...

movl	a(%rip), %eax   # load eax=a

movl	%eax, b(%rip)   # store b=eax

# pointer


int a=73;

int b=0;

int *p=&a;


b=*p;


movl $73, -20(%rbp)  # int a=73

movl $0, -4(%rbp)    # int b=0;

leaq -20(%rbp), %rax

# load address of rbp-20 in rax (a)

movq %rax, -16(%rbp)

# store the address in rbp-16 (p)

movq -16(%rbp), %rax

movl (%rax), %eax

movl %eax, -4(%rbp)

# array 


int a[10];

a[0]=10;

a[1]=11;

a[2]=12;


int b=0;


b=a[2];


# compiler create a 10x4=40 size stack

# then 4 for int b and alligment

movl $10, -48(%rbp)  # a[0]=10

# a[0] begin at rbp-48

movl $11, -44(%rbp)  # a[1]=11

movl $0, -4(%rbp)    # int b=0


movl -40(%rbp), %eax # load a[2] to eax

movl %eax, -4(%rbp)  # store b=a[2]

# struct type


struct bla {

int a;

int b;

char c;

};


int main()  {


struct bla a;


a.a=4;

a.b=5;

a.c='c';


a.a=a.b;


# here we can see that the stuct bla is only a definition

# compiler, how to handle size of values.


movl $4, -16(%rbp)   # a.a=4

movl $5, -12(%rbp)   # a.b=5

movb $99, -8(%rbp)   # a.c=='c' (99)


# a.a=a.b;

movl -12(%rbp), %eax # get a.a in register

movl %eax, -16(%rbp) # store to a.b

# struct with pointers; 

# same struct bla


struct bla a;

struct bla *p;


a.a=4;  a.b=5;  a.c='c';


p=&a;


p->a=11;



movl $4, -32(%rbp)   # a.a=4

movl $5, -28(%rbp)   # a.b=5

movb $99, -24(%rbp)  # a.c='c'

leaq -32(%rbp), %rax 

# get the address of rbp-32 ( struct bla a variable)


movq %rax, -8(%rbp)  

# store the address to struct bla *p;

movq -8(%rbp), %rax

# get address of p

# is not necessary, because it stored yet

movl $11, (%rax)

# p->a=11; 

# movl $11, %rax: that were rax=11

# movl $11, (%rax):  store 11 to addres which is saved in rax


movq -8(%rbp), %rax

# get address of p

movl $12, 4(%rax)

# store to 'address of p + 4 (integer)'=12



# if() else

int a=4;

int b=0;


if(a==4) {

    b=11;

}else{

    b=12;

}  


movl $4, -4(%rbp)    # a=4

movl $0, -8(%rbp)    # b=0

cmpl $4, -4(%rbp)    # is a==4?

jne .L2             # no, jump to .L2 do b=12

movl $11, -8(%rbp)   # yes, do b=11

jmp .L4             # don not do b=12, jump to exit

.L2:

movl $12, -8(%rbp)   # b=12

.L4: # exit here

int a=4;

int b=0;


switch(a)  {

    case 0:

        b=11;

        break;

    case 1:

        b=12;

        break;

    default:

        b=30;

}             


movl $4, -4(%rbp)

movl $0, -8(%rbp)


# switch(a)

movl -4(%rbp), %eax  # load a to eax

testl %eax, %eax      # test a

je .L3                 # a==0 jump to .L3

cmpl $1, %eax        # compare a==1

je .L4                 # yes, jump to .L4

jmp .L6                 # else jump to .L6

.L3:

movl $11, -8(%rbp)   # b=11

jmp .L7                 # break;

.L4:

movl $12, -8(%rbp)   # b=12

jmp .L7                 # break;

.L6:

movl $30, -8(%rbp)   # default: b=30;

.L7:                        # exit



# information:

testl %eax, %eax

jz    zeroLabel     ; jump if EAX is zero

js    negLabel      ; jump if EAX is negative

jns   posLabel      ; jump if EAX is positive

je    label # if eax==0 equal

# if, else if, else

int a=4;

int b=0;


if(a==3) {

    b=3;

} else if(a==4) {

    b=4;

} else {

    b=5;

}


movl $4, -4(%rbp)

movl $0, -8(%rbp)

cmpl $3, -4(%rbp)    # if(a==3)

jne .L2                 # not equal, jump .L2

movl $3, -8(%rbp)    # equal, b=3;

jmp .L5                 # jump to exit

.L2:

cmpl $4, -4(%rbp)    # else if(a==4)

jne .L4                 # not equal, jump to .L4

movl $4, -8(%rbp)    # b=4;

jmp .L5                 # jump to exit

.L4:

movl $5, -8(%rbp)    # else: b=5;

.L5:

# for loop

int i;

int j;


for(i=0; i<10; i++) {

    j=i;

}  


movl $0, -4(%rbp)    # i=0

jmp .L2                 # jump .L2 to compare

.L3:

movl -4(%rbp), %eax  # move value of i to eax

movl %eax, -8(%rbp)  # store eax to j

addl $1, -4(%rbp)    # i=i+1

.L2:

cmpl $9, -4(%rbp)    # compare i==9 

jle .L3                 # jump to begin .L3 if i<=9

for(i=0; i<10; i++) {

    j=i;

    if(i==2)

        break;

}


movl $0, -4(%rbp)    # i=0

jmp .L2                 # jump to compare 

.L5:

movl -4(%rbp), %eax  # eax=i

movl %eax, -8(%rbp)  # j=eax

cmpl $2, -4(%rbp)    # compare i==2

je .L7                 # yes, jump to exit, 

                       # je .L6 is the same

.L3:                        

addl $1, -4(%rbp)    # i=i+1

.L2:

cmpl $9, -4(%rbp)    # compare i==9

jle .L5         # less or equal i<=9 jumpt to begin

jmp .L6                 # jumpt to exit

.L7:                        # exit for break, not necessary

nop

.L6:                        # exit


# smaller

movl $0, -4(%rbp)    # i=0

jmp .L2                 # jump to compare 

.L5:

movl -4(%rbp), %eax  # eax=i

movl %eax, -8(%rbp)  # j=eax

cmpl $2, -4(%rbp)    # compare i==2

je .L6                 # yes, jump to exit, 

                       # jump to exit

addl $1, -4(%rbp)    # i=i+1

.L2:

cmpl $9, -4(%rbp)    # compare i==9

jle .L5          # less or equal i<=9 jumpt to begin

.L6:  

# while loop

while(i>10) {

    i++;

    j=i;

} 


jmp .L2

.L3:

addl $1, -4(%rbp)

movl -4(%rbp), %eax

movl %eax, -8(%rbp)

.L2:

cmpl $10, -4(%rbp)

jg .L3

































