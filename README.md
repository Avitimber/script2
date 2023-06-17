# 使用 C 语言协程

## 作业 find.c grep.c 

1. 在文件 fs_walk.c 编写中编写函数 fs_walk
   + fs_walk 是一个生产者协程
   + 遍历指定目录下所有的目录项
   + 使用 co_yield 函数向消费者协程传递目录项

2. 在文件 find.c 中实现 find 程序的功能
   + 引用 fs_walk.c 
   + 编写一个消费者协程，获取 fs_walk 传递的目录项
   + 打印符合要求的目录项 

```
例：在目录 /usr/include 下查找文件 stdio.h
$ find /usr/include -name stdio.h
/usr/include/stdio.h
/usr/include/c++/7/tr1/stdio.h
/usr/include/x86_64-linux-gnu/bits/stdio.h
```

3. 在文件 grep.c 中实现 grep 程序的功能
   + 引用 fs_walk.c 
   + 编写一个消费者协程，获取 fs_walk 传递的目录项
   + 检索指定的字符串 

```
例：在目录 /usr/include 下查找包含有字符串 linux 的文件
$ grep -r linux /usr/include
/usr/include/selinux/selinux.h:extern int is_selinux_e
nabled(void);
/usr/include/selinux/selinux.h:extern int is_selinux_m
ls_enabled(void);
/usr/include/selinux/selinux.h:/* Wrappers for the sel
inuxfs (policy) API. */
```

```

