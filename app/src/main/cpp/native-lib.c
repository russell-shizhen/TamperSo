#include <jni.h>
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

#ifdef __cplusplus
}
#endif
