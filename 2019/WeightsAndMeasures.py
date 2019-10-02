#python3 
import sys
def main():
    turtels = []
    for line in sys.stdin.readlines():
        wigth , strength = map(int, line.split())
        turtels.append((wigth , strength))

    turtels.sort(key=lambda x:x[1])
    strength_left = [sys.maxsize/2] * len(turtels) 
    strength_left[0] = 0
    max_turtels = 0
    #dp solution - starc turtels wigths and save min strength of the smashed turtels 
    for ltr in range(len(turtels)):
        for rtl in range(len(turtels) -1, 0, -1):
            if strength_left[rtl-1]+turtels[ltr][0] <= turtels[ltr][1]: # can turtels[ltr] carry the rest of the smashed turtels?
                strength_left[rtl] = min(strength_left[rtl], strength_left[rtl-1]+turtels[ltr][0])
                max_turtels = max(max_turtels, rtl)
    print(max_turtels)

if __name__ == "__main__":
    main()
