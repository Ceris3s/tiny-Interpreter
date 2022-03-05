/**
 
gcc -o c0 c0.c
./c0 hello.c

 */


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int token ;   //current token
char *src , *old_src ;   // pointer to source code string
int poolsize ; //default size of text/data/stack
int line;


//  next() 用于词法分析，获取下一个标记，它将自动忽略空白字符。不过下面这个没忽略
void next(){
    token = *src ++ ;
    return;
}

//expression(level) 用于解析一个表达式。
void expression(int level){
    // do nothing
}

//program() 语法分析的入口，分析整个 C 语言程序。
void program() {

    next();               // get next token
    while(token > 0) {
        printf("token is: %c\n", token);
        next();
    }
}

//eval() 虚拟机的入口，用于解释目标代码。
int eval() {   // do nothing yet
    return 0;
}

int main(int argc, char **argv)
{
    int i, fd;

    argc -- ;
    argv ++ ;
    
    poolsize = 256*1024;  //  arbitrary size
    line = 1;

    if((fd = open(*argv, 0)) < 0){
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    if(!(src = old_src = malloc(poolsize))) {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }

    //read the source file
    if ((i = read(fd, src, poolsize-1)) <= 0) {
        printf("read() returned %d\n", i);
        return -1;
    }
    src[i] = 0; // add EOF character
    close(fd);

    program();
    return eval();
}


/*
输出截取的一部分：
test@ubuntu:~/Desktop/test/cc$ ./c0 hello.c
token is: #
token is: i
token is: n
token is: c
token is: l
token is: u
token is: d
token is: e
token is:  
token is: <
token is: s
token is: t
token is: d
token is: i
token is: o
token is: .
token is: h
token is: >
token is: 
token is: 

token is: 
token is: 

token is: i
token is: n
token is: t
token is:  
token is: f
token is: i
token is: b
token is: o
token is: n
token is: a
token is: c
token is: c
token is: i
token is: (
token is: i
token is: n
token is: t
token is:  
token is: i
token is: )
token is:  
token is: {
token is: 
token is: 

token is:  
token is:  
token is:  
token is:  
token is: i
token is: f
token is:  
token is: (
token is: i
token is:  
token is: <
token is: =
token is:  
token is: 1
token is: )
token is:  
token is: {
token is: 
token is: 

token is:  
token is:  
token is:  
token is:  
token is:  
token is:  
token is:  
token is:  
token is: r
token is: e
token is: t
token is: u
token is: r
token is: n
token is:  
token is: 1
token is: ;
token is: 
token is: 

token is:  
token is:  
token is:  
token is:  
token is: }
token is: 
token is: 



*/
