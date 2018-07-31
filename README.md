# 3SS ©
An Android dhash algorithm that does NN, greyscale, and fingerprint in one pass. Currently written to detect exact duplicates.
Available in C++ and Kotlin.


3SS describes the 3 steps of the dhash algorithm in one pass for image detection, optimized for use with Android(row hash only, DirectBuffer to JNI or Kotlin implementation). It is using NN for scaling with exact detection.  Future releases may use a better algorithm for reduction and calculate the hamming distance for similarity comparison. It is currently working on complex images with box  interpolation and these shortcuts.

## Best times for hashing, so far:

* JNI C++ nativeDHash: .4secs

* Kotlin dHash: 


<img src="https://i.imgur.com/f5jLtXl.png" height="250"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

## License

* [Apache Version 2.0](http://www.apache.org/licenses/LICENSE-2.0.html)

## Building

This lib was built with Android Studio which uses the gradle build system.  

## Acknowledgements

This project uses the [Github API] ( https://www.github.com)





