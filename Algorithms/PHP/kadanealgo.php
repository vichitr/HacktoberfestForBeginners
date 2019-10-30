<?php  
function maxSubArraySum($a, $n) 
{ 
$max_so_far = 0; 
$max_end_here = 0; 
for ($i = 0; $i < $n; $i++) 
{ 
    $max_end_here = $max_end_here + $a[$i]; 
    if ($max_end_here < 0) 
        $max_end_here = 0; 
  
    else if ($max_so_far < $max_end_here) 
        $max_so_far = $max_end_here; 
} 
return $max_so_far; 
}
  
$a = array(1, 1, 2, -1,3, 4, 5); 
$n = count($a); 
$max_sum = maxSubArraySum($a, $n); 
echo "Maximum contiguous sum is ",$max_sum; 
?>