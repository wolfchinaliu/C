#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
//int a;//变量在头部就已经声明了，但是定义和初始化都是在主函数中
//int b;
//char c;
//float f;
//int et;
//int max(int, int);
//void swap(int, int);
//extern void test();
//int si,sj;
//int s = 100;
//int *p;
//int max(int x, int y){
//    return x>y?x:y;
//}
/**共用体**/
union Data{
    int i;
    float f;
    char ch[20];
};
/**结构体*/
struct Books{
    char name[50];
    char author[100];
    char subject[100];
    int bookId;
} book3;

struct demo2{
    unsigned int bookId;
    unsigned int bookId2;
} demo2;
/**位域**/
typedef struct Test{
    int i;
    float f;
} test;
struct demo{
    unsigned int bookId:1;
    unsigned int bookId2:1;
} demo;
#define TRUE 1
#define FALST 0
extern int errno;
/**#define可以对类型进行扩展，typedef不行**/
void printBook(struct Books *books);
/**递归函数***/
double factorial(double i){
    if(i<=1){
        return 1;
    }else{
        return i*factorial(i-1);
    }
}
int main(){
    printf("请输入值：");
    int ii ;
    scanf("%d\n", &ii);
    printf("%d的阶乘值为：%d\n",ii,factorial(ii));
    char student[100];
    char *st;
    strcpy(student,"this is student");
    st = malloc(200 * sizeof(char));
    if(st==NULL){
        fprintf(stderr, "Error unable to allocate required merory\n");
    }else{
        strcpy(st, "this is students ");
    }
    st = realloc(st, 300 * sizeof(char));
    printf("student:%s\n",st);
    free(st);
    printf("TRUE的值:%d\n",TRUE);
    printf("FALST的值:%d\n",FALST);
    test t1;
    t1.f = 2.43f;
    printf("t1.f:%f\n",t1.f);
    t1.i = 3;
    printf("t1.i:%d\n",t1.i);
    union Data data;
    printf("data的空间大小为：%lu\n", sizeof(data));
    data.i = 10;
    data.f = 22.4f;
    strcpy(data.ch, "hello");
    printf("data.i:%d\n", data.i);
    printf("data.f:%f\n", data.f);
    printf("data.ch:%s\n", data.ch);
    data.i = 10;
    printf("data.i:%d\n", data.i);
    data.f = 22.4f;
    printf("data.f:%f\n", data.f);
    strcpy(data.ch, "hello");
    printf("data.ch:%s\n", data.ch);
    struct Books books1;
    struct Books books2;
    strcpy(books1.author,"tiger");
    strcpy(books1.name,"java");
    strcpy(books1.subject,"computer");
    books1.bookId = 10012312321;
    strcpy(books2.author,"jerry");
    strcpy(books2.name,"PHP");
    strcpy(books2.subject,"computerSize");
    books2.bookId = 33334234;
    printBook(&books1);
    printBook(&books2);
    printf("demo.bookId:%lu\n", sizeof(demo));
    printf("demo2.bookId:%lu\n", sizeof(demo2));
    /**读取和写入文件**/
//    FILE *fp = NULL;
//    fp = fopen("/temp/a.txt", "w+");
//    fprintf(fp, "this is c program\n");
//    fputs("this is fputs methos write file\n", fp);
//    fclose(fp);
//    FILE *fp = NULL;
//    fp = fopen("/Users/tiger/Code/CLionWork/temp/a.txt", "w+");//这个路径直接复制才可以，应该是绝对路径
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);
//    fclose(fp);
    FILE *file = NULL;
    file = fopen("/Users/tiger/Code/CLionWork/temp/a.txt","r");
    char buff[200];
    fscanf(file, "%s", buff);
    printf("%s\n",buff);
    fgets(buff, 200,file);
    printf("%s",buff);
    fgets(buff, 200,file);
    printf("%s",buff);
    fclose(file);
    /**预处理器**/
    printf("File:%s\n",__FILE__);
    printf("Date:%s\n",__DATE__);
    printf("Time:%s\n",__TIME__);
    printf("Line:%d\n",__LINE__);
   // printf("FILE:%s\n",____);
    /**输入和输出**/
    /**异常处理**/
    int errorNum;
    FILE * file2 ;
    file2 = fopen("/Users/tiger/Code/CLionWork/temp/b.txt", "rb");
    if(file2==NULL){
        errorNum = errno;
        fprintf(stderr, "错误号：%d\n", errno);
        perror("通过perror输出错误\n");
        fprintf(stderr, "打开文件错误：%s\n", strerror(errorNum));
    }else{
        fclose(file2);
    }
//    char cc[20];
//    printf("press Entry:");
//    gets(cc);
//    printf("\n You entry:");
//    puts(cc);

