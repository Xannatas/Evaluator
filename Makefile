main:	main.cpp Tokenizer.o Evaluator.o
	g++ main.cpp Tokenizer.o Evaluator.o

Tokenizer:	Tokenizer.h Toknizer.cpp
	g++ -c Toknizer.cpp

Evaluator:	Evaluator.h Evaluator.cpp Toknizer.h
	g++ -c Evaluator.cpp

clean: rm -f *o a.out
