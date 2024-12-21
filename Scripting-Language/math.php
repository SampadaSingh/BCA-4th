<?php
$n1=$_GET['n1'];
$n2=$_GET['n2'];
$select=$_GET['focus'];
if($select=="add"){
    echo"$n1 + $n2 = ".($n1+$n2);
}
if($select=="subtract"){
    echo"$n1 - $n2 = ".($n1-$n2);
}
if($select=="multiply"){
    echo"$n1 * $n2 = ".($n1*$n2);
}
if($select=="divide"){
    echo"$n1 / $n2 = ".($n1/$n2);
}
?>