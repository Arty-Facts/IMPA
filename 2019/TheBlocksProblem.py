#python3 
import sys


def main():
    blocks = int(sys.stdin.readline().strip())
    blockMap = [[i] for i in range(blocks)]
    blockLoc = list(range(blocks))

    for line in sys.stdin.readlines():
        line = line.strip()
        if line == "quit":
            break
        mp, t, oo, f = line.split()
        t, f = int(t), int(f)
        if mp == "move":
            if oo == "onto":
                if blockMap[blockLoc[t]][-1] == t:
                    blockLoc[f] = blockLoc[t]
                    blockMap[blockLoc[t]].append(f)
            elif oo == "over":
                pass

        elif mp == "pile":
            if oo == "onto":
                pass
            elif oo == "over":
                pass


        print(mp, t, oo, f)

if __name__ == "__main__":
    main()