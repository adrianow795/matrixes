ARG VERSION=latest

#Get a base image (ubuntu)
FROM ubuntu:${VERSION}

# run some commands on the image - this will be executed during building of the image
RUN apt-get -y update
RUN apt install -y cmake
RUN apt install -y g++
RUN apt install -y lcov
RUN apt install -y doxygen

#copy all local files to docker 
COPY . /usr/src/matrixes_docker

# set work directory
WORKDIR /usr/src/matrixes_docker
RUN cmake -B build && cmake --build build

CMD ["build/matrix"]

