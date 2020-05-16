//This code is contributed by Shreevatsa N, @vatsa287
Set<Integer> colors = new HashSet<>();
    int pairs = 0;

    for (int i = 0; i < n; i++) {
        if (!colors.contains(c[i])) {
            colors.add(c[i]);
        } else {
            pairs++;
            colors.remove(c[i]);
        }
    }

    System.out.println(pairs);