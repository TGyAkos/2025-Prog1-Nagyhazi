# Felhasználói dokumentáció

## A program leírása
A program egy morze kód kódoló/dekódoló, ami képes bármilyen morze kódtáblával, ASCII szövegeket oda vissza fordítani.

## A program használata
A "morze" nevű parancs, parancssori futtatásával tudja elindítani a programot, az alábbi opciókkal.
- [-r] - dekódolás (reverse) módban futtatja a programot (opcionális, nem kötelező megadni)
- <kódtábla elérésiútja> - a kódtáblát tar fálj elérési útját kell megadni ".txt" kiterjesztéssel együtt
- <kódolandó/dekódolandó szöveg elérésiútja> - a kódolni/dekódolni kívánt szöveges fálj elérési útját kell megadni a ".txt" kiterjesztéssel együtt
- [kimeneti fáljnév] - az elkészült fordítást tartalmazó fálj neve, a fájlt a program hozza létre (opcionális, nem kötelező megadni)
  Ha nincs megadva a **[kimeneti fáljnév]** akkor a program egy új fájlt fog létrehozni **result.txt** néven
  A meghívás leírása:
```
morze [-r] <kódtábla elérésiútja> <kódolandó/dekódolandó szöveg elérésiútja> [kimeneti fájlnév]
```

Például, ezek lehetséges meghívások:
```
morze -r ./codetable.txt ./text.txt morze_out.txt
morze -r ./codetable.txt ./text.txt
morze ./codetable.txt ./text.txt morze_out.txt
morze ./codetable.txt ./text.txt 
```

## A kódtábla elkészítése
Az alábbi táblázat jeleiből kell felépíteni a kódtáblát.

| Morze jel                      | Leírás                  |
|--------------------------------|-------------------------|
| "."                            | rövid                   |  
| "-"                            | hosszú                  |
| " " (ASCII szóköz)             | hosszú szünetjel        |
| "	" (ASCII tabulátor karakter) | nagyon hosszú szünetjel |

A kódtáblát a kövekező formátumban kell leírni egy ".txt" fájlban.
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