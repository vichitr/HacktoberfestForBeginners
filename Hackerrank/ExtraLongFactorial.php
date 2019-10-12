<?php

// Complete the extraLongFactorials function below.

function extraLongFactorials($n) {

    $factorial=$n;
    while (--$n>1) $factorial=bcmul($factorial,$n);
    echo $factorial;

}

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);

extraLongFactorials($n);

fclose($stdin);
