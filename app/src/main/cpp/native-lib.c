#include <jni.h>
//#include <string>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "arophix_jni.h"


#ifdef __cplusplus
extern "C" {
#endif

static const char *secret = "password_me";

int is_palindrome_using_recursion(int aj);
int fibonacci_loop(int num);
int fibonacci_recursive(int num);
int factorial_of_a_number(int n);

static int add(int a, int b);

JNIEXPORT jstring JNICALL
Java_arophix_com_androidopenssl_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject instance) {
    return (*env)->NewStringUTF(env, "Android OpenSSL");
}

void set_signal_handler(void);
void almost_c99_signal_handler(int sig);

void set_signal_handler(void)
{
    signal(SIGABRT, almost_c99_signal_handler);
    signal(SIGUSR1, almost_c99_signal_handler);
    signal(SIGKILL, almost_c99_signal_handler);
    signal(SIGSTOP, almost_c99_signal_handler);
    signal(SIGFPE,  almost_c99_signal_handler);
    signal(SIGILL,  almost_c99_signal_handler);
    signal(SIGINT,  almost_c99_signal_handler);
    signal(SIGSEGV, almost_c99_signal_handler);
    signal(SIGTERM, almost_c99_signal_handler);
}

void almost_c99_signal_handler(int sig)
{
    ALOGW("!! Caught a signal !!\n");
    switch(sig)
    {
        case SIGABRT:
            ALOGW("Caught SIGABRT: usually caused by an abort() or assert().\n");
            ALOGW("This exception is as expected, it is not an error.\n\n");
            exit(0); // as expected, so return 0
        case SIGFPE:
            ALOGW("Caught SIGFPE: arithmetic exception, such as divide by zero\n");
            break;
        case SIGILL:
            ALOGW("Caught SIGILL: illegal instruction\n");
            break;
        case SIGINT:
            ALOGW("Caught SIGINT: interactive attention signal, probably a ctrl+c\n");
            break;
        case SIGSEGV:
            ALOGW("Caught SIGSEGV: segfault\n");
            break;
        case SIGUSR1:
            ALOGW("Caught SIGUSR1\n");
            break;
        case SIGKILL:
            ALOGW("Caught SIGKILL\n");
            break;
        case SIGSTOP:
            ALOGW("Caught SIGSTOP\n");
            break;
        case SIGTERM:
            ALOGW("Caught SIGTERM\n");
            break;
        default:
            ALOGW("Caught SIGTERM: a termination request was sent to the program\n");
            break;
    }
    exit(1);
}


JNIEXPORT jint JNICALL
Java_arophix_com_androidopenssl_MainActivity_computeSum(JNIEnv *env, jobject instance, jint a,
                                                        jint b) {
    set_signal_handler();
    
    int sum = add(a, b);
    
    static int valueToTamper = 20;
    
    int result = fibonacci_loop(valueToTamper);
    ALOGW("====>>>> fibonacci_loop result of %d: %d\t", valueToTamper, result);
    
    result = fibonacci_recursive(valueToTamper);
    ALOGW("====>>>> fibonacci_recursive result of %d: %d\t", valueToTamper, result);
    
    factorial_of_a_number(20);
    
    is_palindrome_using_recursion(60);
    
    
    return sum;
}


static int add(int a, int b){
    int sum = a + b;
//    abort();
    return sum;
}


int factorial_of_a_number(int n) {
    int fact, i;
    fact = 1;
    ALOGW("Enter the number\t");
    for(i = 1; i <= n; i++)
    {
        fact = fact*i;
    }
    ALOGW("Factorial of %d is %d", n , fact);
    return fact;
}


int fibonacci_loop(int n)
{
    int next = -1;
    
    if (n < 0) {
        return next; //error!
    }

    int first = 0, second = 1, c;
    
    for (c = 0; c <= n; c++) {
        if (c <= 1) {
            next = c;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        ALOGW("fibonacci of %d: %d\n", c, next);
    }
    
    return next;
}


int fibonacci_recursive(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (fibonacci_recursive(n-1) + fibonacci_recursive(n-2));
}


int is_palindrome_using_recursion(int aj)
{
    static int valueN = 100;
    static int sum = 0;
    if(aj != 0)
    {
        sum = sum *10 + aj%10;
        return is_palindrome_using_recursion(aj/10);   // recursive call same as while(n!=0) using loop
    }
    else if(sum == valueN)
        return 1;
    else
        return 0;
}

#ifdef __cplusplus
}
#endif
