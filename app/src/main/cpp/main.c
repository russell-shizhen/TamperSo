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

extern void swap();

int buf[2] = {1, 2};
int main()
{
    swap();
    return 0;
}

#ifdef __cplusplus
}
#endif
