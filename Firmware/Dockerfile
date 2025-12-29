FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV PICO_SDK_PATH=/firmware/src/pico-sdk

RUN apt-get update && apt-get install -y \
    cmake \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    build-essential \
    git \
    python3 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /firmware
COPY src/ ./src/

WORKDIR /firmware/src
RUN git clone --depth 1 https://github.com/raspberrypi/pico-sdk.git && \
    cd pico-sdk && git submodule update --init

RUN cmake -B build -S . && make -C build -j8

RUN mkdir -p /output && cp build/*.uf2 /output/

CMD ["cp", "-r", "/output/.", "/firmware/out/"]