//    int cs=0;
//    printf("pree Enter a value");
//    printf("\n You enter :");
//    while (cs!=97){
//        cs = getchar();
//        putchar(cs);
//        printf("\n");
//    }

//    /*指针加加表示地址往后移动一位*/
//    int arr[] = {10,100,211};
//    int i,*pr;
//    pr = arr;
//    int max = 3;
//    for (int j = 0; j < max; ++j) {
//        printf("arr[%d]:%d\n",j,*pr);
//        printf("arr[%d]的地址为：%p\n",j,pr);
//        pr++;
//    }
//    /*指针减减表示指向的地址往前移动一位*/
//    int max2 = 4;
//    int arr2[] = {1,3,4,59};
//    int l,*pl;
//    pl = &arr2[max2 - 1];
//    for (int k = max2; k >0; k--) {
//        printf("arr2[%d]:%d\n",k,*pl);
//        printf("arr2[%d]:地址为：%p\n",k,pl);
//        pl--;
//    }
//    /**比较指针**/
//    int arr3[]={20,40,55,99};
//    int ii,*pp;
//    pp = arr3;
//    for (int m = 0; m < 4; ++m) {
//        if (pp<=&arr3[m]){
//            printf("arr3[%d]:%d\n",m,*pp);
//            printf("arr3[%d]:地址为：%p\n",m,pp);
//        }
//        pp++;
//    }
//    /**函数指针**/
//    int (*p)(int,int)=&max;
//    int a,b,c,d;
//    printf("请输入三个数字：");
//    scanf("%d,%d,%d",&a,&b,&c);
//    d = p(a,p(b,c));
//    printf("最大值：%d",d);
//    int a = 1;
//    int b = 2;
//    int c = 'char';
//    float f = 3.14f;
//    printf("a为：%d \n", a);
//    printf("b为：%d \n", b);
//    printf("c为：%d \n", c);
//    printf("f为：%f \n", f);
//    et = 5;
//    test();
//    printf("int的长度为： %lu \n", sizeof(int));
//    printf("简单的测试一下Test \n");
//    printf("Float的最大值为：%E \n",FLT_MAX );
//    printf("Float的最小值为：%E \n",FLT_MIN );
//    printf("float的精确度：%d \n",FLT_DIG);//6位
//    long l,j;
//    scanf("%lu%lu", &l,&j);
//    scanf("%lu%lu", &si,&sj);
//
//    printf("i:%lu %lu\n", l,j);
//    printf("max:%lu\n",max(l,j));
//    printf("交换前： a:%lu,b:%lu\n", si, sj);
//
//    swap(si, sj);
//
//    printf("交换后： a:%lu,b:%lu\n", si, sj);
//    int sum(int, int);
//    int s = sj;
//    int ss = sum(si,s);
//    printf("s:%lu\n",ss);
//      int arr[5];
//      int i = 5;
//    for (int j = 0; j < i; ++j) {
//        arr[j] = j+10;
//    }
//    for (int k = 0; k < 5; ++k) {
//        printf("Element[%d]\n", arr[k]);
//    }
//    int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,22};//表示三行四列
//    for (int l = 0; l < 3; ++l) {
//        for (int j = 0; j < 4; ++j) {
//            printf("Element[%d][%d]:%d\n",l,j,arr2[l][j]);
//        }
//    }
//    //char s = 'hello';
//    printf("i的地址为：%p\n",&i);
//    printf("s的地址为：%p\n",&s);
//    printf("p指针的地址为:%lu\n",NULL);
//    if(!p){
//        printf("p指针的地址为:%lu\n",p);
//    }
//    while (l !=2){
//        printf("l:%d\n", l);
//        l++;
//    }
//    do{printf("sss");}while(l==100);
    /**字符串的常用操作**/
//    char a[]="hello";
//    char b[]="world";
//    char c[20];
//    strcpy(c,a);//复制a到c
//    strcat(c,b);
//    int len = strlen(c);
//    printf("len:%d\n",len);
//    int *ppp = strstr(c,a);
//    printf("ppp的地址：%p\n", ppp);
//    printf("ppp的地址：%d\n", *ppp);
//    printf("c:%s\n",c);
    return 0;

}
void printBook(struct Books *books){
    printf("Book.name:%s\n", books->name);
    printf("Book.author:%s\n", books->author);
    printf("Book.subject:%s\n", books->subject);
    printf("Book.bookId:%d\n", books->bookId);
}
//int max(int i,int j){
//    int result;
//    if(j>i){
//        result = j;
//    }else{
//        result = i;
//    }
//    return result;
//}
//void sortDemo(int* arr){
//
//}
//void swap(int i,int j){
//    int temp;
//    temp = i;
//    i = j;
//    j = temp;
//}
//
//int sum(int i,int s){
//    printf("i:%lu\n",i);
//    printf("s:%lu\n", s);
//    return i+s;
//}








