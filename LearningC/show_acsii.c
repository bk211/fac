#include <stdio.h>
int main()
{
    char c;
    printf("intpud: ");
 
    // 读取用户输入
    scanf("%c", &c);  
    
    // %d 显示整数
    // %c 显示对应字符
    printf("%c if ASCII is %d", c, c);
    return 0;
}