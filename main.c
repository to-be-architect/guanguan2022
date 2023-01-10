#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*
 * 计算平均数
 * 入参：numbers 指针数组
 */
double calculate_average(double *numbers, int length);

/*
 * 计算方差
 * 入参：numbers 指针数组
 */
double calculate_variance(double *numbers, int length);

double calculate_average2(double *numbers, int length);

double calculate_variance2(double *numbers, int length);

void test_avg_variance();

void test_avg_variance_no_ptr();

void test_avg_variance_use_ptr();

// Note that arr[] for fun is just a pointer even if square
// brackets are used
void fun(int arr[]) { // SAME AS void fun(int *arr)
    int m = sizeof(arr) / sizeof(arr[0]);
    printf("\nArray size inside fun() is %d", m);
}

void test_fun_param_ptr() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array size inside main() is %d", n);
    fun(arr);
}


void test_pp() {
    int a = 7;
    printf("%d\n", (a++) / 2); // 输出： 3
    printf("%d\n", (a++) / 2); // 输出： 4
}

void test_avg_variance() {
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // 计算数组长度（就是语言的语法规则，背下来就行了）：我们常用 sizeof(arr)/sizeof(arr[0])  来计算数组的长度。
    //其中，
    //sizeof(arr)：计算了整个数组arr占据了多少内存（字节为单位),
    //sizeof(arr[0])： 计算了数组中第一个元素所占多少字节，两者相除就是数组的长度。

    int length = sizeof(numbers) / sizeof(double);

    printf("输入数组：");
    for (int i = 0; i < length; i++) {
        printf("%.1f ", numbers[i]);
    }
    // 调用 calculate_average 函数计算平均数
    double avg = calculate_average2(numbers, length);
    // 调用 calculate_variance 函数计算方差
    double variance = calculate_variance2(numbers, length);
    printf("\n");
    printf("平均数：%.1f\n", avg);
    printf("方差：%.1f\n", variance);

//     输出：
//        数组：1.00 2.00 3.00 4.00 5.00
//        平均数：3.00
//        方差：2.00
}

void test_avg_variance_use_ptr() {
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // 计算数组长度（就是C语言的语法规则，背下来就行了）：我们常用 sizeof(arr)/sizeof(arr[0])  来计算数组的长度。
    //其中，
    //sizeof(arr)：计算了整个数组arr占据了多少内存（字节为单位),
    //sizeof(arr[0])： 计算了数组中第一个元素所占多少字节，两者相除就是数组的长度。
    int n = sizeof(numbers) / sizeof(double);

    // 1.计算平均数
    // 使用指针 p 指向数组 numbers 首地址
    double *p = numbers;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += *p;
        p++; // 指针移动，指向下一个元素
    }
    double avg = sum / n;
    printf("avg=%0.2f\n", avg);

    // 2.计算方差
    double *q = numbers; // 也可以直接复用 指针 p=numbers, 这里为了好理解，直接新声明了一个指针 q
    double variance = 0.0;
    for (int j = 0; j < n; j++) {
        variance += (*q - avg) * (*q - avg);
        q++; // 指针移动，指向下一个元素
    }

    variance = variance / n;
    printf("variance=%0.2f", variance);
}

void test_avg_variance_no_ptr() {
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // 数组长度
    int n = sizeof(numbers) / sizeof(double);

    // 计算平均数
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    double avg = sum / n;
    printf("avg=%0.2f\n", avg);

    // 计算方差
    double variance = 0.0;
    for (int j = 0; j < n; j++) {
        variance += (numbers[j] - avg) * (numbers[j] - avg);
    }
    variance = variance / n;
    printf("variance=%0.2f", variance);
}

void test_avg_variance2() {
    // 输入的数据，放到数组numbers里
    double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // 数组长度
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int m = sizeof(numbers) / sizeof(double);

    // 平均数
    double *p = numbers;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += *p;
        p++;
    }
    double avg = sum / n;
    printf("平均数：%.2f\n", avg);

    // 方差
    double variance = 0;
    // 指针复位
    p = numbers;

    for (int j = 0; j < n; j++) {
        variance += (*p - avg) * (*p - avg); //求方差: *number 是取指针指向的数组元素的值
        p++;
    }
    variance = variance / n;
    printf("方差：%.2f", variance);

}

/*
 * 计算平均数
 * 入参：numbers 指针数组 类型是double指针,指向double数组
 */
double calculate_average(double *numbers, int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += *(numbers + i);//求和
    }
    return sum / length;
}


/*
 * 计算方差
 * 入参：numbers 类型是double指针,指向double数组
 */
double calculate_variance(double *numbers, int length) {
    double variance = 0.0;
    // 平均数
    double avg = calculate_average(numbers, length);

    for (int j = 0; j < length; j++) {
        variance += (*(numbers + j) - avg) * (*(numbers + j) - avg); //求方差: *number 是取指针指向的数组元素的值
    }
    return variance / length;
}

/*
 * 计算平均数
 * 入参：numbers 指针数组 类型是double指针,指向double数组
 */
double calculate_average2(double *numbers, int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += *numbers;//求和
        numbers++; // 指针移动指向数组的下一个元素
    }
    return sum / length;
}


/*
 * 计算方差
 * 入参：numbers 类型是double指针,指向double数组
 */
double calculate_variance2(double *numbers, int length) {
    double variance = 0.0;
    // 平均数
    double avg = calculate_average(numbers, length);

    for (int j = 0; j < length; j++) {
        variance += (*numbers - avg) * (*numbers - avg); //求方差: *number 是取指针指向的数组元素的值
        numbers++;// 指针移动指向数组的下一个元素
    }
    return variance / length;
}


char to_lower_case(char ch);

int p3();

int p4();


int p4() {
    char s[] = "ABC+abc=DeF", // 字符串s，也就是字符数组s[]
    *p = s; // 指向数组s首地址的指针 p

    for (int i = 0; i < sizeof(s); ++i) {
        printf("%c", s[i]);
    }

    while (*p) { // 如果 *p 取s[]中的字符未到末尾
        *p = to_lower_case(*p); // 执行 to_lower_case(ch)函数，也就是大写转小写
        putchar(*p); // 输出 *p 字符到console控制台
        p++; // 继续遍历下一个字符的地址
    } // 经过这个 while循环之后，此时的 s = "abc+abc=def"


    for (int i = 0; i < sizeof(s); ++i) {
        printf("%c", s[i]);
    }

    putchar('\n'); // 输出换行; 记住： 此时的 s = "abc+abc=def"
    putchar(to_lower_case(s[0])); // s[0]=  a
    putchar(to_lower_case(s[3])); // s[3]=  +
    putchar(to_lower_case(s[7])); // s[7]=  =
    putchar(to_lower_case(s[8])); // s[8]=  d
    // 程序运行到这里，控制台就输出了： a+=d
    putchar('\n'); // 打印换行
    return 0;
}
// 最终输出：
/*
abc+abc=def
a+=d

 */
// 大写字母转小写
char to_lower_case(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        ch = ch - 'A' + 'a'; // 大写转小写，ASCII码，编码的码值进行加减法
    return ch;
}


