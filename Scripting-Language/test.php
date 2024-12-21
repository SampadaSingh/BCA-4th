<?php
if (isset($_GET['focus'])) {
    $select = $_GET['focus'];

    if ($select == "title") {
        echo '
        <h1>ABC</h1>
        <p>Date</p>
        <p>Price</p>
        <p>Description</p>
        ';
    } elseif ($select == "date") {
        echo '
        <p>Title</p>
        <h1>11/17/2024</h1>
        <p>Price</p>
        <p>Description</p>
        ';
    } elseif ($select == "price") {
        echo '
        <p>Title</p>
        <p>Date</p>
        <h1>1234</h1>
        <p>Description</p>
        ';
    } elseif ($select == "description") {
        echo '
        <p>Title</p>
        <p>Date</p>
        <p>Price</p>
        <h1>helllooooooooo</h1>
        ';
    }
} else {
    echo '<p>Please provide a valid focus parameter in the URL.</p>';
}
?>
