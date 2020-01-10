# person_generator

Marek Przygocki
01/10/2020

program przyjmuje 1+3*N parametrów, gdzie N to w zakresie od 1-10

Pierwszy argument - ilość osób które mają zostac wygenerowane i umieszczone w strukturach, zakres : 1-1.000.000
argument 2,3,4 - odpowiednio wg. jakiego pola ma wypisac posortowane dane, od jakiej pozycji[numerujemy od 1], i ilosć pozycji do wypisania
argument 5,6,7 - jak wyżej
...
sortowanie (parametr 2 + (N*3)):
[1] >> sort_name;
[2] >> sort_surname;
[3] >> sort_address;
[4] >> sort_age;
[5] >> sort_dob;//date of birth

Przykład 
<program> 10000 1 1 1 2 20 50
stworzy 10k osób, 
ze wszystkich osób posortowanych po imieniu, wypisze pierwszą,
ze wszystkich osób posortowanych po nazwisku, wypisze 50 osób, od pozycji 20, czyli osoby 20-69
zakończy się.
