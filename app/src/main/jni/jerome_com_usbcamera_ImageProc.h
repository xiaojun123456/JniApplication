//
// Created by xiaojun on 2019-09-26.
//

#ifndef JNIAPPLICATION_JEROME_COM_USBCAMERA_IMAGEPROC_H
#define JNIAPPLICATION_JEROME_COM_USBCAMERA_IMAGEPROC_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif




JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeStopRecord(JNIEnv *, jobject);

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeStartRecord(JNIEnv *, jobject);

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeStopCamera(JNIEnv *, jobject);

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativeProcessCamera(JNIEnv *, jobject);

JNIEXPORT jint JNICALL
Java_jerome_com_usbcamera_ImageProc_nativePrepareCamera(JNIEnv *, jobject, jint, jint,jint);

JNIEXPORT void JNICALL
Java_jerome_com_usbcamera_ImageProc_nativePixelToBmp(JNIEnv *, jobject,jobject);



#ifdef __cplusplus
}
#endif


#endif //JNIAPPLICATION_JEROME_COM_USBCAMERA_IMAGEPROC_H
