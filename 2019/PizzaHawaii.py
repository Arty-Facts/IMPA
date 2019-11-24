#python3 
import sys
from collections import defaultdict
def main():
    tests = int(sys.stdin.readline().strip())
    for i in range(tests):
        if i > 0:
            print()
        n = int(sys.stdin.readline().strip())
        guess = defaultdict(set)
        data = []
        for i in range(n):
            name = sys.stdin.readline().strip()
            _, *foren = sys.stdin.readline().split()
            _, *nativ = sys.stdin.readline().split()
            data.append((set(nativ),set(foren)))
            for fore in foren:
                for nat in nativ:
                    guess[fore].add(nat)
        for nativ, foren in data:
            for n in nativ:
                for no, fo in data:
                    if n not in no:
                        for bar in fo:
                            guess[bar].discard(n)
        contradiction = True
        change = ""
        while contradiction:
            contradiction = False
            for ingredient, possible in guess.items():
                for choice in possible:
                    #print(ingredient, choice)
                    count = 0
                    for nativ, foren in data:
                        if choice in nativ and ingredient not in foren:
                            count += 1
                            break
                    if count > 0:
                        contradiction = True
                        change = choice
                        break
                if contradiction:
                    possible.discard(change)
                    if len(possible) == 1:
                        s = list(possible)[0]
                        for nativ, foren in data:
                            if s not in nativ:
                                for f in foren:
                                    guess[f].discard(s)
                    break
        for ingredient, possible in sorted(guess.items()):
            #print(ingredient ,possible)
            for p in sorted(possible):
                print(f"({ingredient}, {p})")

if __name__ == "__main__":
    main()
