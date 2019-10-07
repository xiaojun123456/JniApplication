LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -lm -llog -ljnigraphics
LOCAL_CPP_FEATURES += exceptions

LOCAL_MODULE := UsbCameraProc

LOCAL_SRC_FILES := UsbCameraProc.cpp\
utils.c\
jpegDecode.c\
ImageProc.c
include $(BUILD_SHARED_LIBRARY)