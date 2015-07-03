LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := konavector_static

LOCAL_MODULE_FILENAME := libkonavector

LOCAL_SRC_FILES := \
	KonaVector.cpp \
	KonaVector2D.cpp \
	KonaRect.cpp \
	KonaCircle.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES := $(LOCAL_PATH)
                                 
include $(BUILD_STATIC_LIBRARY)
