<?php
for($i=2;$i<=1000;$i++)
{
    $o=true;
    for($x=$i-1;$x>1;$x--)
    {
        if($i%$x==0)
        {
            $o=false;
            break;
        }
    }
    if($o) echo $i."<br>";
}
?>
