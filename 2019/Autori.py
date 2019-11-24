import sys

names = sys.stdin.readline().strip() 
acro = ""
for bokstav in names:
    if bokstav.isupper():
        acro = acro + bokstav

print(acro)