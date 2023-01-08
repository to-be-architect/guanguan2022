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

int main() {
//    fib_recur(10);
//    fib_arr();
//    test_fun_ptr();
//    mirror_str();
//    test_prime_number();
//    test_file_read();
//    test_file_write();

    return 0;
}




