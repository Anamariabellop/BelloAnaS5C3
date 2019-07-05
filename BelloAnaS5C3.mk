#makefile

BelloAnaResorte.pdf: datosresorte.dat BelloAna_S5C3_plots.py BelloAna_S5C3_ODES.cpp
	python BelloAna_S5C3_plots.py
datosresorte.dat: a.out
	./a.out
a.out: BelloAna_S5C3_ODES.cpp
	g++ BelloAna_S5C3_ODES.cpp
	
