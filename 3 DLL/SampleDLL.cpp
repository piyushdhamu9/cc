#include <stdio.h>
// #include "SampleDLL.h"
// JNIEXPORT int JNICALL Java_SampleDLL_add(JNIEnv *env, jobject javaobj, jint num1, jint num2) 
// {
// 	return num1+num2;
// }

#include<bits/stdc++.h>
// #include <jni.h>
#include "SampleDLL.h"
#include <iostream>

// Implement the native method
extern "C" JNIEXPORT jint JNICALL Java_SampleDLL_add(JNIEnv* env, jobject obj, jint num1, jint num2) {
    return num1 + num2;
}
