#include <jni.h>
#include <string>

std::string caesarCipher(const std::string &input, int shift) {
    std::string result;
    for (char c : input) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapp_MainActivity_encrypt(
        JNIEnv *env,
        jobject /* this */,
        jstring input) {
    const char *inputChars = env->GetStringUTFChars(input, NULL);
    std::string encrypted = caesarCipher(std::string(inputChars), 3); // Encrypt with shift 3
    env->ReleaseStringUTFChars(input, inputChars);
    return env->NewStringUTF(encrypted.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapp_MainActivity_decrypt(
        JNIEnv *env,
        jobject /* this */,
        jstring input) {
    const char *inputChars = env->GetStringUTFChars(input, NULL);
    std::string decrypted = caesarCipher(std::string(inputChars), -3); // Decrypt with shift -3
    env->ReleaseStringUTFChars(input, inputChars);
    return env->NewStringUTF(decrypted.c_str());
}
