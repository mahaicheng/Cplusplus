/*************************************************************************
	> 文件名: 10.1.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年04月04日 星期一 11时43分53秒
 ************************************************************************/

#include<stdio.h>
#include<apue.h>

int main()
{
    int fd1 = open("foo.txt", O_RDONLY, 0);
    close(fd1);

    int fd2 = open("baz.txt", O_RDONLY, O_CREAT);
    printf("fd2 = %d\n", fd2);
}
