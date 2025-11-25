# Specifikáció
## A program céjla
A feladat egy olyan program készítése, amely egy fájlban definiált morze kódtábla alapján szövegeket tud morzésítani, illetve a megadott morze kódtábla alapján morze kódot lefordítani. Mindezt egy parancssori program keretében.

## A program használata
A felhasználónak a program használatához szereznie/készíteni kell egy morze kódtáblát, valamint egy kódolandó vagy dekódolandó szöveget paint text formátumban, ASCII karakterekből, .txt kiterjesztéssel. Valamint a program meghívásokor meg kell adnia, hogy milyen néven jöjjön létre a kódolt/dekódolt szöveget tartaldmazó fájl, ha nincs megadva akkor a "result.txt" fájlba helyeződik a végeredmény.
A felhasználónak a "*.*", "*-*" valamint a " ", "	" ASCII karaktereket kell használnia a morze kód *rövid", "hosszú szünetjel", "nagyon hosszú szünetjel" jeleiként a kódtáblában, valamint a dekódolni kívánt szövegben egyaránt.
A programnak alapvetö üzemmódja a kódolás, amelyt egy flag-gel lehessen megfordítani

### Az morze jelek definiálása
Összgezve a felhasználó az alábbi táblázat jeleiből kell, hogy tudja felépíteni a dekódolni kívánt szöveget, valamint az alábbi táblázat alapján tudja felhasználni a kódolt szöveget.

| Morze jel                      | Leírás                  |
|--------------------------------|-------------------------|
| "."                            | rövid                   |  
| "-"                            | hosszú                  |
| " " (ASCII szóköz)             | hosszú szünetjel        |
| "	" (ASCII tabulátor karakter) | nagyon hosszú szünetjel |
    

### A kódtábla struktúrája
A kódtáblát a kövekező formátumban kell deklarálni:
```
{karakter} {morzekódja}
{karakter} {morzekódja}
{karakter} {morzekódja}
```
Például:
```
a .-
b ..
c --
```

### A program futtatása
A felhasználónak a "morze" nveű parancs, parancssori futtatásával kell tudnia elindítani a programot, az alábbi opcionális flag-gel, és paraméterekkel.
"-r" - dekódolás (reverse) módban futtatja a programot
<kódtábla elérésiútja> - a fálj elérési útja kiterjesztéssel együtt
<kódolandó/dekódolandó szöveg elérésiútja> - a fálj elérési útja kiterjesztéssel együtt
A meghívás leírása:
```
morze [-r] <kódtábla elérésiútja> <kódolandó/dekódolandó szöveg elérésiútja> [kimeneti fájlnév]
```

Például:
```
morze -r ./codetable.txt ./text.txt morze_out.txt
```

## A futtatás eredménye
A program a szabványos kimentre helyes lefutás esetén kiírja a lefordítandó, valamint a létrehozott fájl nevét természetesen kiterjesztésekkel együtt a következőt formátumban:
```
Sikeres fordítás {bemeneti fájlnév} -> {kimeneti fáljnév}
```

Amennyiben a hiba történik a futtatás során, az lentebb megtalálható hibák valamelyikét a következő formátumban írja ki a szabványos bemenetre:
```
Hiba: {Hibakód} - {hiba leírása}
```

A megkülönböztetett hibák és hibakódjaik, természetesen a leírás megegyezik az esettel amikor a hibakód adódik.

| Hibakód | Leírás                                                                      |
|---------|-----------------------------------------------------------------------------|
| 0x1     | Nem ismert hiba                                                             |
| 0x2     | Nem ASCII karakter van a kódtáblában vagy a kódolandó/dekódolandó szövegben |
| 0x3     | Helytelen kódtábla formátum                                                 |
| 0x4     | A kimeneti fálj már létezik                                                 |
| 0x5     | Sikertelen fordítás hiányos kódtábla miatt                                  |

### A kimeneti fájl eredménye
Amennyiben a futtatás során hibába ütközik a program, a kimeneti fálj nem jön létre.

Sikeres futtatás esetén az eredmény a kimeneti fálj első sorába íródik, kódoló és dekódoló módban is.

Példa kódoló módban:
```
.-	..	--
```

Példa dekódoló módban:
```
a b c
```

