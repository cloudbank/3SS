# 3SS ©
An Android dhash algorithm that does reduction, greyscale, and fingerprint in one pass. Currently written to detect exact duplicates with box interpolation. Without higher quality downsizing it is limited to images without distortions. It is possible to extend its use for distortions by using adjunctly with an image library's downsize(e.g. Glide). I am reworking it to possibly use Haar transform or sinclanczos to downsize. I am researching reworking the whole algorithm in 3SS2B for other possibilities such as FMIQ, Radon, or Haar fingerprinting, and Deep Autoencoders.  NN is the simplest possible choice for use cases such as networking apps that consume API's with duplicates.

Available in C++ and Kotlin.


3SS describes the 3 steps of the dhash algorithm in one pass for image detection, optimized for use with Android(row hash only, DirectBuffer to JNI or Kotlin implementation). It is using NN for scaling with exact detection.  It is currently working on complex images with box  interpolation and these shortcuts.

## Best times for hashing, so far:

* JNI C++ nativeDHash: .4secs

* Kotlin dHash: 1 sec


<img src="https://i.imgur.com/f5jLtXl.png" height="250"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

## License

* [Apache Version 2.0](http://www.apache.org/licenses/LICENSE-2.0.html)

## Building

This lib was built with Android Studio which uses the gradle build system.  

## Acknowledgements

This project uses the [Github API] ( https://www.github.com)
* http://www.hackerfactor.com/blog/index.php?/archives/529-Kind-of-Like-That.html
* http://tech.jetsetter.com/2017/03/21/duplicate-image-detection/





