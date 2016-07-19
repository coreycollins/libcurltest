FROM ubuntu:trusty

RUN apt-get update && \
    apt-get install -y --no-install-recommends --force-yes \
    build-essential \
    ca-certificates \
    cmake \
    curl \
    libcurl4-openssl-dev 

COPY . /root/test

RUN cd /root/test && \
    make

RUN chmod +x /root/test

ENTRYPOINT /root/test/test 