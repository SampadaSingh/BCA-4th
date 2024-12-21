<?php
$a = 1;
$b = 5;
$count = 2; 

echo $a . " " . $b . " ";

do {
    $next = $a + $b;
    echo $next . " ";
    $a = $b;
    $b = $next;
    $count++;
} while ($count < 10);

?>
