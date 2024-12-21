<?php
// 20 inches = 1 ft 8 inches
// 1 ft = 12 inches

function inchToFeet($inch) {
    $feet = (int)($inch / 12); 
    $remainingInches = $inch % 12;
    return "$feet feet $remainingInches inches";
}
$inch = 20;
echo "$inch inches equals: " . inchToFeet($inch) . "<br>"; 
?>
