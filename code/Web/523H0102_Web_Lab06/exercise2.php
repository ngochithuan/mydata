<?php
    $num1 = '';
    $num2 = '';
    $error = '';
    $op = '';
    $alert = 'success';
    if(empty($_POST['num1']) || empty($_POST['num2'])){
        $alert = 'danger';
        $error = 'Empty number(s)!';
    } else {
        $num1 = $_POST['num1'];
        $num2 = $_POST['num2'];
        $op = $_POST['op'];
        if(isset($op)){
            $error = 'Choose a operation';
            $alert = 'danger';
        }
        $alert = 'success';
    }

?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

    <title>Exercise 2.</title>
</head>
<body>
    <div class="container">

        <div class="row">
            <div class="col-md-6 my-5 mx-auto border rounded px-3 py-3">
                <h4 class="text-center">Tính toán cơ bản</h4>
                <form method="post">
                    <div class="form-group">
                        <label for="num1">Số hạng 1</label>
                        <input value="<?= $num1?>" name="num1" type="text" class="form-control" id="num1">
                    </div>
                    <div class="form-group">
                        <label for="num2">Số hạng 2</label>
                        <input value="<?= $num2?>" name="num2" type="text" class="form-control" id="num2">
                    </div>
                    <div class="form-group">
                        <div class="custom-control custom-radio custom-control-inline">
                            <input name="op" value="add" id="add" type="radio" class="custom-control-input" <?php if (isset($op) && $op=="add") echo "checked";?>>
                            <label for="add" class="custom-control-label">Cộng</label>
                        </div>
                        <div class="custom-control custom-radio custom-control-inline">
                            <input name="op" value="subtract" id="subtract" type="radio" class="custom-control-input" <?php if (isset($op) && $op=="subtract") echo "checked";?>>
                            <label for="subtract" class="custom-control-label">Trừ</label>
                        </div>
                        <div class="custom-control custom-radio custom-control-inline">
                            <input name="op" value="multiply" id="multiply" type="radio" class="custom-control-input" <?php if (isset($op) && $op=="multiply") echo "checked";?>>
                            <label for="multiply" class="custom-control-label">Nhân</label>
                        </div>
                        <div class="custom-control custom-radio custom-control-inline">
                            <input name="op" value="divide" id="divide" type="radio" class="custom-control-input" <?php if (isset($op) && $op=="divide") echo "checked";?>>
                            <label for="divide" class="custom-control-label">Chia</label>
                        </div>
                    </div>
                    <button class="btn btn-success">Xem kết quả</button>
                </form>
            </div>
        </div>
        <div class="row">
            <div class="col-md-6 mx-auto px-3 py-3 text-center">
                <div class="alert alert-<?= $alert ?>"><?php echo $error;?></div>
            </div>
        </div>
    </div>
</body>
</html>