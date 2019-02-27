LC=xelatex
SRC=report.tex
PDF=report.pdf
LFLAGS=-shell-escape

default: ${PDF}

${PDF}: ${SRC}
	${LC} ${LFLAGS} ${SRC}

clean:
	rm -f *.aux *.log *.out

.PHONY: clean
