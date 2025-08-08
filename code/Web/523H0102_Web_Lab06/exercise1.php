<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercise 1</title>

    <style>
        table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
            text-align: center;
        }

        th {
            background-color: lightgray;
        }

        th, td {
            padding: 7px;
        }
    </style>
</head>
<body>
    <table class="table table-bordered">
  <thead>
    <tr>
      <th colspan="10">BẢNG CỬU CHƯƠNG</th>
    </tr>
  </thead>
  <tbody>
    <?php
    for ($i = 1; $i <= 10; $i++){
    ?>
    <tr>
        <?php 
        for ($j = 1; $j <= 10; $j++){
        ?>
            <td><?php
                $r = $j * $i;
                echo "$j x $i = $r";
            ?></td>
        <?php 
        }
        ?>
    </tr>
    <?php
    }
    ?>
  </tbody>
</table>
</body>
</html>