// O P Q R S T U V W X Y Z
int p3() {
    char word1[15] = "SJTUSERS"; // p   S     ### J T U S E R S  因为，q="STU" 都大于等于p[0]="S"，所以，p一直都没捞着移动，q已经移动到了q="DENTS"
    char word2[15] = "STUDENTS"; // q:  S T U ### D E N T S      然后，p="SJT"(count<3) 都大于q="DENTS"的"D", 加上count<3的限制，所以，p最终移动到p="USERS"

    int count = 0;           // count: 0 0 0 1 2 3
    char *p = word1, *q = word2;

    // 这个while循环,双指针滑动比较 word1,word2字符，打印字母大的或者相等的 = max(word1[i], word2[j])
    // 如果word1>word2找到了3个字符，就停止。
    while (*p != '\0' && *q != '\0' && count < 3) { // word1，word2未结束  and  计数：循环执行3次 count=0,1,2
        if (*p > *q) { // 如果 word1 字符码值 大于 word2 字符码值（ASCII编码）
            printf("%c", *p); // 输出大的 *p 字符:  S J T
            //       对应count:  0 1 2
            p++;              // word1 的下一个字符
            count++;          // 计数加1【只针对word1】,当count=2进入循环后，count++，count=3的时候，退出循环.此时，p="USERS", q="DENTS"

        } else {
            printf("%c", *q); // 输出大的 *q 字符: S T U
            q++;              // word2 的下一个字符
        }
    } // STUSJT

    if (*p != '\0') printf("\n%s", p); // 输出剩下的 word1字符串 USERS
    if (*q != '\0') printf("\n%s", q); // 输出剩下的 word2字符串 DENTS
    return 0;
}

void test_rnd() {
    // 随机数种子
    srand(time(0));

    int number[10] = {0};
    for (int i = 0; i < 10; ++i) {
        number[i] = 11 + rand() % 9989;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ", number[i]);
    }
}

void test_arr_size() {
    int arr[] = {1, 2, (3, 4), 5};
    int length = sizeof(arr) / sizeof(int);
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(int));
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    // 16
    //4
    //1 2 4 5
}


void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 冒泡排序
void bubble_sort(int arr[], int length) {
    int flag = 0;
    for (int i = 0; i < length - 1; ++i) { // round
        for (int j = 0; j < length - 1 - i; ++j) { // 每趟比较的次数，第i趟比较 length-i 次
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                flag = 1; // 如果都没有交换，flag=0
            }
        }
        if (flag == 0) { // 如果某一趟没有交换位置，则说明已经排好序，直接退出循环
            break;
        }
    }
}

void test_bubble_sort() {
    int arr[10] = {1, 3, 2, 6, 5, 4, 7, 9, 8, 10};
    bubble_sort(arr, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    // 1 2 3 4 5 6 7 8 9 10
}

// 计算pi: pi/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...
void calculate_pi() {
    int sign;
    double pi;
    double n, t;
    t = 1;
    pi = 0;
    n = 1;
    sign = 1;
    while (fabs(t) > 1e-8) {
        pi += t;
        n += 2;
        sign = -sign;
        t = sign / n;
    }
    pi *= 4;
    printf("%f", pi);
}

// 斐波那契数列1
void fib() {
    long f1, f2;
    f1 = 1;
    f2 = 1;
    for (int i = 0; i < 10; ++i) {
        printf("%ld %ld ", f1, f2);
        f1 = f1 + f2; // f3 = f1+f2 --> f1
        f2 = f2 + f1; // f4 = f3+f2 --> f2
    }
    printf("\n");
}

// 斐波那契数列2
void fib_arr() {
    long f[20] = {1, 1};
    for (int i = 2; i < 20; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 0; i < 20; ++i) {
        printf("%ld ", f[i]);
    }

    printf("\n");
}


// 斐波那契数列3:递归
long fib_recur(int n) {
    if (n <= 1) {
        return 1;
    }
    return fib_recur(n - 1) + fib_recur(n - 2);
}

void test_fib_recur() {
    for (int i = 0; i < 20; ++i) {
        printf("%ld ", fib_recur(i));
    }
}

// 素数判断
int is_prime(int n) {
    int k = sqrt(n);
    int i;
    for (i = 2; i <= k; i++) {
        if (n % i == 0) {
            break;
        }
    }

    if (i > k) {
        return 1; // yes, n is prime number
    } else {
        return 0; //  no
    }
}

// 计算100-200之间的所有素数
void test_prime_number() {
    for (int i = 101; i <= 200; i += 2) { // 偶数不是素数，就直接判断奇数好了
        if (is_prime(i) == 1) {
            printf("%d ", i);
        }
    }
}


int max(int x, int y) {
    return x > y ? x : y;
}

// 函数指针
void test_fun_ptr() {
    /* p 是函数指针 */
    int (*p)(int, int) = &max; // &可以省略
    int a, b, c, d;

    printf("请输入三个数字:");
    scanf("%d %d %d", &a, &b, &c);

    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c);

    printf("最大的数字是: %d\n", d);
}

// 字符串操作
void test_str() {
    char str1[14] = "runoob";
    char str2[14] = "google";
    char str3[14];
    int len;

    printf("str1 :  %s\n", str1);
    printf("str2 :  %s\n", str2);
    printf("str3 :  %s\n", str3);

    /* 复制 str1 到 str3 */
    strcpy(str3, str1);
    printf("strcpy( str3, str1) , str3:  %s\n", str3);

    /* 连接 str1 和 str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2) , str1:  %s\n", str1);

    /* 连接后，str1 的总长度 */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len);
}

//编写一个程序，由用户输入一个任意字符串（长度小于 50），实现将该字符串反序，并将原字符串与反序后的字符串拼接在一起（原字符串放在前面，反序的字符串放在后面），在屏幕上输出拼接好的字符串。
//比如：如果输入字符串：abcde，则输出字符串：abcdeedcba

//求字符串长度
int chptr_strlen(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;  //指向下一指针
    }
    return count;
}

