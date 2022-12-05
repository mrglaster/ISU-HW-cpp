### Task about the moon

Write a program that allows the user, for the date he enters, in the format dd.mm.yyyy, to find out:

1) rising (elevation changes from negative to positive)
2) climax (maximum elevation)
3) moonset (elevation changes from positive to negative) of the Moon.

Present the result in the form:
1) Date: dd.mm.yyyy
2) Moonrise: hh:mm:ss
3) Moon Climax: hh:mm:ss
4) Moonset: hh:mm:ss

The coordinates of the Moon are given in files with the following format: yyyymmdd.dat.
File format:
1st line header
YMD HMS T R El Az FI LG
Further….:
YMD - Date in YYYYMMDD format;
HMS - Time in HHMMSS format;
T - time in fractions of an hour;
R is the distance from the observer in Irkutsk to the Moon in km;
El is the elevation angle (degrees) of the Moon for an observer in Irkutsk;
Az - azimuth (deg) of the Moon for an observer in Irkutsk
Fi is the latitude (degrees) of the Moon;
LG is the longitude (deg) of the Moon.

The archive with the ephemerides of the Moon is available at
https://drive.google.com/file/d/1Vp_vI_7g9Ng5YiQKN60fhT-fxBMMRjVM/view?usp=sharing
