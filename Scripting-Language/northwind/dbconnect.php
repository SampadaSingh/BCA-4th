<?php
$localhost = "localhost";
$user= "root";
$password = "";
$dbname = "northwind";

$conn = new mysqli($localhost, $user, $password, $dbname);

if($conn->connect_error) {
    die('<div class="alert alert-danger">Connection failed' . $conn->connect_error. '</div>');
}
?>