// 交换 str （i,j）位置的字符
void swap_char(char *str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// 逆序字符串
void reverse_string(char *str) {
    int left = 0;
    int right = chptr_strlen(str) - 1;
    while (left < right) {
        swap_char(str, left++, right--);
    }
}

// 镜像字符串
void mirror_str() {
    char input_str[100];
    char output_str[200];

    printf("请输入一个字符串:\n");
    gets(input_str); // 读入字符串，赋值input_str
    // strcpy到 output_str
    strcpy(output_str, input_str);
    // 逆序 input_str
    reverse_string(input_str);
    // append 逆序之后的 input_str 到 output_str
    strcat(output_str, input_str);
    // 输出 output_str
    printf("镜像字符串输出:\n");
    puts(output_str); // 用 puts 输出字符串也可以的
}

// 文件读写
// 编写一个程序，从文本文件 string.txt 中逐个读入字符，组成字符串。
//统计该字符串中字母（包括大写和小写字母）、数字和空格的个数，并将统计结果输出在屏幕上。假设文本文件 string.txt 存放在 D 盘根目录下，字符总数不超过 100，且可能含多行。
//例如 string.txt 中的内容为： /Users/bytedance/CLionProjects/untitled/data/string.txt
//Hello 50+ SJTUers,
//Welcome to the Class CS0900.
//则统计结果输出为：
//字母数：31
//数字数：6
//空格数：6

int is_letter(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

int is_number(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int is_space(char c) {
    if (c == ' ') {
        return 1;
    } else {
        return 0;
    }
}

int test_file_read() {
    FILE *f;
    f = fopen("/Users/bytedance/CLionProjects/untitled/data/string.txt", "r"); // 读文件的模式 r，这地方需要写对。w,w+,a+
    if (NULL == f) {
        printf("error!");
        return 1;
    }

    // 把文件 /Users/bytedance/CLionProjects/untitled/data/string.txt 中的内容，填充到字符数组 str[100]
    char ch;
    char str[100];
    int k = 0;
    while ((ch = fgetc(f)) != EOF) {
        str[k++] = ch;
    }
    // 按照惯用法，默认填充 '\0'
    str[k] = '\0';

    // 统计字母、数字、空格数
    int letter_count = 0, number_count = 0, space_count = 0;
    for (int j = 0; j < strlen(str); ++j) {
        char c = str[j];
        if (is_letter(c)) {
            letter_count++;
        } else if (is_number(c)) {
            number_count++;
        } else if (is_space(c)) {
            space_count++;
        }
    }

    printf("字母个数: %d\n数字个数: %d\n空格个数: %d\n", letter_count, number_count, space_count);
    //字母个数: 31
    //数字个数: 6
    //空格个数: 6

    // 关闭文件
    fclose(f);

    return 0;
}

// 写文件
// 三个比较常见的操作读（r）、写(w)和追加(a)。
//读（r）：就是将数据从文件读到程序里，这要求所处理的文件一定要存在，否则就会读取失败
//写（w）：就是将数据写入文件中，所处理的文件可以存在，也可以不存在，如果不存在就会自动创建一个新的文件，然后再将所写的数据存入文件中。但是如果文件已经存在了，并且文件里面已经有数据了，如果执行写操作，那么原有的内容就会被覆盖。
//追加（a）：跟写操作有点类似，文件可以存在也可以不存在，但是如果文件存在，并且有数据，执行写操作时（fopen(“filename”,“a”))时，所写进的数据会存在已有数据的后面，不会覆盖原有数据。
//原文链接：https://blog.csdn.net/weixin_42371679/article/details/104451537

int test_file_write() {
    FILE *fp;
    // 打开文件，append写模式
    fp = fopen("/Users/bytedance/CLionProjects/untitled/data/string.txt", "a"); // w：write, a：append

    char str[] = "\nThis is Dream IT";
    // 把 str 写入 fp 中
    fwrite(str, sizeof(str), 1, fp);

    fclose(fp);

    return 0;
}

// 题目：输入某年某月某日，判断这一天是这一年的第几天？
//程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。
void test_day_of_year() {
    int day, month, year, sum = 0, leap;
    printf("\n请输入年、月、日，格式为：年,月,日（2015,12,10）\n");
    scanf("%d,%d,%d", &year, &month, &day);  // 格式为：2015,12,10
    switch (month) // 先计算某月以前月份的总天数
    {
        case 1:
            sum = 0;
            break;
        case 2:
            sum = 31;
            break;
        case 3:
            sum = 59;
            break;
        case 4:
            sum = 90;
            break;
        case 5:
            sum = 120;
            break;
        case 6:
            sum = 151;
            break;
        case 7:
            sum = 181;
            break;
        case 8:
            sum = 212;
            break;
        case 9:
            sum = 243;
            break;
        case 10:
            sum = 273;
            break;
        case 11:
            sum = 304;
            break;
        case 12:
            sum = 334;
            break;
        default:
            printf("data error");
            break;
    }
    sum = sum + day; // 再加上某天的天数
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {// 判断是不是闰年
        leap = 1;
    } else {
        leap = 0;
    }
    if (leap == 1 && month > 2) { // *如果是闰年且月份大于2,总天数应该加一天
        sum++;
    }
    printf("这是这一年的第 %d 天。", sum);
    printf("\n");
}

// 题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//程序分析：可填在百位、十位、个位的数字都是 1、2、3、4，组成所有的排列后再去掉不满足条件的排列。
void test_combine_numbers() {
    int i, j, k;
    printf("\n");
    for (i = 1; i < 5; i++) { // 以下为三重循环:1,2,3,4
        for (j = 1; j < 5; j++) { // 1,2,3,4
            for (k = 1; k < 5; k++) { // 1,2,3,4
                if (i != k && i != j && j != k) {  // 确保i、j、k三位互不相同
                    printf("%d,%d,%d\n", i, j, k);
                }
            }
        }
    }
}

// 题目：输出9*9口诀。
//程序分析：分行与列考虑，共 9 行 9 列，i 控制行，j 控制列。
void test_9_9_table() {
    int i, j;
    printf("\n");
    for (i = 1; i < 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d*%d=%-3d", i, j, i * j); /*-3d表示左对齐，占3位*/
        }
        printf("\n"); /*每一行后换行*/
    }
}

// 题目：要求输出国际象棋棋盘。
//程序分析：国际象棋棋盘由64个黑白相间的格子组成，分为8行*8列。用i控制行，j来控制列，根据i+j的和的变化来控制输出黑方格，还是白方格
void test_chess_board() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0)
                printf("%c%c", 219, 219);
            else printf("  ");
        printf("\n");
    }
}

// 题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
//程序分析：利用for循环控制100-999个数，每个数分解出个位，十位，百位。
void narcissus_flowers() {
    int i, x, y, z;
    for (i = 100; i < 1000; i++) {

        x = i % 10;
        y = i / 10 % 10;
        z = i / 100 % 10;

        if (i == (x * x * x + y * y * y + z * z * z)) {
            printf("%d\n", i);
        }

    }
}

// 题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
//
//程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
//
//(1)如果这个质数恰等于（小于的时候，继续执行循环）n，则说明分解质因数的过程已经结束，另外 打印出即可。
//(2)但n能被k整除，则应打印出k的值，并用n除以k的商,作为新的正整数n.重复执行第二步。
//(3)如果n不能被k整除，则用k+1作为k的值,重复执行第一步。
void factor_n() {
    int n, i;
    printf("请输入整数：");
    scanf("%d", &n);
    printf("%d=", n);
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n != 1) {
                printf("*");
            }
        }
    }

    printf("\n");
    //请输入整数：986
    //986=2*17*29
}

// 题目：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
//程序分析：(a>b)?a:b这是条件运算符的基本例子。
int grade_score() {
    int score;
    char grade;
    printf("请输入分数： ");
    scanf("%d", &score);
    grade = (score >= 90) ? 'A' : ((score >= 60) ? 'B' : 'C');
    printf("%c\n", grade);
    return 0;
}

// 题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
//
//程序分析：
//
//（1）最小公倍数=输入的两个数之积除于它们的最大公约数，关键是求出最大公约数；
//
//（2）求最大公约数用辗转相除法（又名欧几里德算法）
//
//1）证明：设c是a和b的最大公约数，记为c=gcd(a,b),a>=b,
//令r=a mod b
//设a=kc，b=jc，则k，j互素，否则c不是最大公约数
//据上，r=a-mb=kc-mjc=(k-mj)c
//可知r也是c的倍数，且k-mj与j互素，否则与前述k，j互素矛盾,
//由此可知，b与r的最大公约数也是c，即gcd(a,b)=gcd(b,a mod b)，得证。
//
//2）算法描述：
//
//第一步：a ÷ b，令r为所得余数（0≤r 第二步：互换：置 a←b，b←r，并返回第一步。
int gcd() {
    int a, b, t, r, n;
    printf("请输入两个数字：\n");
    scanf("%d %d", &a, &b);
    if (a < b) {
        t = b;
        b = a;
        a = t;
    }
    r = a % b;
    n = a * b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    printf("这两个数的最大公约数是%d，最小公倍数是%d\n", b, n / b);

    return 0;
}

// 题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
//程序分析：利用while语句,条件为输入的字符不为'\n'。
int count_letter_digits() {
    char c;
    int letters = 0, spaces = 0, digits = 0, others = 0;
    printf("请输入一些字母：\n");
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            letters++;
        else if (c >= '0' && c <= '9')
            digits++;
        else if (c == ' ')
            spaces++;
        else
            others++;
    }
    printf("字母=%d,数字=%d,空格=%d,其他=%d\n", letters, digits, spaces, others);
    return 0;
}

// 题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222 (此时共有n=5个数相加)，几个数相加有键盘控制。
//程序分析：关键是计算出每一项的值。
int calculate_aaaaa() {
    int s = 0, a, n, t;
    printf("请输入 a 和 n：\n");
    scanf("%d%d", &a, &n);
    t = a;
    while (n > 0) {
        s += t;
        a = a * 10;
        t += a;
        n--;
    }
    printf("a+aa+...=%d\n", s);
    return 0;
}

