# Cplusplus-Program_LAN-Party

Obiective:
- Înțelegerea conceptului de funcționare și implementare a unor structuri de date(precum liste, stive, cozi, arbori binari de căutare)
- Operarea cu aceste structuri de date
- Implementarea unei funcționalități practice folosind aceste concepte

Descriere:
Facultatea de Automatica si Calculatoare prin LSAC organizează in fiecare semestru un LAN Party la care participă toți studenții 
care vor sa își testeze abilitățile la un anumit joc. 
Se dorește realizarea unei soluții software(program executabil) ce poate automatiza acest proces.

Cerinte:
1. Se va crea o listă cu informațiile din fișierul d.in(lista se va forma prin adaugarea elementelor la inceput - O(1)).
2. Se vor elimina din lista anterior creată, echipele cu cel mai mic punctaj de echipă (informațiile despre modul de calcul al acestui punctaj se găsesc în cadrul secțiunii Detalii Tehnice) astfel incat in lista sa ramana n echipe (unde n maxim si n este putere a lui 2).În cazul în care mai multe echipe au acelasi scor se elimina prima echipă gasita in lista. Dupa fiecare eliminare se va relua parcurgerea listei de la cap.
3. Se vor implementa structurile de date necesare pentru a se efectua meciurile:
    - Se va crea o coadă în care se vor pune meciurile dintre echipe.
    - Echipele vor forma meciuri în ordinea în care se află în lista de la punctul anterior, primele două echipe vor forma primul meci (și așa mai departe).
    - Se vor crea două stive - una pentru învinși și una pentru câștigători - ce vor conține echipele ce au pierdut, respectiv, au câștigat meciul anterior.
    - Se vor introduce în stivă echipele în funcție de rezultatul obținut și se va adauga un punct la punctajul de echipă al echipelor ce au câștigat.
    - In cazul unui meci in care ambele echipe au acelasi punctaj, se va alege prima echipa adaugata in meciul disputat.
    - Se vor șterge echipele ce se găsesc în stiva de învinși.
    - Din stiva de câștigători se vor extrage echipele și se va umple din nou coada de meciuri formându-se meciuri cu echipele consecutive (prima echipă scoasă din stivă va juca cu a doua echipa scoasă din stivă primul meci).
    -Se vor repeta pașii enumerați pana la aflarea echipelor de pe primele 8 locuri, care vor fi salvate intr-o alta lista, dupa aflarea acestora se vor continua meciurile pana la aflarea echipei castigatoare.
4. Se va realiza un clasament al ultimelor 8 echipe (salvate la subpunctul anterior) sub forma unui BST(Binary Search Tree). Acesta va fi ordonat după punctajul pe echipă și i se va afișa conținutul în ordine descrescătoare(in cazul in care doua echipe au acelasi punctaj se vor ordona in functie de nume, descrescator)

Rezolvare si solutii gasite:
Cerinta 1:
- am creat clase pentru Echipa, Player si Lista (fisiere header si cpp-uri)
si am implementat constructori si destructori unde a fost nevoie (Player, Echipa, 
Lista), impreuna cu alte metode necesare pentru rezolvarea cerintelor 
(operatorii >>, <<, =)
- in lista.cpp am facut functii pentru crearea listei (folosindu-ma de 
fisierul de date) si de afisare lista

Cerinta 2:
- am facut o functie de calculare a scorului minim dintr-o lista, o functie
care elimina nodul daca are scorul minim, si alta functie care elimina toate 
scorurile mici pana se ajunge la numarul dorit de echipe
- am facut inca o functie pentru scrierea listei in fisier

Cerinta 3:
- o functie pentru extragerea informatiei dintr-un fisier si punerea acesteia
intr-o coada astfel incat sa fie puse cate doua echipe intr-un singur nod
al cozii, si o functie pentru afisarea cozii
- am creat clasa stiva, cu o functie pentru adaugarea unei echipe in stiva
si alta functie de sortare a cozii initiale pe doua stive diferite, una
pentru castigatori si alta pentru invinsi, si o functie de afisare a stivei
- functie de stergere a stivei, pentru stiva de invinsi, si alta functie de
afisare a unei stive intr-un fisier
- in main, m-am folosit de un while pentru a efectua cerinta nr. 3, si de 
o instructiune if (n==16) pentru a afla topul celor 8 echipe castigatoare 
(pe care le-am pus intr-o alta lista, pentru a le putea afisa la cerinta 4)

Cerinta 4:
- am creat un arbore BST, caruia i-am implementat constructorii necesari
- am facut functii de adaugare a unei echipe in arbore, de afisare a 
arborelui si de adaugare a unei liste intr-un arbore in ordine corecta
