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

Matavimo metu į laiką neįtraukiama įvairi informacijos manipuliacija (pvz.apskaičiavimas vidurkių) ar kitos operacijos, kurios nėra tiesiogiai susijusios su failais ar nėra intensyvios resursų ar laiko sąnaudos atžvilgiu.

Kartu testuota ir kompiliatoriaus naudoti flag'ai ir jų prisidėjimas prie programos efektyvumo ar kt. Šalia nurodytas ir failo dydis, siekiant parodyti santykį tarp kompiliatoriaus optimizacijų ir failo dydžio.

Rezultatai pateikiami lentelės pavidalu, išskirstyti naudotų studentų duomenų dydžiu ir pateiktas kiekvieno darbo punkto laikas sekundėmis.

### Testavimo aplinka

- CPU: Intel Core Ultra 7 155H, 16 branduolių, 3.8 GHz
- RAM: 16 GB DDR5
- Diskas: 1 TB SSD NVME 
- Kompiliatorius: `g++`, `-std=c++17`

### Naudoti duomenų rinkiniai

Eksperimentams naudojami iš anksto sugeneruoti failai:

| Studentų skaičius | Failo pavadinimas | Paskirtis |
|---:|---|---|
| 10 000 | `studentai10000.txt` | Mažesnio rinkinio testas |
| 100 000 | `studentai100000.txt` | Vidutinio rinkinio testas |
| 1 000 000 | `studentai1000000.txt` | Didelio rinkinio testas |

Kiekviena strategija testuojama su tais pačiais duomenų rinkiniais. Kiekvienas bandymas atliekamas iš naujo paruošus pradinį konteinerį. Skaičiuojamas 5 bandymų laiko vidurkis.

### Rezultatai, tiriantys `class` ir `struct` skirtumus 

#### Dabar, naudojant klases (`class`):
| Studentų skaičius | Skaitymas | Skirstymas | Rašymas |
|---:|---:|---:|---:|
`O1`, 216 KB
| 10,000 | 0.020826 | 0.000012 | 0.012536 |
| 100,000 | 0.222845 | 0.000382 | 0.114582 |
| 1,000,000 | 1.078042 | 0.005574 | 1.094501 |
`O2`, 212 KB
| 10,000 | 0.016937 | 0.000013 | 0.022052 |
| 100,000 | 0.229391 | 0.000391 | 0.119202 |
| 1,000,000 | 1.171074 | 0.004880 | 1.247350 |
`O3`, 232 KB
| 10,000 | 0.017131 | 0.000007 | 0.012343 |
| 100,000 | 0.215817 | 0.000278 | 0.113277 |
| 1,000,000 | 1.189372 | 0.004933 | 1.342095 |

#### Pirminė realizacija, naudojanti struktūras (`struct`):
| Studentų skaičius | Skaitymas | Skirstymas | Rašymas |
|---:|---:|---:|---:|
`O1`, 252 KB
| 10,000 | 0.020339 | 0.000145 | 0.012311 |
| 100,000 | 0.239246 | 0.002276 | 0.119872 |
| 1,000,000 | 1.175576 | 0.028370 | 1.223900 |
`O2`, 232 KB
| 10,000 | 0.022739 | 0.001209 | 0.013092 |
| 100,000 | 0.257048 | 0.012539 | 0.129134 |
| 1,000,000 | 1.402110 | 0.124734 | 1.315480 |
`O3`, 272 KB
| 10,000 | 0.017633 | 0.000160 | 0.011547 |
| 100,000 | 0.219756 | 0.002356 | 0.112539 |
| 1,000,000 | 1.079966 | 0.027164 | 1.144756 |

## Išvados

Pereiti prie klasių svarbu ir tinkama (?) Dedu klaustuką, nes galutinai nesupratau, koks gilus skirtumas yra. Atrodo pagrindinė motyvacija yra adaptuotis prie kitų programuotojų. Didžiausias greičio skirtumas atkeliavo nuo vėlesnių optimizacijų, kaip skaitymo ir rašymo funkcijų optimizacijos (`std::move` ir `*begin++`).

Visvien galima išskirti pastebimą skirtumą – klasė efektyvesnė už struktūra, jeigu galima taip tiesmukiškai teigti.

Dėl kompiliatoriaus flag'ų, `O2` yra geriausias pagal failo dydį, o `O1` pagal greitį.

### TODO

---

### Papildomi komentarai

<img width="656" height="50" alt="{009B9741-B639-469F-80A3-92D4BEF856D2}" src="https://github.com/user-attachments/assets/6561230b-3892-4733-98d2-fe40ba4f4ff4" />
