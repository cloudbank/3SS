#include <jni.h>


/**3SS
 * scales the image using the fastest, simplest algorithm called "nearest neighbor, greyscales,
 * and fingerprints all in one*/
extern "C" JNIEXPORT jlong JNICALL
Java_com_droidteahouse_edo_preload_MyPreloadModelProvider_nativeDhash(
        JNIEnv *env, jobject obj, jobject db, jint newWidth, jint newHeight, jint oldWidth,
        jint oldHeight) {
    jint end = (newWidth * newHeight) - 1;
    jint *iBuf = (jint *) env->GetDirectBufferAddress(db);
    jint x2, y2;
    jint index = 0;
    jlong hash = 0;
    jint firstpixel = 0;
    //buffer has been allocated for size already on java side
    for (jint y = 0; y < newHeight; ++y) {
        for (jint x = 0; x < newWidth; ++x) {
            x2 = x * oldWidth / newWidth;
            if (x2 < 0) {
                x2 = 0;
            } else if (x2 >= oldWidth) {
                x2 = oldWidth - 1;
            }
            y2 = y * oldHeight / newHeight;
            if (y2 < 0) {
                y2 = 0;
            } else if (y2 >= oldHeight) {
                y2 = oldHeight - 1;
            }
            if (index % newWidth == 0) {
                firstpixel = iBuf[((y2 * oldWidth) + x2)];
            } else if ((index) % newWidth != 0) {
                jint pixel2 = iBuf[((y2 * oldWidth) + x2)];
                jint pixel = firstpixel;
                firstpixel = pixel2;
                //little endian
                pixel2 = (pixel2 & 0xff) * 0.299 + ((pixel2 >> 8) & 0xff) * 0.587 +
                         ((pixel2 >> 16) & 0xff) * 0.114;
                pixel = (pixel & 0xff) * 0.299 + ((pixel >> 8) & 0xff) * 0.587 +
                        ((pixel >> 16) & 0xff) * 0.114;

                //could store the gray pixels here to use with colhash and rotations

                hash |= (pixel < pixel2);
                //last shift here not wanted
                if (index < end) {//
                    hash <<= 1L;
                }
            }
            index++;
        }

    }



//this happens anyway but try to move it along
    //env->DeleteLocalRef(db);
    //delete (newBitmapPixels);

    return hash;
}






