//
// Created by xiaojun on 2019-09-26.
//


#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <malloc.h>
#include "stdio.h"


#include "jerome_com_usbcamera_ImageProc.h"

#include "ImageProc.h"

#define  LOG_TAG    "native-dev"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)



/**
 * 加载 so 文件的时候，会触发 OnLoad
 * 检测失败，返回 -1，App 就会 Crash
 */
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {

    return JNI_VERSION_1_6;
}






JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeStopRecord(JNIEnv *env, jobject obj) {
    return stopRecord(env);
}

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeStartRecord(JNIEnv *env, jobject obj) {
    return startRecord(env, obj);
}

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeStopCamera(JNIEnv *env, jobject obj) {
    stopCamera(env);
    return 0;
}

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeProcessCamera(JNIEnv *env, jobject obj) {
    return processCamera(env);
}

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativePrepareCamera(JNIEnv *env, jobject obj, jint width, jint height,jint pixelFormat) {
    return prepareCameraWithBase(env,width, height, pixelFormat);
}

JNIEXPORT void JNICALL
Java_jerome_com_usbcamera_ImageProc_nativePixelToBmp(JNIEnv *env, jobject obj,jobject bmp) {
    pixelToBmp(env, bmp);
}


