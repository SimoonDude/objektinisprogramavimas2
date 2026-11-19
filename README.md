# Objektinis programavimas — Studentų galutinių balų skaičiavimas

## Projekto aprašymas

Programa skirta studentų namų darbų ir egzamino rezultatams apdoroti bei galutiniam balui apskaičiuoti.

Projekto metu realizuojamas studentų duomenų įvedimas, apdorojimas, grupavimas į dvi kategorijas ir skirtingų konteinerių bei algoritmų veikimo spartos tyrimas.

## Versijos ir jų pakeitimai

### `v1.0`

- Pasirinkta naudoti trečiąją strategiją.
- Ištaisyti galutinės klaidos, galutinai testuota.
- Parengtos programos kompiliavimo ir paleidimo instrukcijos.

### `v1.1`

- Pereita prie `class` tipo objekto studentas
- Įvestos optimizacijos 

---

## Programos reikalavimai

- C++ kompiliatorius, palaikantis C++17.
- `make` įrankis (jei naudojamas Makefile).
- Git – pasirinktinai, jei norima atsisiųsti ir valdyti projekto šaltinio kodą.

## Įdiegimas ir kompiliavimas

### 1. Projekto atsisiuntimas

```bash
git clone <REPOSITORY_URL>
cd objektinisprogramavimas
```

### 2. Programos kompiliavimas

Projekto šakniniame kataloge vykdyti:

```bash
make
```

Kompiliavimo metu sukuriamas vykdomasis failas `studentai`.

### 3. Programos paleidimas

Linux arba „GitHub Codespaces“ aplinkoje:

```bash
./studentai
```

Jeigu `make` nėra įdiegtas, programą galima kompiliuoti tiesiogiai:

```bash
g++ -std=c++17 -Wall -Wextra -O2 1uzd.cpp -o studentai
```

## Naudojimosi instrukcija

1. Paleisti programą pagal aukščiau pateiktas instrukcijas.
2. Pasirinkti norimą operaciją programos meniu:
    1) Įvesti studentų duomenis pačiam.
    2) Apdoroti turimus duomenis.
    3) Sugeneruoti pažymius turimems studentams
    4) Sugeneruoti ne tik pažymius bet ir studentus
4. Pasirinkti kur išvesti, ir prireikus, suvesti failo pavadinimą.
5. Pasirinkti galutinio balo rūšiavimo būdą.
6. Peržiūrėti apskaičiuotus rezultatus ir studentų suskirstymą į kategorijas.
7. Jeigu norima, ištestuoti programos veikimo spartą su "Debug" pasirinkimu ir failais `benchmark-data/`.

## Studentų skirstymo strategijos

Studentai suskirstomi į dvi grupes pagal galutinio balo kriterijų:

- **Vargšiukai** – studentai, kurių galutinis balas mažesnis už nustatytą ribą.
- **Kietiakai** – studentai, kurių galutinis balas yra lygus ribai arba ją viršija.

Skirstymo riba. Laikoma išlaikyta, jeigu

$ vidurkis_{nd} * 0,4 + egzaminas * 0,6 \geq 5 $

## Eksperimentų metodika

Eksperimentų tikslas – palyginti skirtingų programos įgyvendinimų strategijų veikimo spartą ir įvertinti, kokią įtaką daro įvariūs algoritmai bei konteineriai.

### Testavimo aplinka

- CPU: Intel Xeon Platinum 8370C, 2 branduoliai, 2,80 GHz
- RAM: 7,8 GiB
- Diskas: virtualus SSD (darbo disko `ROTA=0`)
- Kompiliatorius: `g++`, `-std=c++17 -O2`

### Naudoti duomenų rinkiniai

Eksperimentams naudojami iš anksto sugeneruoti failai:

| Studentų skaičius | Failo pavadinimas | Paskirtis |
|---:|---|---|
| 10 000 | `studentai10000.txt` | Mažesnio rinkinio testas |
| 100 000 | `studentai100000.txt` | Vidutinio rinkinio testas |
| 1 000 000 | `studentai1000000.txt` | Didelio rinkinio testas |

Kiekviena strategija testuojama su tais pačiais duomenų rinkiniais. Kiekvienas bandymas atliekamas iš naujo paruošus pradinį konteinerį. Skaičiuojamas kelių bandymų laiko vidurkis.

Matavimo metu į laiką neįtraukiama įvairi informacijos manipuliacija (pvz.apskaičiavimas vidurkių) ar kitos operacijos, kurios nėra tiesiogiai susijusios su failais ar nėra intensyvios resursų ar laiko sąnaudos atžvilgiu.

Kartu testuota ir kompiliatoriaus naudoti flag'ai ir jų prisidėjimas prie programos efektyvumo ar kt. Šalia nurodytas ir failo dydis, siekiant parodyti santykį tarp kompiliatoriaus optimizacijų ir failo dydžio.

### Rezultatai

Rezultatai pateikiami lentelės pavidalu, išskirstyti naudotų studentų duomenų dydžiu ir pateiktas kiekvieno darbo punkto laikas sekundėmis.
#### Dabar, naudojant klases (`class`):
| Studentų skaičius | Skaitymas | Skirstymas | Rašymas |
|---:|---:|---:|---:|
| 10,000 | 0.014672 | 0.000006 | 0.011366 |
| 100,000 | 0.262006 | 0.000207 | 0.107046 |
| 1,000,000 | 0.928797 | 0.004769 | 1.071378 |
#### Pirminė realizacija, naudojanti struktūras (`struct`):
| Studentų skaičius | Skaitymas | Skirstymas | Rašymas |
|---:|---:|---:|---:|
| 10,000 | 0.022739 | 0.001209 | 0.013092 |
| 100,000 | 0.257048 | 0.012539 | 0.129134 |
| 1,000,000 | 1.402110 | 0.124734 | 1.315480 |
## Išvados

Pereiti prie klasių svarbu

### TODO

Norėčiau netolimoje ateityje pereiti prie `template`'u. Šiuo metu egzistuoja skirtingos struktūros su `std::list` ir `std::vector`.

### Papildomi komentarai

<img width="656" height="50" alt="{009B9741-B639-469F-80A3-92D4BEF856D2}" src="https://github.com/user-attachments/assets/6561230b-3892-4733-98d2-fe40ba4f4ff4" />
