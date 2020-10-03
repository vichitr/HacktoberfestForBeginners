<?php

function insertionSort(array &$array, $size)
{
    $shifts = 0;

    for ($i = 1; $i < $size; $i++) {
        $current = $array[$i];
        for ($j = $i - 1; $j >= 0 && $array[$j] > $current; $j--) {
            $array[$j + 1] = $array[$j];
            $shifts++;
        }
        $array[$j + 1] = $current;
    }

    return $shifts;
}

$handle = fopen('php://stdin', 'r');
fscanf($handle, '%d', $size);
$array = explode(' ', trim(fgets($handle)));

$shifts = insertionSort($array, $size);
printf("%d\n", $shifts);
fclose($handle);

?>
