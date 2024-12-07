FROM alpine:latest

RUN apk update
RUN apk add git
RUN apk add g++

RUN mkdir /home/lab1
RUN cd /home/lab1
RUN git clone https://github.com/D1ceBreaker/PARVPO-lab1.git
RUN g++ -o lab1 -fopenmp PARVPO-lab1/main.cpp
RUN cd PARVPO-lab1
RUN mkdir output
RUN touch ./output/output.txt
CMD ./lab1 > /output/output.txt
