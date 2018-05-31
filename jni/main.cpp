#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#define LOG_TAG "DoubleSpeed"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

class Player
{
	public:
		float getSpeed();
};

static float (*real_Player$getSpeed)();
static float hk_Player$getSpeed()
{
	return real_Player$getSpeed() * 2;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    
	MSHookFunction((void*) &Player::getSpeed, (void*) &hk_Player$getSpeed, (void**) &real_Player$getSpeed);
	
    return JNI_VERSION_1_2;
}
