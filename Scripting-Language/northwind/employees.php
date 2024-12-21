<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employees Display</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class = "container mt-5">
        <h2 class = "text-center mb-4">Employees Content</h2>
        <!-- Search Bar -->
        <div class="search-container">
                <input type="text" id="searchInput" placeholder="Search employee" />
                <button onclick="search()">Search</button>
         </div>

        <?php
        require('dbconnect.php');
        $conn = new mysqli($localhost, $user, $password, $dbname);

        $tbname = "employees";
        $sql = "SELECT `EmployeeID`,`FirstName`,`LastName`,`BirthDate`,`Notes` FROM $tbname;"; //echo $sql;
        $result = $conn->query($sql);

        if($result && $result->num_rows > 0) {
            echo '<table class="table table-striped">';
            echo '<thead class = "table-dark">';
            echo '<tr>';
            echo '<th>ID</th>';
            echo '<th>First Name</th>';
            echo '<th>Last Name</th>';
            echo '<th>DOB</th>';
            echo '<th>Notes</th>';
            echo '</tr>';
            echo '</thead>';
            echo '<tbody>';

            $x=1;
            while($row = $result->fetch_array()) {
                echo '<tr>';
                echo '<td>' . $row[0] . '</td>';
                echo '<td>' . $row[1] . '</td>';
                echo '<td>' . $row[2] . '</td>';
                echo '<td>' . $row[3] . '</td>';
                echo '<td>' . $row[4] . '</td>';
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
    <script>
        function search(){
            
        }
    </script>
</body>
</html>