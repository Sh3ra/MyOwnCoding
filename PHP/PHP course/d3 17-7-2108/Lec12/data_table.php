<?php
    $students = [
        "ahmed" => [90,80,50,50,60],
        "sara" => [100,60,80,20,30],
        "dina" => [80,50,99],
        "mona" => [95,60,80],
        "ali" => [88,67,89],
    ];
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Student Data</title>
    <style>
        table,th,tr , td{
            border-color: blueviolet;
            background-color: aquamarine;
            border-collapse: collapse;
            border-width: 4px;
            border-style: groove;
        }
        table{
            width: 50%;
            align-content: center;
        }
    </style>
</head>
<body>
    <table align="center">
        <tr>
            <th>Name</th>
            <th>Math</th>
            <th>English</th>
            <th>Arabic</th>
        </tr>
        <?php
            foreach ($students as $name=>$degrees)
            {
                echo "<tr>";
                echo "<td>$name</td>";
              /*  echo "<td>$degrees[0]</td>";
                echo "<td>$degrees[1]</td>";
                echo "<td>$degrees[2]</td>";
              */
              for($i = 0 ; $i<count($degrees);$i++)   echo "<td>$degrees[$i]</td>";
                echo "</tr>";
            }
        ?>

    </table>
</body>
</html>