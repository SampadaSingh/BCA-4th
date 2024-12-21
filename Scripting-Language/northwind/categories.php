<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Database Content Display</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class = "container mt-5">
        <h2 class = "text-center mb-4">Database Content</h2>

        <?php
        require('dbconnect.php');
        $conn = new mysqli($localhost, $user, $password, $dbname);

        $tbname = "categories";
        $sql = "SELECT * FROM $tbname;"; //echo $sql;
        $result = $conn->query($sql);

        if($result && $result->num_rows > 0) {
            echo '<table class="table table-striped">';
            echo '<thead class = "table-dark">';
            echo '<tr>';
            echo '<th>ID</th>';
            echo '<th>Name</th>';
            echo '<th>Description</th>';
            echo '</tr>';
            echo '</thead>';
            echo '<tbody>';

            $x=1;
            while($row = $result->fetch_array()) {
                echo '<tr>';
                echo '<td>' . $row[0] . '</td>';
                echo '<td>' . $row[1] . '</td>';
                echo '<td>' . $row[2] . '</td>';
                echo '</tr>';
            }

            echo '</tbody>';
            echo '</table>';
        } else {
            echo '<div class="alert alert-danger">No records found</div>';
        }
        $conn->close();
        ?>
    </div>
</body>
</html>