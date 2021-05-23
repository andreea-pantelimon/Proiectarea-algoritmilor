# Darius-Florentin Neatu <neatudarius@gmail.com>
# Copyright 2018

# Exemplu de Makefile pentru tema

# tag-uri obligatorii (nume + comportament identic)
# build    => compileaza toata tema 
#             (ATENTIE! E important - NU compilati in tag-urile de run. Sesizati?)
# run-p$ID => ruleaza problema cu ID-ul specificat (1, 2, 3, 4)
# clean    => sterge toate fisierele generate

# restul este la alegerea studentului


CFLAGS=-Wall -std=c++11

# nume necesar (build)

build-p1: ./bani.cpp
	g++ bani.cpp -o bani

build-p2: ./gard.cpp
	g++ gard.cpp -o gard

build-p3: ./bomboane.cpp
	g++ bomboane.cpp -o bomboane

build-p4: ./sala.cpp
	g++ sala.cpp -o sala

run-p1: ./bani
	./bani

run-p2: ./gard
	./gard

run-p3: ./bomboane
	./bomboane

run-p4: ./sala
	./sala

clean: ./gard
	rm ./gard ./bani ./bomboane ./sala
