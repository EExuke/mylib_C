# 静态库与动态库的编译示例

# 制作静态库：
	1.编写 xxx.c 和 xxx.h 文件
	2.用[gcc xxx.c -c -o xxx.o] 编译xxx.c生成 xxx.o 文件
	3.然后用[ar -cr libxxx.a xxx.o] 生成静态库
	4.可编写一个main.c 来测试静态库 [引用：include "add.h"]
	5.再[gcc main.c ./libadd.a] 编译 main.c 和 libadd.a
	6.先将add.c 和add.o 删除，保留 add.h 和libadd.a ；则静态库中的API add函数就可以使用了

# 制作动态库：
	1.同上文件
	2.用[gcc xxx.c -shared -fPIC -o libxxx.so] 编译生成动态链接库 libxxx.so
	3.同样写main.c测试 [引用：include "add.h"]
	4.编译时简单声明引用库[gcc main.c ./libadd.so]
