#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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


// 斐波那契数列2:递归
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

// main 函数
int main() {
    test_prime_number();
}



