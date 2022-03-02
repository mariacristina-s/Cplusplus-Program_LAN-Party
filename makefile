build:
	g++ main.cpp Player.cpp Echipa.cpp Lista.cpp Stiva.cpp Coada.cpp ArboreBST.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty
	rm -f ex2.dat
