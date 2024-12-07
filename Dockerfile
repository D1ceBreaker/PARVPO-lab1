FROM alpine:latest
# используем образ alpine linux

RUN apk update
RUN apk add git # -> скачиваем гит и компилятор для плюсов
RUN apk add g++

RUN mkdir /home/lab1
RUN cd /home/lab1
# создаем рабочую директорию
RUN git clone https://github.com/D1ceBreaker/PARVPO-lab1.git
# клонируем гит репо
RUN g++ -o lab1 -fopenmp PARVPO-lab1/main.cpp
# компилируем склонированный код
RUN mkdir ./PARVPO-lab1/output
RUN touch ./PARVPO-lab1/output/output.txt
# создаем файл для вывода времени работы
CMD ./lab1 > ./PARVPO-lab1/output/output.txt
# запускаем код с перенаправлением потока вывода
