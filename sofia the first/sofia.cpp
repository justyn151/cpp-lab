// https://tlx.toki.id/problems/osn-2025/0A

#pragma GCC optimize("O3")

#include <unistd.h>
#include <cstddef>
#include <cstring>

constexpr std::size_t CAPACITY = 10'000'064;

alignas(64) static char input[CAPACITY];
alignas(64) static char output[CAPACITY];

int main() {
    std::size_t inputSize = 0;

    // Usually completes in one syscall on the judge.
    while (inputSize < CAPACITY) {
        const ssize_t bytesRead = ::read(
            STDIN_FILENO,
            input + inputSize,
            CAPACITY - inputSize
        );

        if (bytesRead <= 0) {
            break;
        }

        inputSize += static_cast<std::size_t>(bytesRead);
    }

    const char* dataBegin = input;

    while (*dataBegin++ != '\n') {
    }

    const char* readPosition = input + inputSize;

    if (readPosition > dataBegin && readPosition[-1] == '\n') {
        --readPosition;
    }

    char* writePosition = output;

    while (readPosition > dataBegin) {
        const char* numberEnd = readPosition;

        while (
            readPosition > dataBegin &&
            __builtin_expect(readPosition[-1] != '\n', true)
        ) {
            --readPosition;
        }

        const std::size_t length =
            static_cast<std::size_t>(numberEnd - readPosition);

        __builtin_memcpy(
            writePosition,
            readPosition,
            length
        );

        writePosition += length;
        *writePosition++ = '\n';

        // Skip the separator before this number.
        if (readPosition > dataBegin) {
            --readPosition;
        }
    }

    std::size_t remaining =
        static_cast<std::size_t>(writePosition - output);

    const char* position = output;

    while (remaining != 0) {
        const ssize_t bytesWritten = ::write(
            STDOUT_FILENO,
            position,
            remaining
        );

        if (bytesWritten <= 0) {
            break;
        }

        position += bytesWritten;
        remaining -= static_cast<std::size_t>(bytesWritten);
    }

    return 0;
}