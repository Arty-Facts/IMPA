#python3 
import sys
ans = ""
def main():
    dictionary = set()
    word = ""
    hifen = False
    for line in sys.stdin.readlines():
        for c in line:
            if c.isalpha():
                if hifen:
                    word += "-"
                word += c.lower()
                hifen = False
            elif c == "-":
                hifen = True
            elif c == "\n":
                if not hifen:
                    if word != "":
                        dictionary.add(word)
                    word = ""
                hifen = False
            else:
                if word != "":
                    dictionary.add(word)
                word = ""
    for w in sorted(dictionary):
        print(w)

        

if __name__ == "__main__":
    main()
