# tiny-Interpreter
Write a simple interpreter of C



自己的小练习，基于https://github.com/lotabout/write-a-C-interpreter

1. [手把手教你构建 C 语言编译器（0）——前言](http://lotabout.me/2015/write-a-C-interpreter-0/)
2. [手把手教你构建 C 语言编译器（1）——设计](http://lotabout.me/2015/write-a-C-interpreter-1/)
3. [手把手教你构建 C 语言编译器（2）——虚拟机](http://lotabout.me/2015/write-a-C-interpreter-2/)
4. [手把手教你构建 C 语言编译器（3）——词法分析器](http://lotabout.me/2015/write-a-C-interpreter-3/)
5. [手把手教你构建 C 语言编译器（4）——递归下降](http://lotabout.me/2016/write-a-C-interpreter-4/)
6. [手把手教你构建 C 语言编译器（5）——变量定义](http://lotabout.me/2016/write-a-C-interpreter-5/)
7. [手把手教你构建 C 语言编译器（6）——函数定义](http://lotabout.me/2016/write-a-C-interpreter-6/)
8. [手把手教你构建 C 语言编译器（7）——语句](http://lotabout.me/2016/write-a-C-interpreter-7/)
9. [手把手教你构建 C 语言编译器（8）——表达式](http://lotabout.me/2016/write-a-C-interpreter-8/)
10. [手把手教你构建 C 语言编译器（9）——总结](http://lotabout.me/2016/write-a-C-interpreter-9/)

## 编译器的构建流程

一般而言，编译器的编写分为 3 个步骤：

1. 词法分析器，用于将字符串转化成内部的表示结构。
2. 语法分析器，将词法分析得到的标记流（token）生成一棵语法树。
3. 目标代码的生成，将语法树转化成目标代码。

已经有许多工具能帮助我们处理阶段1和2，如 flex 用于词法分析，bison 用于语法分析。只是它们的功能都过于强大，屏蔽了许多实现上的细节，对于学习构建编译器帮助不大。所以我们要完全手写这些功能。

所以我们会依照以下步骤来构建我们的编译器：

1. 构建我们自己的虚拟机以及指令集。这后生成的目标代码便是我们的指令集。
2. 构建我们的词法分析器
3. 构建语法分析器



## 编译器框架

我们的编译器主要包括 4 个函数：

1. `next()` 用于词法分析，获取下一个标记，它将自动忽略空白字符。
2. `program()` 语法分析的入口，分析整个 C 语言程序。
3. `expression(level)` 用于解析一个表达式。
4. `eval()` 虚拟机的入口，用于解释目标代码。

这里有一个单独用于解析“表达式”的函数 `expression` 是因为表达式在语法分析中相对独立并且比较复杂，所以我们将它单独作为一个模块（函数）。



