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

extern int buf[];
int *bufp0 = &buf[0];
static int *bufp1;
void swap()
{
    int temp;
    bufp1 = &buf[1];
    temp = *bufp0;
    *bufp0 = *bufp1;
    *bufp1 = temp;
}

#ifdef __cplusplus
}
#endif
