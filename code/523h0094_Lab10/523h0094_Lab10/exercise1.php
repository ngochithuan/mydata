<?php
session_start();
if (isset($_SESSION['error'])) {
    $error = $_SESSION['error'];
    unset($_SESSION['error']);
} else {
    $error = null;
}

if (isset($_SESSION['success'])) {
    $success = $_SESSION['success'];
    unset($_SESSION['success']);
} else {
    $success = null;
}
?>

<!doctype html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport"
        content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>exercise 1</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</head>

<body>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col col-md-6 card mt-5 p-3">
                <h3 class="text-center">Upload File</h3>
                <form enctype="multipart/form-data" method="post" action="upload.php">

                    <div class="form-group">
                        <label for="name">File Name</label>
                        <input name="fileName" id="name" type="text" class="form-control" >
                    </div>
                    <div class="form-group">
                        <div class="custom-file">
                            <input name="myFile" type="file" class="custom-file-input" id="myFile" >
                            <label class="custom-file-label" for="document">Choose file</label>
                        </div>
                    </div>
                    <div class="form-group">
                        <button class="btn btn-primary ">Upload</button>
                    </div>
                    <div class="form-group">
                        <?php 
                        if ($error) {
                            echo '<div class="alert alert-danger">' . htmlspecialchars($error) . '</div>';
                        }
                        if ($success) {
                            echo '<div class="alert alert-success">' . htmlspecialchars($success) . '</div>';
                        }
                        ?>
                    </div>
                </form>
            </div>
        </div>
    </div>
    <script>
        $(".custom-file-input").on("change", function () {
            var fileName = $(this).val().split("\\").pop();
            $(this).siblings(".custom-file-label").addClass("selected").html(fileName);
        });

        document.querySelector('#myFile').addEventListener('change', (e) => {
    if (e.target.files.length > 0) {
        let myFile = e.target.files[0]; 

        const fileName = myFile.name;
        const fileSize = myFile.size;
        const fileExtension = fileName.split('.').pop().toLowerCase();

        const maxSize = (500 * 1024 ) * 1024; 
        if (fileSize > maxSize) {
            alert('File size must be <2MB');
            e.target.value = ''; 
            return;
        }

        alert('File is valid. You can proceed with the upload.');
    }
});
    </script>
</body>

</html>