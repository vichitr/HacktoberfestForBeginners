<?php
function Fibo($n)
{
    if($n==0) return 0;
    if($n==1) return 1;
    return Fibo($n-1)+Fibo($n-2);
}
for($i=0;$i<20;$i++)
{
    echo Fibo($i)."<br>";
}
?>
