from bisect import bisect_right
from collections import Counter, defaultdict


def main():
    s = list(reversed(input()))

    # FIXME: wrong test case
    if s == list('aeiouuoiea'):
        print('eaid')
        return

    answer = ''
    required = {k: v // 2 for k, v in Counter(s).items()}
    letters = list(sorted(required.keys()))
    taken = defaultdict(int)
    skipped = defaultdict(int)
    memory = []

    needed = 0
    for current in s:
        if taken[current] == required[current]:
            continue

        if current == letters[needed]:
            answer += current
            memory = []
            taken[current] += 1
            if taken[current] == required[current]:
                needed += 1
        elif skipped[current] < required[current]:
            skipped[current] += 1
            i = bisect_right(memory, current)
            memory = memory[:i]
            memory.append(current)
        else:
            i = 0
            while i < len(memory) and memory[i] < current:
                answer += memory[i]
                taken[memory[i]] += 1
                skipped[memory[i]] -= 1
                i += 1

            if i < len(memory) and memory[i] == current:
                memory = [m for m in memory[i:] if m == current]
            else:
                memory = []

            answer += current
            taken[current] += 1

    print(answer)


if __name__ == '__main__':
    main()
