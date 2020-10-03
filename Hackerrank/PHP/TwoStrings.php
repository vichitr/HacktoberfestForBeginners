<?php

$handle = fopen('php://stdin', 'r');
fscanf($handle, '%d', $testsLeft);

for (; $testsLeft; $testsLeft--) {
    $a = trim(fgets($handle));
    $b = trim(fgets($handle));
    
    $chars1 = count_chars($a, 1);
    $chars2 = count_chars($b, 1);
    
    printf("%s\n", array_intersect_key($chars1, $chars2) ? 'YES' : 'NO');
}
