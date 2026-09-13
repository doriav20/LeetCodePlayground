# Build and run:            docker build -t leetcode-playground . && docker run --rm leetcode-playground
# Run with local sources:   docker run --rm -v "$(pwd):/LeetCodePlayground" leetcode-playground
# Warnings as errors:       docker build --build-arg WARNINGS_AS_ERRORS=ON -t leetcode-playground .

FROM gcc:15

RUN apt-get update \
    && apt-get install -y --no-install-recommends cmake ninja-build \
    && rm -rf /var/lib/apt/lists/*

ARG WARNINGS_AS_ERRORS=OFF

WORKDIR /LeetCodePlayground

COPY . .

RUN cmake -S . -B /build -G Ninja -DWARNINGS_AS_ERRORS=${WARNINGS_AS_ERRORS} \
    && cmake --build /build

CMD ["sh", "-c", "cmake --build /build &&/build/LeetCodePlayground"]
