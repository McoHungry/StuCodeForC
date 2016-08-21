 指针七题：

1.	利用随机函数获取十个1-100的整数并打印，然后再反序打印一遍。(通过指针获取下标的值)

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 10

void func(int *num)
{
	srand((unsigned int)time(NULL));		// 设置系统时间做为随机数种子
	for(int i = 0; i < N; ++i)				// 循环N 次
		printf("%d ", *(num + i) = rand() % 100 + 1);	// 每次获取一个 1~100之间的随机数，同时赋值到数组里，并打印出来
}

int main(void)
{
	int num[N] = { 0 };			// 定义一个十个元素的整型数组
	int *p = num;				// 定义一个数组指针指向数组首地址
	func(p); 					// 将指针做为函数参数传递
    printf("\n");
	for(p = num + N - 1; p >= num; --p)	// 将指针重新指向数组最后一位下标，从后往前遍历并打印，直到指向数组的第一个下标
		printf("%d ", *p);				// 打印 p当前指向的地址 的值
	return 0;
}


2.	输入年份和这一年的第N天，计算并打印出这一天是这一年的几月几日。(区分闰年)
#include <stdio.h>
int main(void)
{
	int year, month, days;
	char ch;
	do
	{
		int num[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	// 非闰年的每月天数

		printf("Plz input year and days :");
		scanf("%d,%d", &year, &days);				// 把年份和总天数赋值到year 和 days 里

		if((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
			*(num + 2) = 29;			// 如果判断当前年份是闰年，则修改2月的天数为29天

		for(month = 1; days > *(num + month); ++month)	// 总天数减去当前月的天数，如果能减，则月份加一天，剩余天数继续参与运算
			days -= *(num + month);						// 直到剩余天数不大于当前月天数，则退出循环。
														// 则当前月和当前剩余天数，即是 这一年的 month 月 和 days 日
		// 假设 days = 32，days 先减去 31天，剩余1天并赋值给 days， 同时 month 自增1，如此循环，直到 days的天数不大于当前月的天数

		printf("year = %d, month = %d, days = %d\n", year, month, days);
		printf("\n\nIf you want again, input Y/y (other for quit): ");
		getchar();					// 接收之前scanf()输入的回车符
		ch = getchar();

	} while( ch == 'Y' || ch == 'y');		// 只要输入 Y、y，循环继续

	printf("\nThank you for using! See you again :)\n");
	return 0;
}

3.	利用随机函数获取到所有的小写英文字母，存储到字符数组char ch[26]里，且按字母表顺序打印出来。(a b c d ... z)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 26

void func(char *p)
{
	srand((unsigned int)time(NULL));		// 设置系统时间为随机数种子
	int i = 0;							// 用来接收成功存储的字符的个数
	while(i < N)
	{
		int temp = rand() % N;			// 随机数的范围是 0 ~ 25， 同时赋值给 temp				
		if(*(p + temp) == 0)			// 判断数组第 temp 个下标的值 是否是 0，如果是0，表示之前这里没有存储过字符，则执行下面的语句
		{
			*(p + temp) = temp + 'a';	// 把temp + 'a' 的值，赋值到 数组的第 temp个下标里，每次成功赋值一个字符，i就自增1
			++i;						// 假设 temp 是1， 那么就让 'a' + 1 = 'b'，同时赋值到 temp + 1里
		}								// 假设 temp 又是1， 那么 if 条件不成立，代码块的语句不执行，并重新循环获取随机数
	}
}

int main(void)
{
	char ch[N] = { 0 };		// 定义一个字符数组，同时初始化为 0， 做为后面判断条件
	func(ch);				// 把数组名做为函数实参传递
	for(int i = 0; i < N; ++i)
		putchar(*(ch + i));		// 循环打印数组里的字符
	printf("\n");
	return 0;
}

4.	将字符串“We Are Family!”，去除空格后打印出来。（WeAreFamily!）

#include <stdio.h>

char *func(char *p)
{
	int i = 0, j = 0;		// 定义两个自增量，分别代表字符串的两种下标
	while(*(p + i))			// 遍历字符串，直到结尾 '\0';
	{
		if(*(p + i) != ' ')		// 判断当前字符是否为 ' '，如果是空格，则执行下面的语句
			*(p + j++) = *(p + i);	// 取出字符串 第i个下标的字符，替换字符串第j个下标的值，同时j自增1
		++i;					// 不管是否执行if语句，i 都会自增1，直到循环结束
	}
	*(p + j) = '\0';			//	替换完成后，把字符串的第j 个下标的位置替换成'\0',表示字符串结束

	return p;					// 返回字符串首地址指针 p 给调用函数
}
	// j = 5;  i = 7;
	// *(p + i) :"We Are Family!"
	// *(p + j) :"WeAreFamily!y!" 

int main(void)
{
	char str[] = "We Are Family!";
	printf("Now, the string is : %s\n", str);			// 打印没有修改过的字符串
	printf("After delete space : %s\n", func(str));		// 打印修改后的字符串（函数返回值 p 做为printf()函数的参数打印）
	return 0;						// 程序正常执行结束
}


5.	输入一个字符串，判断其是否是回文。(回文：即正读和反读都一样，如abcba，abba)

#include <string.h>
#include <stdio.h>
#define N 20

int func(char *p, int n)		// 形参：p 指向字符串首地址， n 表示字符串的有效长度
{
	for(int i = 0; i < n / 2; ++i)			// 循环获取字符，循环次数字符串长度的一半
		if(*(p + i) != *(p + n - 1 - i))	// 拿第i个字符和倒数第i个字符进行比较，如果不想等，则返回 0
			return 0;
	return 1;					// 循环结束都没有返回0，说明这个是回文，就返回 1 给if()
}

// gcc test.c -o test
// test abcccba
//命令行参数版本
int main1(int argc, char *argv[])	// char *argv[] 可以理解成字符串数组，每个参数当作字符串存储
{
	printf("%d\n", argc);			// argc 表示命令上面有多少个参数（包括可执行程序本身）
	if(func(argv[1], strlen(argv[1])))		// argv[] 下标从0开始， 程序本身就是 argv[0]	
		printf("Yes! %s is huiwen!\n", argv[1]);		// 如果func()返回真值，则打印这句话
	else
		printf("Nooo! %s is not huiwen!\n", argv[1]);	// 否则 打印这句话
	return 0;
}

// 普通版本
int main2(void)
{
	char str[N] = { 0 };		// 定义一个数组类型的字符串，用来存储用户输入
	printf("Plz input a string: ");
	gets(str);					// gets()函数可以接收键盘输入的字符串
	//fgets(str, N, stdin)

	if(func(str, strlen(str)))		// 调用 func()函数，同时获取str字符串的有效长度，同时做为参数传递，并接收返回值做为if判断
		printf("Yes! %s is huiwen!\n", str);		// 如果func()返回真值，则打印这句话
	else
		printf("Nooo! %s is not huiwen!\n", str);	// 否则 打印这句话
	return 0;
}		

6.	输入一段字符串，无论是否有重复元素出现，都只打印一次出现过的大写字母和小写字母，且按字母表顺序打印。（如输入AaAa!<-131->!zZzZ， 只打印A Z a z）

#include <stdio.h>
#define N 100

void func(char *str, char *temp)
{
	for(int i = 0; *(str + i) != '\0'; ++i)		// 循环遍历 str 字符串，直到字符串结尾
	{
		char ch = *(str + i);					// 定义一个字符变量接收字符，方便判断
		if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))	// 判断这个字符是否在大写字母和小写字母范围内
			*(temp + (*(str + i) - 65)) = *(str + i);			// 如果是，就放到 temp 里，可以参考 第3题解释
			// 65 是大写字母A 的ASCII码，因为是从大写字母开始存储，所以字符减去65的差，就可以做为 temp 的下标，然后再存储这个字符
	}
}

int main(void)
{ 
	char str[N] = { 0 };		// 存储用户输入的字符串
	int n = 'z' - 'A' + 1;		// 设定'A' 到 'z' 的ASCII码区间（中间有其他妖魔鬼怪）
	char temp[n] = { 0 }; 		// 存储处理过的字符串（大写字母和小写字母）
	printf("Plz input a string: ");
	gets(str);					// 接收用户键盘输入

	func(str, temp);			// 把两个字符串的地址做为函数实参传递

	for (int i = 0; i < n; ++i)	// 循环遍历 temp 字符串
		if(*(temp + i))			// 如果当前字符不为 0， 就打印出来
			putchar(*(temp + i));

	return 0;					// 程序正常结束
}



7.	输入一个用空格分隔的字符串，通过程序计算出最长的那段字符串占多少位。（如输入 1234 12345 123 12，最后得出5）

#include <stdio.h>
#define N 30

int func(char *str)
{
	int max = 0, temp = 0;				// 定义两个变量，max 存储最长的子串长度， temp 存储当前子串长度
	for(int i = 0; *(str + i); ++i)		// 循环遍历字符串，直到字符串结尾
	{
		if(*(str + i) != ' ')			// 判断当前遍历的字符，如果不是空格
			temp++;						// temp 就自增1， 直到遇到空格为止
		else							// 如果遇到了空格
		{
			if(temp > max)				// 再判断 temp 是否比 max 大，如果大
				max = temp;				// 就替换 max 的值
			temp = 0;					// 不管有没有替换， temp 都会被重置为 0
		}
	}
	return max > temp ? max : temp;		// 直到循环结束，返回max 和temp 最长的那个
}


int main(void)
{
	char str[N] = { 0 };		// 存储用户输入的字符串
	printf("Plz input a string: ");
	gets(str);					// gets() 接收键盘输入

	printf("The string long word hava %d letter.\n", func(str)); // 输出最长的子串长度
	return 0;						// 程序正常结束
}


// end!