// 题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数。
// 分解因子，然后判断因子之和。
int perfect_numbers() {
    const int N = 1000;
    int i, j, k, n, sum;
    int a[256]; // 记录因子

    for (i = 2; i <= N; i++) { // N 以内的所有数 i ，遍历 i 处理

        sum = a[0] = 1;
        k = 0;

        for (j = 2; j <= (i / 2); j++) {

            if (i % j == 0) { // 因子分解
                sum += j; // 因子的和
                a[++k] = j; // 每个因子，记录在数组 a[] 中
            }

        }

        if (i == sum) {
            printf("%d=%d", i, a[0]);

            for (n = 1; n <= k; n++) {
                printf("+%d", a[n]);
            }

            printf("\n");
        }

    }

    return 0;
}

// 题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
int ball_jump() {
    float h, s;
    h = s = 100;
    h = h / 2; //第一次反弹高度
    for (int i = 2; i <= 10; i++) {
        s = s + 2 * h;
        h = h / 2;
    }
    printf("第10次落地时，共经过%f米，第10次反弹高%f米\n", s, h);
    return 0;
}

// 题目：打印出如下图案（菱形）。
//    *
//  ***
// *****
//*******
// *****
//  ***
//   *
//程序分析：先把图形分成两部分来看待，前四行一个规律，后三行一个规律，利用双重for循环，第一层控制行，第二层控制列。
int print_rhombus() {
    int i, j, k;

    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 2 - i; j++) {
            printf(" ");
        }
        for (k = 0; k <= 2 * i; k++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= i; j++) {
            printf(" ");
        }
        for (k = 0; k <= 4 - 2 * i; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

// 题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
//程序分析：请抓住分子与分母的变化规律。
int sum_number_sequences() {
    int i, t;
    float sum = 0;
    float a = 2, b = 1;
    for (i = 1; i <= 20; i++) {
        sum = sum + a / b;
        t = a;
        a = a + b;
        b = t;
    }
    printf("%9.6f\n", sum);
    return 0;
}

// 题目：求1+2!+3!+...+20!的和。
//程序分析：此程序只是把累加变成了累乘。
int sum_factors() {
    int i;
    long double sum, mix;
    sum = 0, mix = 1;
    for (i = 1; i <= 20; i++) {
        mix = mix * i;
        sum = sum + mix;
    }
    printf("%Lf\n", sum);
    return 0;
}

// 题目：利用递归方法求5!。
//程序分析：递归公式：fn=fn_1*4!
int fact(int n) {
    int f;
    if (n == 0) {
        f = 1;
    } else {
        f = n * fact(n - 1);
    }
    return f;
}


// 题目：字符串反转，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。
void reverse(char *s) {
    // 获取字符串长度
    int len = 0;
    char *p = s;
    while (*p != 0) {
        len++;
        p++;
    }
    // 交换
    int i = 0;
    char c;
    while (i <= len / 2 - 1) {
        c = *(s + i);
        *(s + i) = *(s + len - 1 - i);
        *(s + len - 1 - i) = c;
        i++;
    }
}

// 题目：求一个3*3矩阵对角线元素之和
//程序分析：利用双重for循环控制输入二维数组，再将a[i][i]累加后输出。
int matrix_sum() {
    int N = 3;
    int i, j, a[N][N], sum = 0;
    printf("请输入矩阵(3*3)：\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < N; i++)
        sum += a[i][i];
    printf("对角线之和为：%d\n", sum);
    return 0;
}

// 题目：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。
//程序分析：首先判断此数是否大于最后一个数,然后再考虑插入中间的数的情况,插入后此元素之后的数,依次后移一个位置。
int insert_element() {
    int a[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
    int temp1, temp2, number, end, i, j;

    printf("原始数组是:\n");
    for (i = 0; i < 10; i++)
        printf("%4d", a[i]);

    printf("\n插入一个新的数字: ");
    scanf("%d", &number);
    end = a[9];

    if (number > end)
        a[10] = number;
    else {
        for (i = 0; i < 10; i++) {
            if (a[i] > number) {
                temp1 = a[i];
                a[i] = number;
                for (j = i + 1; j < 11; j++) {
                    temp2 = a[j];
                    a[j] = temp1;
                    temp1 = temp2;
                }
                break;
            }
        }
    }

    for (i = 0; i < 11; i++)
        printf("%4d", a[i]);

    printf("\n");

    return 0;
}

// 题目：将一个数组逆序输出。
//程序分析：用第一个与最后一个交换。

#define N 10

int reverse_array() {
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, t;
    printf("原始数组是:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    for (i = 0; i < N / 2; i++) {
        t = a[i];
        a[i] = a[N - 1 - i];
        a[N - 1 - i] = t;
    }

    printf("\n排序后的数组:\n");

    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}


#define TRUE 1
#define FALSE 0
#define SQ(x) (x)*(x)
#define exchange(a, b) { int t;t=a;a=b;b=t;}//注意放在一行里
#define LAG >
#define SMA <
#define EQ ==
#define MAX
#define MAXIMUM(x, y)(x>y)?x:y
#define MINIMUM(x, y) (x>y)?y:x

int test_define() {
    int x = 10;
    int y = 20;
    printf("x=%d; y=%d\n", x, y);
    exchange(x, y);
    printf("x=%d; y=%d\n", x, y);

    int num;
    int again = 1;
    printf("如果值小于 50 程序将终止。\n");
    while (again) {
        printf("\n请输入数字：");
        scanf("%d", &num);
        printf("该数字的平方为 %d \n", SQ(num));
        if (num >= 50)
            again = TRUE;
        else
            again = FALSE;
    }


    int i, j;
    printf("请输入两个数字：\n");
    scanf("%d %d", &i, &j);
    if (i LAG j)
        printf("%d 大于 %d \n", i, j);
    else if (i EQ j)
        printf("%d 等于 %d \n", i, j);
    else if (i SMA j)
        printf("%d 小于 %d \n", i, j);
    else
        printf("没有值。\n");


    int a = 10, b = 20;
#ifdef MAX
    printf("更大的数字是 %d\n", MAXIMUM(a, b));
#else
    printf("更小的数字是 %d\n",MINIMUM(a,b));
#endif
#ifndef MIN
    printf("更小的数字是 %d\n", MINIMUM(a, b));
#else
    printf("更大的数字是 %d\n",MAXIMUM(a,b));
#endif
#undef MAX
#ifdef MAX
    printf("更大的数字是 %d\n",MAXIMUM(a,b));
#else
    printf("更小的数字是 %d\n", MINIMUM(a, b));
#endif
#define MIN
#ifndef MIN
    printf("更小的数字是 %d\n",MINIMUM(a,b));
#else
    printf("更大的数字是 %d\n", MAXIMUM(a, b));
#endif

    return 0;
}

int test_fact() {
    int i;
    int fact(int);
    for (i = 0; i < 6; i++) {
        printf("%d!=%d\n", i, fact(i));
    }
    return 0;
}

// 题目：打印出杨辉三角形（要求打印出10行）。
// 程序分析：
//结构如下所示：
//
//1
//1    1
//1    2    1
//1    3    3    1
//1    4    6    4    1
int yanghui_triangle() {
    int i, j;
    int a[10][10];
    printf("\n");
    for (i = 0; i < 10; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (i = 2; i < 10; i++)
        for (j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    for (i = 0; i < 10; i++) {
        for (j = 0; j <= i; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    return 0;
}


// 题目：有 n个整数，使其前面各数顺序向后移 m 个位置，最后m个数变成最前面的 m 个数。
//滚动数组
void move(int array[], int n, int offset) {
    int *p, *arr_end;
    arr_end = array + n;      //数组最后一个元素的下一个位置
    int last;

    //滚动直到偏移量为0
    while (offset) {
        last = *(arr_end - 1);
        for (p = arr_end - 1; p != array; --p)   //向右滚动一位
            *p = *(p - 1);
        *array = last;
        --offset;
    }
}

//打印数组
void print_arr(int array[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%4d", array[i]);
    printf("\n");
}

int move_array() {
    int arr[20];
    int i, n, offset;
    //输入数组大小和数组内容
    printf("Total numbers?\n");
    scanf("%d", &n);
    printf("Input %d numbers.\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    //输入滚动偏移量
    printf("Set your offset.\n");
    scanf("%d", &offset);
    printf("Offset is %d.\n", offset);
    //打印滚动前数组
    print_arr(arr, n);
    //滚动数组并打印
    move(arr, n, offset);
    print_arr(arr, n);
    return 0;
}

// 题目：有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。
void circle_number() {
    int num[50], n, *p, j, loop, i, m, k;
    printf("请输入这一圈人的数量:\n");
    scanf("%d", &n);
    p = num;
    //开始给这些人编号
    for (j = 0; j < n; j++) {
        *(p + j) = j + 1;
    }
    i = 0;//i用于计数,即让指针后移
    m = 0;//m记录退出圈子的人数
    k = 0;//k报数1,2,3
    while (m < n - 1) {
        //当退出的人数不大于总人数时，即留下的人数至少是一个人
        //这句不能写成m<n,因为假设有8人，当退出了6人时，此时还是进行人数退出，即m++，
        //这时是7<8，剩下的一个人自己喊1，2,3那么他也就退出了，将不会有输出
        if (*(p + i) != 0) {
            //如果这个人的头上编号不是0就开始报数加1，这里采用的方法是报数为3的人头上编号重置为0
            k++;
        }

        if (k == 3) {
            k = 0;    //报数清零，即下一个人从1开始报数
            *(p + i) = 0;//将报数为3的人编号重置为0
            m++;    //退出人数加1
        }
        i++;      //指针后移
        if (i == n)//这句很关键，如果到了队尾，就要使指针重新指向对头
            //并且它只能放在i++后面，因为只有i++了才有可能i==n
        {
            i = 0;
        }
    }

    printf("现在剩下的人是:");
    for (loop = 0; loop < n; loop++) {
        if (num[loop] != 0) {
            printf("%2d号\n", num[loop]);
        }
    }

}

//求字符串长度
int length(char *s) {
    int i = 0;
    while (*s != '\0') {
        i++;
        s++;
    }
    return i;
}


typedef struct Student {
    char name[20];
    char sex[5];
    int age;
} Student;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList CreateList(int n) {
    LinkList L, p, q;
    int i;
    L = (LNode *) malloc(sizeof(LNode));
    if (!L)return 0;
    L->next = NULL;
    q = L;

    for (i = 1; i <= n; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        printf("请输入第%d个元素的值:", i);
        scanf("%d", &(p->data));
        p->next = NULL;
        q->next = p;
        q = p;
    }

    return L;
}

void printLinkList(LinkList h) {
    LinkList p = h->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 题目：连接两个链表。

struct list {
    int data;
    struct list *next;
};

typedef struct list node;
typedef node *link;

link delete_node(link pointer, link tmp) {
    if (tmp == NULL) /*delete first node*/
        return pointer->next;
    else {
        if (tmp->next->next == NULL)/*delete last node*/
            tmp->next = NULL;
        else /*delete the other node*/
            tmp->next = tmp->next->next;
        return pointer;
    }
}

void selection_sort(link pointer, int num) {
    link tmp, btmp;
    int i, min;
    for (i = 0; i < num; i++) {
        tmp = pointer;
        min = tmp->data;
        btmp = NULL;
        while (tmp->next) {
            if (min > tmp->next->data) {
                min = tmp->next->data;
                btmp = tmp;
            }
            tmp = tmp->next;
        }
        printf("\40: %d\n", min);
        pointer = delete_node(pointer, btmp);
    }
}

link create_list(int array[], int num) {
    link tmp1, tmp2, pointer;
    int i;
    pointer = (link) malloc(sizeof(node));
    pointer->data = array[0];
    tmp1 = pointer;
    for (i = 1; i < num; i++) {
        tmp2 = (link) malloc(sizeof(node));
        tmp2->next = NULL;
        tmp2->data = array[i];
        tmp1->next = tmp2;
        tmp1 = tmp1->next;
    }
    return pointer;
}

link concatenate(link pointer1, link pointer2) {
    link tmp;
    tmp = pointer1;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = pointer2;
    return pointer1;
}

void test_concat_linklist() {
    int arr1[] = {3, 12, 8, 9, 11};
    link ptr;
    ptr = create_list(arr1, 5);
    selection_sort(ptr, 5);
}

// 题目：输入一个整数，并将其反转后输出。
int reversed_number() {
    int n, reversedNumber = 0, remainder;

    printf("输入一个整数: ");
    scanf("%d", &n);

    while (n != 0) {
        remainder = n % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
    }

    printf("反转后的整数: %d", reversedNumber);

    return 0;
}

// 题目：编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，调用函数1/1+1/3+...+1/n(利用指针函数)。
double evenumber(int n);

double oddnumber(int n);

int sum_seq() {
    int n;
    double res;
    double (*pfunc)(int); // 函数指针

    printf("请输入一个数字：");
    scanf("%d", &n);

    if (n % 2 == 0) {
        pfunc = evenumber;
    } else {
        pfunc = oddnumber;
    }

    res = (*pfunc)(n);
    printf("%lf\n", res);

    return 0;
}

double evenumber(int n) {
    double s = 0, a = 0;
    int i;
    for (i = 2; i <= n; i += 2) {
        a = (double) 1 / i;
        s += a;
    }
    return s;
}

double oddnumber(int n) {
    double s = 0, a = 0;
    int i;
    for (i = 1; i <= n; i += 2) {
        a = (double) 1 / i;
        s += a;
    }
    return s;
}

// 题目：指向指针的指针
int ptr_ptr_demo() {
    const char *s[] = {"man", "woman", "girl", "boy", "sister"};
    const char **q;
    int k;
    for (k = 0; k < 5; k++) {
        q = &s[k];
        printf("%s\n", *q);
    }
    return 0;
}

// 题目：找到年龄最大的人，并输出。请找出程序中有什么问题。
typedef struct man {
    char name[20];
    int age;
} man;

int max_age_man() {

    man person[3] = {"li", 18, "wang", 25, "sun", 22};
    man *q, *p;

    int i, m = 0;
    p = person;
    for (i = 0; i < 3; i++) {
        if (m < p->age) {
            m = p->age;
            q = p; // max age person
        }
        p++;
    }
    printf("%s %d\n", q->name, q->age); // wang 25
    return 0;
}

// 题目：字符串排序。
void swap_char_ptr(char *str1, char *str2);

int sort_str() {
    char str1[20], str2[20], str3[20];
    printf("请输入3个字符串,每个字符串以回车结束!:\n");
    fgets(str1, (sizeof str1 / sizeof str1[0]), stdin);
    fgets(str2, (sizeof str2 / sizeof str2[0]), stdin);
    fgets(str3, (sizeof str3 / sizeof str3[0]), stdin);

    if (strcmp(str1, str2) > 0)swap_char_ptr(str1, str2);
    if (strcmp(str2, str3) > 0)swap_char_ptr(str2, str3);
    if (strcmp(str1, str2) > 0)swap_char_ptr(str1, str2);

    printf("排序后的结果为：\n");

    printf("%s\n%s\n%s\n", str1, str2, str3);

    return 0;
}

void swap_char_ptr(char *str1, char *str2) {
    char tem[20];
    strcpy(tem, str1);
    strcpy(str1, str2);
    strcpy(str2, tem);
}

// 题目：海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子平均分为五份，多了一个，
// 这只 猴子把多的一个扔入海中，拿走了一份。
// 第二只猴子把剩下的桃子又平均分成五份，又多了 一个，它同样把多的一个扔入海中，拿走了一份，
// 第三、第四、第五只猴子都是这样做的， 问海滩上原来最少有多少个桃子？
int monkey_pitch() {
    int x
    , i = 0, j = 1;
    while (i < 5) {
        x = 4 * j;
        for (i = 0; i < 5; i++) {
            if (x % 4 != 0) { break; }
            x = (x / 4) * 5 + 1;
        }
        j++;
    }
    printf("%d\n", x);

    return 0;
}

// 题目：809*??=800*??+9*?? 其中??代表的两位数, 809*??为四位数，8*??的结果为两位数，9*??的结果为3位数。求??代表的两位数，及809*??后的结果。
void output(long int b, long int i) {
    printf("\n%ld = 800 * %ld + 9 * %ld\n", b, i, i);
}

int solve_formula() {
    void output(long int b, long int i);
    long int a, b, i;
    a = 809;
    for (i = 10; i < 100; i++) {
        b = i * a;
        if (b >= 1000 && b <= 10000 && 8 * i < 100 && 9 * i >= 100) {
            output(b, i);
        }
    }
    return 0;
}

// 题目：八进制转换为十进制
int ox2de() {
    int n = 0, i = 0;
    char s[20];
    printf("请输入一个8进制数:\n");
    gets(s);

    while (s[i] != '\0') {
        n = n * 8 + s[i] - '0';
        i++;
    }

    printf("刚输入的8进制数转化为十进制为\n%d\n", n);

    return 0;
}

//题目：求0—7所能组成的奇数个数。
//
//程序分析：
//
//这个问题其实是一个排列组合的问题，设这个数为 sun=a1a2a3a4a5a6a7a8,a1-a8 表示这个数的某位的数值，当一个数的最后一位为奇数时，那么这个数一定为奇数，不管前面几位是什么数字。如果最后一位数为偶数，则这个数一定为偶数。
//
//a1-a8可以取 0-7 这个八个数字，首位数字不为 0。
//
//从该数为一位数到该数为8位数开始统计奇数的个数：
//
//1.当只有一位数时也就是该数的最后一位，奇数个数为4
//2.当该数为两位数时，奇数个数为4*7=28
//3.当该数为三位数时，奇数个数为：4*8*7=224
//...
//8.当该数为八位数时，奇数个数为：4*8*8*8*8*8*8*7(依次为最后一位到第一位)
int ode_combinations(int agrc, char *agrv[]) {
    long sum = 4, s = 4;//sum的初始值为4表示，只有一位数字组成的奇数个数为4个
    int j;
    for (j = 2; j <= 8; j++) {
        printf("%d位数为奇数的个数%ld\n", j - 1, s);
        if (j <= 2)
            s *= 7;
        else
            s *= 8;
        sum += s;
    }
    printf("%d位数为奇数的个数%ld\n", j - 1, s);
    printf("奇数的总个数为：%ld\n", sum);
    // system("pause");
    return 0;
}

//题目：一个偶数总能表示为两个素数之和。
//程序分析：我去，这是什么题目，要我证明这个问题吗？真不知道怎么证明。那就把一个偶数分解成两个素数吧。
int is_primer(unsigned int n);

int decomposed_two_prime_numbers() {
    unsigned int n, i;

    do {
        printf("请输入一个偶数:\n");
        scanf("%d", &n);
    } while (n % 2 != 0);

    for (i = 1; i < n; i++) {
        if (is_primer(i) && is_primer(n - i)) {
            break;
        }
    }

    printf("偶数%d可以分解成%d和%d两个素数的和\n", n, i, n - i);

    return 0;
}

// 题目：判断一个素数能被几个9整除。
//程序分析：丫的！这题目的意思是判断一个素数能整除几个9组成的数吧？我就这么理解吧。素数是不 能被除1和自身之外的数整除的
int prime_999() {
    int p, i;
    long int sum = 9;
    printf("请输入一个素数:\n");
    scanf("%d", &p);
    for (i = 1;; i++)
        if (sum % p == 0)break;
        else sum = sum * 10 + 9;

    printf("素数%d能整除%d个9组成的数%ld\n", p, i, sum);
    return 0;
}

// 题目：两个字符串连接程序 。
char *strconnect(char *str1, char *str2);

int str_cat() {
    char str1[20], str2[20];
    char *str;

    puts("请输入两个字符串，用回车分开:");

    scanf("%s%s", str1, str2);

    str = strconnect(str1, str2);

    puts("连接后的字符串为:");

    puts(str);

    return 0;
}

char *strconnect(char *str1, char *str2) {
    char *str;
    str = (char *) malloc(strlen(str1) + strlen(str2) + 1);
    str[0] = '\0';

    strcat(str, str1);
    strcat(str, str2);

    return str;
}

struct student {
    int x;
    char c;
} a;

void fn_struct(struct student b) {
    b.x = 20;
    b.c = 'y';
}

int test_struct_param() {
    a.x = 3;
    a.c = 'a';
    fn_struct(a);
    printf("%d,%c", a.x, a.c);
    return 0;
}

// 题目：某个公司采用公用电话传递数据，数据是四位的整数，
// 在传递过程中是加密的，加密规则如下：
// 每位数字都加上5,然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。
int cypher_test() {
    int a, i, aa[4], t;
    printf("请输入四位数字：");
    scanf("%d", &a);
    aa[0] = a % 10;
    aa[1] = a % 100 / 10;
    aa[2] = a % 1000 / 100;
    aa[3] = a / 1000;
    for (i = 0; i <= 3; i++) {
        aa[i] += 5;
        aa[i] %= 10;
    }
    for (i = 0; i <= 3 / 2; i++) {
        t = aa[i];
        aa[i] = aa[3 - i];
        aa[3 - i] = t;
    }
    printf("加密后的数字：");
    for (i = 3; i >= 0; i--)
        printf("%d", aa[i]);
    printf("\n");
    return 0;
}

// 题目：猜谜游戏。

void caizi(void) {
    int n;
    char begin;
    int count = 1;
    srand((int) time(NULL));
    int m = (rand() % 100) + 1;
    puts("游戏开始，请输入数字:");
    while (1) {
        scanf("%d", &n);
        if (n == m) {
            printf("猜中了，使用了 %d 次！\n", count);
            if (count == 1) {
                printf("你是神级人物了！膜拜\n");
                getchar();
                printf("你已经达到最高级别，还需要玩吗？Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y')      //重复玩的一个嵌套循环
                {
                    caizi();
                } else {
                    printf("谢谢，再见!\n");
                }
            } else if (count <= 5) {
                printf("你是王级人物了！非常赞\n");
                getchar();
                printf("需要挑战最高级别不？Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y') {
                    caizi();
                } else {
                    printf("谢谢，再见!\n");
                }
            } else if (count <= 10) {
                printf("你是大师级人物了！狂赞\n");
                getchar();
                printf("需要挑战最高级别不？Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y') {
                    caizi();
                } else {
                    printf("谢谢，再见!\n");
                }
            } else if (count <= 15) {
                printf("你是钻石级人物了！怒赞\n");
                getchar();
                printf("需要挑战最高级别不？Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y') {
                    caizi();
                } else {
                    printf("谢谢，再见!\n");
                }
            } else {
                getchar();
                printf("你的技术还有待提高哦！重玩？ Y/N\n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y') {
                    caizi();
                } else {
                    printf("谢谢，再见!\n");
                }
            }
            break;
        } else if (n < m) {
            puts("太小了!");
            puts("重新输入:");
        } else {
            puts("太大了!");
            puts("重新输入:");
        }
        count++;//计数器


    }
}


int is_primer(unsigned int n) {
    int i;
    if (n < 4)return 1;
    else if (n % 2 == 0)return 0;
    else
        for (i = 3; i < sqrt(n) + 1; i++)
            if (n % i == 0)return 0;

    return 1;
}

//题目：计算字符串中子串出现的次数。
int count_substr() {
    int i, j, k, TLen, PLen, count = 0;
    char T[50], P[10];
    printf("请输入两个字符串，以回车隔开，母串在前，子串在后：\n");

    gets(T);
    gets(P);

    TLen = strlen(T);
    PLen = strlen(P);

    for (i = 0; i <= TLen - PLen; i++) {
        for (j = 0, k = i; j < PLen && P[j] == T[k]; j++, k++) { // P[j]==T[k]
        }
        if (j == PLen) { // P是T的字串
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

// 题目：从键盘输入一些字符，逐个把它们送到磁盘上去，直到输入一个#为止。
int gets_write_file() {
    FILE *fp = NULL;
    char filename[25];
    char ch;

    printf("输入你要保存到的文件的名称：\n");

    gets(filename);

    if ((fp = fopen(filename, "w")) == NULL) {
        printf("error: cannot open file!\n");
        exit(0);
    }

    printf("现在你可以输入你要保存的一些字符，以#结束：\n");

    getchar();

    while ((ch = getchar()) != '#') {
        fputc(ch, fp);
    }

    fclose(fp);

    return 0;
}

// 将小写字母转换成大写字母
char upper(char c) {
    return c - 32;
}

// 将大写字母转换成小写字母
char lower(char c) {
    return c + 32;
}

void test_upper_lower() {
    printf("%c\n", upper('a'));
    printf("%c\n", lower('B'));
}

// 题目：有两个磁盘文件A和B,各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件C中。
//
//程序分析：你需要先创建 A.txt 与 B.txt。
//
//A.txt文件内容：
//
//123
//B.txt文件内容：
//
//456

int concat_file_content() {
    FILE *fa, *fb, *fc;
    int i, j, k;
    char str[100], str1[100];
    char tem;

    if ((fa = fopen("/Users/bytedance/CLionProjects/untitled/data/A.txt", "r")) == NULL) {// A.txt 文件需要存在
        printf("error: cannot open A file!\n");
        exit(0);
    }

    fgets(str, 99, fa);

    fclose(fa);

    if ((fb = fopen("/Users/bytedance/CLionProjects/untitled/data/B.txt", "r")) == NULL) {// B.txt 文件需要存在
        printf("error: cannot open B file!\n");
        exit(0);
    }

    fgets(str1, 100, fb);

    fclose(fb);

    strcat(str, str1);

    // 排序
    for (i = strlen(str) - 1; i > 1; i--) {
        for (j = 0; j < i; j++) {
            if (str[j] > str[j + 1]) {
                tem = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tem;
            }
        }
    }

    if ((fc = fopen("/Users/bytedance/CLionProjects/untitled/data/C.txt", "w")) == NULL) {  // 合并为 C.txt
        printf("error: cannot open C file!\n");
        exit(0);
    }

    fputs(str, fc);

    fclose(fc);
    return 0;
}


// 题目：有五个学生，每个学生有3门课的成绩，从键盘输入以上数据（包括学生号，姓名，三门课成绩），
// 计算出平均成绩，况原有的数据和计算出的平均分数存放在磁盘文件"stud"中。
typedef struct MyStudent {
    int ID;
    int math;
    int English;
    int C;
    int average;
    char name[20];
} MyStudent;  // 自定义类型 MyStudent

// 冒泡排序
void bubble_sort_average(MyStudent s[], int size) {
    int flag;
    MyStudent tmp;

    for (int i = 1; i < size; ++i) {
        // 交换标志
        flag = 0;
        for (int j = 0; j < size - i; ++j) {
            if (s[j].average < s[j + 1].average) { // 按照平均分排序
                // swap s[j],s[j+1]
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;

                flag = 1;
            }
        }

        if (flag == 0) break;

    }

}

int student_scores() {

    FILE *fp;
    int i, avg = 0;
    const int SIZE = 5;

    // MyStudent stu[5]; // 数组声明的方式
    MyStudent *stu; // 使用指针，内存分配
    stu = (MyStudent *) calloc(SIZE, sizeof(MyStudent));

    printf("请输入5个同学的信息：学生号，姓名，3门成绩:\n");
/*
1 a 60 70 80
2 b 60 80 90
3 c 59 39 89
4 e 56 88 98
5 d 43 88 78
 */

    for (i = 0; i < SIZE; i++) {

        scanf("%d %s %d %d %d",
              &(stu[i].ID),
              stu[i].name,
              &(stu[i].math),
              &(stu[i].English),
              &(stu[i].C)
        );

        // 平均分
        stu[i].average = (stu[i].math + stu[i].English + stu[i].C) / 3;
    }

    bubble_sort_average(stu, SIZE);

    if ((fp = fopen("stud", "w")) == NULL) {
        printf("error :cannot open file!\n");
        exit(0);
    }

    for (i = 0; i < SIZE; i++) {
        fprintf(fp, "%d %s %d %d %d %d\n",
                stu[i].ID,
                stu[i].name,
                stu[i].math,
                stu[i].English,
                stu[i].C,
                stu[i].average);
    }

    // stud 文件内容：
    /*
4 e 56 88 98 80
2 b 60 80 90 76
1 a 60 70 80 70
5 d 43 88 78 69
3 c 59 39 89 62
     */

    fclose(fp);

    return 0;
}

// 字符串排序
int sort_str_arr() {
    const int LENGTH = 10;
    int i, j;
    char str[LENGTH][50], temp[50];

    printf("输入10个单词:\n");
/*
C
Java
C++
PHP
Python
Perl
Ruby
R
JavaScript
PHP
*/

    for (i = 0; i < LENGTH; ++i) {
        scanf("%s[^\n]", str[i]);
    }

    for (i = 0; i < LENGTH - 1; ++i) {
        for (j = i + 1; j < LENGTH; ++j) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\n排序后: \n");

    for (i = 0; i < 10; ++i) {
        puts(str[i]);
    }
/*
C
C++
Java
JavaScript
PHP
PHP
Perl
Python
R
Ruby
 */

    return 0;
}

void pro1() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int i = 0, j, s = 0;
    while (i++ < 5) {
        if (i % 2 == 0) continue;
        for (j = i; j < 6; j += 2)
            s += a[j];
        printf("i=%d s=%d\n", i, s);
    }
}

void pro2() {
    int number = 56789;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num = number % 10;
            printf("%d", num);
        }
        number /= 10;
        printf("\n");
    }
}

#define square_sum(x, y) x*x+y*y

void pro3() {
    int x = 1, y = 2;
    printf("%d\n", x * x + y * y);
    printf("%d\n", square_sum(x, y));
    printf("%d\n", square_sum(x + 1, y));
    printf("%d\n", square_sum(x, y + 1));
}

void pro4() {
    int x = 1, y = 3, z = 4;
    switch (x < y) {
        case 1:
            while (1) {
                if (z < y) break;
                printf("%d ", (x++) + (--z));
            }
        case 2:
            printf("%d %d %d\n", x, y, z);
            break;
        default:
            printf("ok\n");
    }
}

void shift(int a[], int n, int idx) {
    static int s = 3;
    a[idx] += a[s % n];
    s++;
}

void pro5() {
    int a[5] = {12, 3, 5, 16, 35}, i;
    for (i = 0; i < 3; i++)
        shift(&a[i], 5 - i, i);
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
}

char *func(char *s1, char *s2);

char *func(char *s1, char *s2) {
    char *res, temp;
    int i = 0;
    res = (char *) malloc(strlen(s1) + strlen(s2) + 1);
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 > *s2) {
            res[i++] = *s2;
            temp = *s1;
            *s1 = *s1 - *s2 + '0';
            *s2 = temp;
        } else {
            res[i++] = *s1;
            *s1 = *s2 - *s1 + '0';
        }
        s1++;
        s2++;
    }
    res[i] = '\0';
    return res;
}

void pro6() {
    char a[] = "Ujtxex", b[] = "Sjvukres", *s;
    s = func(a, b);
    printf("%s\n%s\n%s", s, a, b);
    free(s);
}

/*
 * 取任一个数，如 43005798，其中偶数个数是 4，奇数个数是 4，是 8 位
数，可以组成一个新的数 448；该数（448）有 3 个偶数，0 个奇数，是 3 位数，又
可以组成一个新的数 303；303 有 1 个偶数，2 个奇数，是 3 位数，便得到一个新的
数 123。反复重复以上程序，始终是 123，得不到新的数了。对任何一个数重复以上
过程都会得到 123，由此 123 被称为西西弗斯数。
编写一个程序，输入一个自然数，输出西西弗斯数的转换过程。【只要实现不超过 10
位的数】
 */
int sisyphus_number(int n) {
    int odd = 0, even = 0, numn, orgin = n;

    while (n != 0) {
        //统计奇数偶数个数
        if (n % 10 % 2 != 0) {
            even++;
        } else {
            odd++;
        }
        n = n / 10;
    }
    numn = odd * 100 + even * 10 + (odd + even); //重写新数
    if (numn != orgin) {
        printf("->%d", numn);
        sisyphus_number(numn);
    }
    return 0;
}


// 题目：输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。
void max_min_arr(int *s, int n) {
    int i;
    int max = s[0];
    int a = 0;
    for (i = 0; i < n; i++) {
        if (s[i] > max) {
            max = s[i];
            a = i;
        }
    }

    // 最大的与最后一个数交换
    s[a] = s[n - 1];
    s[n - 1] = max;

    int j;
    int min = s[n - 1];
    int b = n - 1;
    for (j = 0; j < n; j++) {
        if (s[j] < min) {
            min = s[j];
            b = j;
        }
    }

    // 最小的与第一个数交换
    s[b] = s[0];
    s[0] = min;

}

void printf_s(int *s, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", s[i]);
    printf("\n");
}

int test_max_min_array() {
    int *s;
    int i, n;
    printf("请输入要处理的数据个数:");
    scanf("%d", &n);
    // 动态分配内存
    s = (int *) calloc(n, sizeof(int));

    printf("请输入 %d 个整数:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    max_min_arr(s, n);
    printf("交换后的数据顺序为:");
    for (i = 0; i < n; i++)
        printf("%d ", s[i]);

    return 0;
}

// 提取字符串中的英文字母
int *extract(char *str1) {
    int len = strlen(str1);
    char *str2;
    str2 = (char *) calloc(len, sizeof(char));

    int i = 0, j = 0;//定义两个整形变量并初始化为0
    while (*(str1 + i) != '\0') { //当我们需要提取的字符串没有到达串结束符， 就可以提取，那么就会进入循环进行数字的提取
        if ((*(str1 + i) >= 'A' && *(str1 + i) <= 'Z') || (*(str1 + i) >= 'a' && *(str1 + i) <= 'z')) {
            *(str2 + j++) = *(str1 + i); //如果是一个数字字符，就将该字符保存到另外一个字符串str2中;注意j一定要自加，每进行一次，就应该指向下一个字符了
        }
        i++; //指向下一个位置
    }
    *(str2 + j) = '\0';//字符串的末尾需要加一个串结束符来表示字符串的结束
    strcpy(str1, str2);
    return 0;
}

// 判断回文字符串
int isPalindrome(char *p) {
    int len = strlen(p); //使用STRLEN函数取字符串数组的字符位数

    for (int i = 0; i <= len; i++) {
        if (p[i] == p[len - 1]) {
            len--; //若首尾两个字符等值，分别向字符串中心移动一位，并判断
        } else
            return 0;
    }
    return 1;
}

int problem3() {
    char str[50];
    printf("请输入一个字符串（长度<50）：");
    //字符串输入
    int k = 0;
    while (1) {
        str[k] = getchar(); //从键盘读取字符
        if (str[k] == '\n') { //如果输入回车赋值读取结束
            break;
        }
        k++;
    }
    // 按照惯用法，默认填充 '\0'
    str[k] = '\0';
    extract(str);
    if (isPalindrome(str))
        printf("%s 是回文字符串\n", str);
    else
        printf("%s 不是回文字符串\n", str);
    return 0;
}


// main 函数
int main() {
//    printf("%d", isPalindrome("aBa"));

    problem3();



//    test_max_min_array();

//    int n; //定义整型变量
//    printf("请输入一个整数："); // 23456008
//    scanf("%d", &n);
//    printf("%d", n);
//    sisyphus_number(n);

//    pro1();
//    pro2();
//    pro3();
//    pro4();
//    pro5();
//    pro6();
//    int *p;
//    int n = 10;
//    p = (int *) calloc(n, sizeof(int));

//    int a=3; printf("%d-%d\n", (a=a*5,a=a/4,a+1),a );

//    int a=rand()%100, b=100+rand()%100;
//    int max=(a==b)?0:1;
//    printf("%d",max);




//    char str1[] = "SpringSummerFallWinter", str2[] = "ll";
//    printf("%s",strstr(str1,str2));
//    int a[3][4] = { {1, 2}, {3, 4}, {5, 6, 7}};
//    printf("%d", a[1][2]);
//    int a, b, c, *d = &c;
//    scanf("%d%d%d", &a, &b, d);
//
//    printf("%d %d %d", a, b, c);

//    int a = 100;
//    char b = 'A';
//    short c = 22;
//    double d = 0.6, e;
//    e = a + b + c + d;
//    int a[2][5];
//    printf("%d ",sizeof (int));
//    printf("%d",sizeof (a[0]));

//    char *p;
//    if (p==NULL){
//
//    }
//
//    if(p!=NULL){
//
//    }


//    int k,a,b;
//    unsigned long w= 5;
//    double x=1.42;
//
//    int z=x%3;
//    w += -2;
//    k = (a=2,b=3,a+b) ;
//    a+=(a-=((b=4) * (a=3)));
//    char 2a = '\0';
//    char _a[2] = {'1'};
//    char a4[] = '123';
//    char a3 = "\1";
//    printf("%s",_a);

//    char * pt1 = "1234", pt2[ ] = "12", * pt3 = "34";
//    pt3 = pt1;
//    pt2 = pt1;
//    strcpy(pt2, pt3);
//    printf("%s", pt2);
//    char s[]="159", * p = s;
//    printf("%c", *(p++));
//    printf("%c", ++(*p));
//    int k = 10;
//    int count=0;
//    while ( k = 0 ){
//        k = k - 1;
//        count++;
//    }
//    printf("%d\n", count);


//    int x, y;
//    int count=0;
//    for (x = 0, y = 3; (y < 17) && (x < 7); x++, y += x){
//        count++;
//    }
//    printf("%d\n", count);
//    char s[12]={"abcdef"};
//    printf("%d\n", strlen(s));
//    int a, b;
//    int c = (a = 5, b = 2, a > b ? a++ : b++, a + b);
//    printf("%d", c);
//    int a = 15;
//    a += a -= a * a;
//    printf("%d", a);

//    int m = 5;
//    if (m++ > 5)
//        printf("%d\n", m);
//    else
//        printf("%d\n", m--);
//    int a=1,b=2,c=3;
//    if ( (a=c)&&(b=c)){
//
//    }
//    printf("%d,%d,%d",a,b,c);

//    float a = 0.1e0;
//    int a=10,b=10,c=10;
//    float f;
//    scanf("%f", &f);
//    printf("%f",f);

//    sort_str_arr();

// student_scores();
//    test_upper_lower();
//    gets_write_file();
//    count_substr();
//    max_age_man();
//    sum_factors();
//    sum_number_sequences();
//    print_rhombus();
//    perfect_numbers();
//    factor_n();
//    narcissus_flowers();
//    fib_recur(10);
//    fib_arr();
//    test_fun_ptr();
//    mirror_str();
//    test_prime_number();
//    test_file_read();
//    test_file_write();
//    test_day_of_year();
//    test_9_9_table();
//    test_chess_board();

    return 0;
}




