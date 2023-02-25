# Programa studentų duomenų įvedimui ir galutinio balo skaičiavimui
Lina Čerepovičiūtė, 1gr.

## v0.4
---

## v0.3
Funkcionalumas išliko toks pat kaip v0.2 versijos

### Programos struktūros pokyčiai:
	1. Programą sudaro du .cpp tipo failai: "main.cpp" ir "functions.cpp".
	2. Programą sudaro du header (.h) tipo failai: "headeris.h" ir "functions.h".
	3. "functions.cpp" faile aprašytos pagalbinės programos funkcijos 
	4. "functions.h" faile aprašytos programoje naudojamos struktūros bei "functions.cpp" faile esančių funkcijų deklaracijos.

## v0.2
### Funkcionalumo pasikeitimai:
	1. Programa leidžia vartotojui nuskaityti duomenis iš failo.
	2. Programa automatiškai nustato namų darbų kiekį pagal failo pirmąją eilutę. (Jei failo nėra, namų darbų kiekį įveda vartotojas)
	3. Programa leidžia vartotojui pasirinkti generuoti atsitiktinius studentus
	4. Nebėra galimybės rankiniu būdu įvedamiems studentams generuoti atsitiktinių pažymių.
	5. Išvedami rezultatai ir pagal vidurkį, ir pagal medianą.
	6. Išvedamas studentų sąrašas surikiuotas abėcėlės tvarka pagal studentų pavardes, o tuo atveju jei pavardės sutampa - pagal vardus.

### Įpatumai:
	1. Nuskaitomo failo pavadinimas turi būti "kursiokai.txt".
	2. Nuskaitomo failo pirmąją eilutę turi sudaryti stulpelių pavadinimai.
	3. Stulpeliai turi būti išrikiuoti tokia tvarka: stulpelis studento vardui, stulpelis studento pavardei, n stulpelių namų darbų pažymiams ir stulpelis egzamino įvertinimui.
	4. Visos nuskaitomo failo eilutės turi būti pilnai užpildytos. Jei studentas neatliko visų užduočių, tuose stulpeliuose turi būti įrašyti 0.

## v0.1
### Funkcionalumas:
	1. Programa leidžia vartotojui įvesti maksimalų pažymių skaičių.
	2. Programa leidžia vartotojui įvesti šiuos studentų duomenis: vardą, pavardę, pažymius ir egzamino balą.
	3. Vartotojui pasirinkus, programa gali generuoti atsitiktinius pažymius.
	4. Pagal įvestus duomenis paskaičiuojamas galutinis balas (vidurkis ir mediana).
	5. Pagal vartotojo pasirinkimą išvedami rezultatai pateikiant vidurkį arba medianą.

### Įpatumai:
	1. Studentų duomenys saugojami struktūroje.
	2. Duomenų saugojimui naudojami vektoriai.
