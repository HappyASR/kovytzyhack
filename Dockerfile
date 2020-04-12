FROM ubuntu:18.04

MAINTAINER @XingXing

RUN echo Asia/Chongqing > /etc/timezone && \
    echo tzdata tzdata/Areas select Asia | debconf-set-selections && \
    echo tzdata tzdata/Zones/Asia select Chongqing | debconf-set-selections

ADD sources.list /etc/apt/

RUN DEBIAN_FRONTEND=noninteractive apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
        gcc \
        gcc-m68k-linux-gnu \
        gcc-arm-linux-gnueabi \
        git \
        cmake \
        make \
        python3 \
        zip

RUN groupadd -g 1000 dockerbot && useradd -g 1000 -u 1000 -m dockerbot
USER dockerbot


